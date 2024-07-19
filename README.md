# Final Workshop

## Contents
- [Running](#running)
- [Recommendations](#recommendations)
- [Authors](#authors)

## Running

1. Access APOLO in the corresponding schedule.

2. At a terminal, run the following command:
    ```
    git clone https://github.com/SCAR-EAFIT/Final-Workshop
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
    gcc -o bin/mmm mmm_implementation.c
    ```

6. Run the program:
    ```
    sh job.sh
    ```

**NOTE:** by default, the program will create random arrays from `2x2` to `5000x5000`, and perform `50` tests. If you are going to run the program on your pc, we recommend that you change these parameters, for example:
```
#define N 10
#define MIN_SIZE 2
#define MAX_SIZE 1000
```
When running the program in APOLO, you should get back the original values:
```
#define N 50
#define MIN_SIZE 2
#define MAX_SIZE 5000
```

## Recommendations

When you open the `mmm_implementation.c` file, you will see some comments, indicating the starting point endpoint to modify.

Search for information on the Internet. Please do not rely on AI's, such as ChatGPT, Claude, or Gemini; you can use them for support, but they can also be wrong.

You have your own time to access APOLO, don't forget to respect these times, because other people also need access. Before you start testing in APOLO you should test and modify the code on your pc.

Create your own GitHub repository and clone it in APOLO, it will be easier for you.

Always run the `job.sh` script to test the `mmm_implementation.c`.

## Authors
- Juan Manuel Gómez
- Santiago Rodriguez
- Santiago Neusa