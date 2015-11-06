#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <sys/time.h>

using namespace std;

#define irand(seed, len, base) rand_r(seed)*(double)len/RAND_MAX-base

static double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

int main(int argc, char **args) {

    // cmd args
    int count = 1000000; // Try Count
    int threads = 16; // Num of parallel threads
    if (argc > 1) {
        count = atoi(args[1]);
        if (argc > 2) {
            threads = atoi(args[2]);
        }
    }
    cerr << "Estimating value of pi with " << count << " Test cases running on " << threads << " Threads ... \n";
    cerr << "Host CPU has " << omp_get_num_procs() << " Cores\n";

    // Initialize seeds
    unsigned int *seeds = new unsigned int[threads];
    srand((unsigned int) time(NULL)); // Base Seeds Are based On Host Time
    for (int i = 0; i < threads; i++)
        seeds[i] = (unsigned int) ((i + 1) * rand());

    // Variables
    unsigned int *thread_seed; // Private Thread ID
    double x, y; // Random X,Y
    int circle_hit = 0; // Circle Hits counter, reducted

    // RUN_TIME
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Fastest Threads ever :))
	#pragma omp parallel for private(thread_seed,x,y) reduction(+:circle_hit) num_threads(threads)
    for (unsigned int i = 0; i < count; i++) {
        thread_seed = seeds + omp_get_thread_num();
        x = irand(thread_seed, 2, 1);
        y = irand(thread_seed, 2, 1);
        if (x * x + y * y < 1)
            circle_hit++;
    }

    // RUN_TIME
    gettimeofday(&end, NULL);
    long elapsed = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);

    // Show Result
    double pi = (4.0 * circle_hit) / count;
    double err= fabs(pi - PI);
    cerr << "PI ~ " << pi << endl;
    cerr << "Error: "<<err<<endl;
    cerr << "Elapsed: " << elapsed << " us" <<endl;

    cout << count << "," << threads << "," << (int)(100000000*err) << "," << elapsed<<endl;

    return 0;
}