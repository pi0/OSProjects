#include <stdio.h>
#include <semaphore.h>
#include <sys/unistd.h>
#include <stdarg.h>
#include <sys/mman.h>
#include <stdlib.h>

#define wait(m) sem_wait(m)
#define signal(m) sem_post(m)

#define mmap_alloc(t) (t*)mmap(NULL, sizeof(t*), PROT_READ | PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, -1, 0);

#define READERS 2
#define MAX 5

int printf_safe(const char *format, ...);

void *reader(void *);

void *writer(void *);

sem_t *printf_mutex, *r_mutex, *rw_mutex;
int *value_ptr, *reader_counter_ptr;

#define RUNNING (*value_ptr)<MAX

int main(int argc, char **argv) {

    // init shared memory
    value_ptr = mmap_alloc(int);
    *value_ptr = 0;
    reader_counter_ptr = mmap_alloc(int);
    *reader_counter_ptr = 0;
    printf_mutex = mmap_alloc(sem_t);
    rw_mutex = mmap_alloc(sem_t);
    r_mutex = mmap_alloc(sem_t);

    // init semaphores
    sem_init(printf_mutex, 1, 1);
    sem_init(rw_mutex, 1, 1);
    sem_init(r_mutex, 1, 1);

    // Start writer and readers
    for (int i = 0; i < READERS + 1; i++)
        if (fork() == 0) {
            if (i == 0)
                writer(NULL);
            else
                reader(NULL);
            exit(0);
        }

    getchar();
    exit(0);
}


void *reader(void *) {
    int pid = getpid();

    while (RUNNING) {
        usleep(5000);

        wait(r_mutex);
        {
            (*reader_counter_ptr)++; // another reader
            if ((*reader_counter_ptr) == READERS - 1) {
                wait(rw_mutex);// block writer(s)
                printf_safe("readers acquire the lock\n");
            }
        }
        signal(r_mutex);

        printf_safe("the reader (%d) reads the value %d\n", pid, (*value_ptr));

        wait(r_mutex);
        {
            (*reader_counter_ptr)--;// reader done
            if ((*reader_counter_ptr) == 0) {
                printf_safe("readers release the lock\n");
                signal(rw_mutex);// enable writer(s)
            }
        }
        signal(r_mutex);
    }
}

void *writer(void *) {
    int pid = getpid();

    while (RUNNING) {
        wait(rw_mutex);
        {
            printf_safe("writer acquires the lock\n");
            usleep(5000);
            printf_safe("the writer (%d) writes the value %d\n", pid, ++(*value_ptr));
            printf_safe("writer releases the lock\n");
        }
        signal(rw_mutex);
    }
}

int printf_safe(const char *format, ...) {
    wait(printf_mutex);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    signal(printf_mutex);
}

