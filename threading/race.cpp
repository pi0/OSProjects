#include <iostream>
#include <sys/unistd.h>

using namespace std;

#define NUM_OF_CLIENTS 100

bool add_member();

void *adder_t(void *);

int members_count = 0;

int main(int argc, int **argv) {
    for (int i = 0; i < NUM_OF_CLIENTS; i++)
        pthread_create(threads + i, NULL, adder_t,thread_locks+i);
    for (int i = 0; i < NUM_OF_THREADS; i++)
        pthread_mutex_lock(thread_locks+i);
    cout<<"Members:"<<members_count;
    return 0;
}

void *adder_t(void* ptr) {
    while (add_member());
    pthread_mutex_unlock((pthread_mutex_t *) ptr);
}

bool add_member() {
    // Check if we have enough space
    if (members_count >= NUM_OF_THREADS)
        return false;
    // Simulate Connecting to master server delay
    usleep(1000);
    // Commit changes
    members_count++;
    // Return OK
    return true;
}
