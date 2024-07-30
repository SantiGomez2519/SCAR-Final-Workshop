# Final Workshop Santiago Gómez Ospina

## Contents
- [Running](#running)
- [Used Methods](#used-methods)
- [Recommendations](#recommendations)
- [Authors](#authors)

## Running

1. Access APOLO.

2. At a terminal, run the following command:
    ```
    git clone https://github.com/SantiGomez2519/SCAR-Final-Workshop.git
    ```

3. Go to the directory where you cloned the project:
    ```
    cd Final-Workshop
    ```

4. Create a `bin` directory inside the root of the project:
    ```
    mkdir bin
    ```

5. Compile the `mmm_implementation.c` file inside the bin directory:
    ```
    gcc mmm_implementation.c -o bin/mmm -O3 -ftree-vectorize -fopenmp -mavx2
    ``` 

6. Run the program:
    ```
    sbatch job.sh
    ```

**NOTE:** by default, the program will create random arrays from `2x2` to `5000x5000`, and perform `50` tests. If you are going to run the program on your pc or perform tests in APOLO, we recommend that you change these parameters, for example:
```
#define N 10
#define MIN_SIZE 2
#define MAX_SIZE 1000
```
When you run the final test of the program, you should recover the original values:
```
#define N 50
#define MIN_SIZE 2
#define MAX_SIZE 5000
```

## Used Methods

To do the task I implement in the code concepts of parallelization and vectorization using the OpenMP API and using the flags of the GCC compiler: -03 -ftree-vectorize -mavx2 -fopenmp also optimizing the task of the matrix multiplication.

## Recommendations

Always run the `job.sh` script to test the `mmm_implementation.c`.

## Authors
- Santiago Gómez Ospina
- Juan Manuel Gómez
- Santiago Rodriguez
- Santiago Neusa