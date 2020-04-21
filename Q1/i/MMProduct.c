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


#define MAXN 2000
int N, numP;

volatile double A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];

int getMaxThreads();

void initialize_inputs(){
    int row, col;
    printf("\nInitializing...\n");
    for (col = 0; col < N; col++) {
        for (row = 0; row < N; row++) {
            A[row][col] = (float)rand() / 32768.0;
            B[row][col] = (float)rand() / 32768.0;
            C[row][col] = 0.0;
        }
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
            for (col = 0; col < N; col++) {
	            printf("%5.2f%s", B[row][col], (col < N-1) ? ", " : ";\n\t");
            }
        }
    }
}

void print_outputs(){
    int row, col;
    if (N <= 10) {
        printf("\nC =\n\t");
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
	            printf("%5.2f%s", C[row][col], (col < N-1) ? ", " : ";\n\t");
            }
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
    /* Initialize A, B and C*/
    initialize_inputs();
    /* Print input matrices */
    print_inputs();

    /* Start Clock */
    printf("\nStarting clock.\n");
    gettimeofday(&etstart, NULL);
    etstart2 = times(&cputstart);
    
    int row, col, k;
    // matrix multiplication
    #pragma omp parallel shared(A, B, C) private(row, col, k) num_threads(numP)
    for(row = 0; row < N; row++){
        for(col = 0; col < N; col++){
            #pragma omp for schedule (static)
            for(k = 0; k < N; k++){
                C[row][col] += A[row][k] * B[k][col];
            }
        }
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