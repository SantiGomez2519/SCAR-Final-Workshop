#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50
#define MIN_SIZE 2
#define MAX_SIZE 5000
#define MAX_NUM 10000000.0

int main(){
    srand((unsigned) time(NULL));
    int size = MIN_SIZE + (rand() % MAX_SIZE), iterator = 0;
    double A[size][size] __attribute__((aligned(64))), B[size][size] __attribute__((aligned(64))), C[size][size] __attribute__((aligned(64)));

    while(iterator++ < N){
        printf("Running iteration number: %d\n", iterator);

        // Start modifying here

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                A[j][i] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM; 
                B[j][i] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM; 
                C[j][i] = 0;
            }
        }
        
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                for(int i = 0; i < size; i++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // Stop modifying here
    }

    printf("Size of matrices: %d \n", size);

    return 0;
}