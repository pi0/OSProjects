#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

using namespace std;

int main(int argc, char **args) {

    int threads = 16; // Num of parallel threads

    if (argc != 4) {
        cerr << "Usage: " << args[0] << " x y z" << endl;
        return -1;
    }

    cout << "Running on " << threads << " Threads ... \n";
    cout << "Host CPU has " << omp_get_num_procs() << " Cores\n";


    // RUN_TIME
    struct timeval start, end;
    gettimeofday(&start, NULL);

    //
    int x = atoi(args[1]);
    int y = atoi(args[2]);
    int z = atoi(args[3]);

    int count = 0;

    omp_set_num_threads(6);
		omp_set_dynamic(0); 

    int i, j, k;

    int thread_tasks[8]={0};
    int thread_num;

#pragma omp parallel for reduction(+:count) collapse(3)  private(i,j,k,thread_num)
    for (i = 0; i < x; i++)
        for (j = 0; j < y; j++)
            for (k = 0; k < z; k++) {
                thread_num = omp_get_thread_num();
                #pragma omp critical
                {//Debug
                    cout << thread_num << ":" << i << "-" << j << "-" << k << endl;
                }
                thread_tasks[thread_num]++;
                count++;
            }


    // RUN_TIME
    gettimeofday(&end, NULL);
    long elapsed = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);

    // Show Result
    cout << "\nElapsed: " << elapsed << " us" << endl;

    cout << "Count: " << count<<endl;

    cout<<"Thread Balance: [";
    for(int i=0;i<6;i++)
        cout<<thread_tasks[i]/6.0<<",";
    cout<<"]"<<endl;

    return 0;
}