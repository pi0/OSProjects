#include <iostream>
#include <sys/unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

using namespace std;

#define NUM_OF_CLIENTS 100
#define MAX_MEMBERS 200
#define SLEEP 1000

#define mmap_alloc(t) (t*)mmap(NULL, sizeof(t*), PROT_READ | PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, -1, 0);

bool add_member();

void *client(void *);

int *members_count;

int main(int argc, int **argv) {

    members_count=mmap_alloc(int);
    *members_count=NUM_OF_CLIENTS;

    for(int i=0;i<NUM_OF_CLIENTS;i++)
        if(fork()==0){
            client(NULL);
            exit(0);
        }

    usleep(SLEEP*5);

    cout<<"Members: "<<*members_count;
    if(*members_count>MAX_MEMBERS)
        cout<<" ... and we have " << (*members_count)-MAX_MEMBERS << " Extra memebrs!";
    cin.get();
    return 0;
}

void *client(void* ptr) {
    while (add_member());
    pthread_mutex_unlock((pthread_mutex_t *) ptr);
}

bool add_member() {
    // Check if we have enough space
    if (*members_count >= MAX_MEMBERS)
        return false;
    // Simulate Connecting to master server delay
    usleep(SLEEP);
    // Commit changes
    (*members_count)++;
    // Return OK
    return true;
}
