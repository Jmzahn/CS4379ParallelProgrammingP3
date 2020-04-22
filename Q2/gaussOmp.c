/*
    Written by Jacob Zahn for CS4379
*/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/time.h>

/* Program Parameters */
#define MAXN 2000 //max matrix size
int N, numP;//matrix size and numper of processsors

/* Matrices and vectors */
volatile double A[MAXN][MAXN], B[MAXN], X[MAXN];

int getMaxThreads();

void initialize_inputs(){
    int row, col;
    printf("\nInitializing...\n");
    for (col = 0; col < N; col++) {
        for (row = 0; row < N; row++) {
            A[row][col] = (float)rand() / 32768.0;
        }
        B[col] = (float)rand() / 32768.0;
        X[col] = 0.0;
    }
}

void print_inputs(){
    int row, col;
    if (N <= 10) {
        printf("\nA =\n\t");
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
	            printf("%5.2f%s", A[row][col], (col < N-1) ? ", " : ";\n\t");
            }
        }
        printf("\nB =\n\t");
        for (row = 0; row < N; row++) {
            printf("%5.2f%s", B[row], ";\n\t");
        }
    }
}

void print_outputs(){
    int row, col;
    if (N <= 10) {
        printf("\nX =\n\t");
        for (row = 0; row < N; row++) {
            printf("%5.2f%s", X[row], ";\n\t");
        }
    }
}

int main(int argc, char *argv[]){
    /* Timing variables */
    struct timeval etstart, etstop;  /* Elapsed times using gettimeofday() */
    clock_t etstart2, etstop2;  /* Elapsed times using times() */
    unsigned long long usecstart, usecstop;
    struct tms cputstart, cputstop;  /* CPU times for my processes */

    srand(time(NULL));  /* Randomize */

    //read args, as MMproduct N P
    if(argc != 3){
        return(-1);
    }
    else{
        char *p, *n;
        long convn = strtol(argv[1], &n, 10);
        long convp = strtol(argv[2], &p, 10);
        numP = convp;
        N = convn;
        if (N > MAXN){
            N = MAXN;
        }
        if (numP > getMaxThreads()){
            numP = getMaxThreads();
        }
    }
    /* Print parameters */
    printf("\nMatrix dimension N = %i.\n", N);
    printf("Number of threads = %i.\n", numP);
    /* Initialize A, B and X*/
    initialize_inputs();
    /* Print input matrices */
    print_inputs();

    /* Start Clock */
    printf("\nStarting clock.\n");
    gettimeofday(&etstart, NULL);
    etstart2 = times(&cputstart);
    
    int row, col, k;
    float multiplier;
    // gaussian elimination
    #pragma omp parallel shared(A, B, X) private(row, col, k, multiplier) num_threads(numP)
    #pragma omp for schedule (dynamic)
    for (k = 0; k < N - 1; k++) {
        for (row = k + 1; row < N; row++) {
            multiplier = A[row][k] / A[k][k];
            for (col = k; col < N; col++) {
	            A[row][col] -= A[k][col] * multiplier;
            }
            B[row] -= B[k] * multiplier;
        }
    }
    //back  substitution
    for (row = N - 1; row >= 0; row--) {
        X[row] = B[row];
        for (col = N-1; col > row; col--) {
            X[row] -= A[row][col] * X[col];
        }
        X[row] /= A[row][row];
    }

    /* Stop Clock */
    gettimeofday(&etstop, NULL);
    etstop2 = times(&cputstop);
    printf("Stopped clock.\n");
    usecstart = (unsigned long long)etstart.tv_sec * 1000000 + etstart.tv_usec;
    usecstop = (unsigned long long)etstop.tv_sec * 1000000 + etstop.tv_usec;

    //print outputs
    print_outputs();
    /* Display timing results */
    printf("\nElapsed time = %g ms.\n",
	 (float)(usecstop - usecstart)/(float)1000);
    printf("(CPU times are accurate to the nearest %g ms)\n",
	 1.0/(float)CLOCKS_PER_SEC * 1000.0);
    printf("My total CPU time for parent = %g ms.\n",
	 (float)( (cputstop.tms_utime + cputstop.tms_stime) -
	  (cputstart.tms_utime + cputstart.tms_stime) ) /
	 (float)CLOCKS_PER_SEC * 1000);
    printf("My system CPU time for parent = %g ms.\n",
	 (float)(cputstop.tms_stime - cputstart.tms_stime) /
	 (float)CLOCKS_PER_SEC * 1000);
    printf("My total CPU time for child processes = %g ms.\n",
	 (float)( (cputstop.tms_cutime + cputstop.tms_cstime) -
	  (cputstart.tms_cutime + cputstart.tms_cstime) ) /
	 (float)CLOCKS_PER_SEC * 1000);
      /* Contrary to the man pages, this appears not to include the parent */
    printf("--------------------------------------------\n");

    return 0;
}

int getMaxThreads(){
    return omp_get_max_threads();
}
