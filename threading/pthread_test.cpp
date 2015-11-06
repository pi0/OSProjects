#include <pthread.h>
#include <iostream>
#include <time.h>
#include <sys/unistd.h>


using namespace std;

void *hello_pthread(void* ptr);

void *producer(void* ptr);
void *consumer(void* ptr);

int main() {

//    pthread_t pthread_t1;
//    int id =  pthread_create(&pthread_t1,NULL,hello_pthread,NULL);
//    cout<<id;

    pthread_t producer_t,cosumer_t;
    pthread_create(&producer_t,NULL,producer,NULL);
    pthread_create(&cosumer_t,NULL,consumer,NULL);

    cin.get();

}

void *hello_pthread(void* ptr) {
    cout<<pthread_self();
}


pthread_mutex_t imutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t icond = PTHREAD_COND_INITIALIZER;

int avail;

void *consumer(void* ptr) {

    while(true){

        pthread_mutex_lock(&imutex);

        pthread_cond_wait(&icond,&imutex);

        cout<<"Consuming.num of available:"<<avail--<<endl;

        pthread_mutex_unlock(&imutex);

    }
}



void *producer(void* ptr) {


    while (true) {

        pthread_mutex_lock(&imutex);

        if(avail>=3)
            pthread_cond_signal(&icond);
        else {
            cout << "Producing.num of available:" << avail++ << endl;
            usleep(500000);
        }

        pthread_mutex_unlock(&imutex);

    }

}