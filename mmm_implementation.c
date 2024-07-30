#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//OpenMP to parallelize and vectorize the loops
#include <omp.h>

//To compile gcc mmm_implementation.c -o bin/mmm -O3 -ftree-vectorize -fopenmp -mavx2 -fopt-info-vec-optimized

//Original N 50 and MAX_SIZE 5000
#define N 50
#define MIN_SIZE 2
#define MAX_SIZE 5000
#define MAX_NUM 10000000.0

int main(){

    srand((unsigned) time(NULL));
    int size = MIN_SIZE + (rand() % MAX_SIZE), iterator = 0;
    double time_spent = 0.0;
    double A[size][size] __attribute__((aligned(64))), B[size][size] __attribute__((aligned(64))), C[size][size] __attribute__((aligned(64)));

    while(iterator++ < N){
        printf("Running iteration number: %d\n", iterator);

        clock_t begin_time = clock();
        
        // Start modifying here
        
        //Parallelize the loops with OpenMP
        #pragma omp critical
        {
            //Vectorize the loops with Single Instruction Multiple Data (SIMD)
            #pragma omp simd
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    A[i][j] = rand();
                    B[i][j] = rand(); 
                    C[i][j] = 0;
                }
            }
        
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++){
                    for(int i = 0; i < size; i++){
                        C[j][i] += A[j][k] * B[k][i];
                    }
                }
            }
        }


        // Stop modifying here
        
        clock_t end_time = clock();
        time_spent += (double)(end_time - begin_time) / CLOCKS_PER_SEC;
    }

    printf("Size of matrices: %d \n", size);
    printf("Running time: %f \n", (time_spent / N));

    return 0;
}