#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <immintrin.h>


//Original N 50 and MAX_SIZE 5000
#define N 10
#define MIN_SIZE 2
#define MAX_SIZE 1000
#define MAX_NUM 10000000.0

int main(){
    // Estimado Wambi, la única modificación que voy a hacer acá es agregar el set de los hilos <3 
    omp_set_num_threads(4);

    srand((unsigned) time(NULL));
    // int size = MIN_SIZE + (rand() % MAX_SIZE), iterator = 0;
    int size = 500, iterator = 0;
    double time_spent = 0.0;
    double A[size][size] __attribute__((aligned(64))), B[size][size] __attribute__((aligned(64))), C[size][size] __attribute__((aligned(64)));

    while(iterator++ < N){
        printf("Running iteration number: %d\n", iterator);

        clock_t begin_time = clock();
        
        // Start modifying here

        
        #pragma omp critical
        {
        #pragma omp simd
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                A[j][i] = rand();
                B[j][i] = rand(); 
                C[j][i] = 0;
            }
        }
    
        }

        #pragma omp critical
        {
        #pragma omp simd
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                for(int i = 0; i < size; i++){
                    C[i][j] += A[i][k] * B[k][j];
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