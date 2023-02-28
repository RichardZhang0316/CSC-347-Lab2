/**
 * This program implements a serial code via a function call that does a matrix multiplication and prints out the
 * execution time and the product of the two matrices with each element printed out to a file called “product.dat” 
 * in a tab-delimited, row/column format.
 *
 * Users are expected to enter three arguments: the executable file, the output file (which is product.dat), and
 * the width of the square matrics.
 *
 * @author Richard Zhang {zhank20@wfu.edu}
 * @date Feb.25, 2023
 * @assignment Lab 2
 * @course CSC 347
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function declaration */
void matrixMult (int width, float** a, float** b, float** c);

int main(int argc, char *argv[])
{
    int width = 0;
    srand(time(NULL)); /* seed the random number generator */
    clock_t start, end; /* measure the starting time and the ending time to calculate the time spent */
    
    /* determine if there are three arguments on the command line */
    if (argc < 3) {
        printf("Command line arguments are not enough: %s \n", argv[0]);
        return 1;
    }

    /* determine if the matrix width entered by users is legitamate */
    if (atoi(argv[2]) <= 0) {
        printf("The matrix width should not less than 1: %s \n", argv[2]);
        return 2;
    }

    /* initiate the three arrays: a and b are the input arrays, and c is the output array */
    width = atoi(argv[2]);
    float **a = (float **)malloc(width * sizeof(float *));
    float **b = (float **)malloc(width * sizeof(float *));
    float **c = (float **)malloc(width * sizeof(float *));
    for (int i = 0; i < width; i++) {
        a[i] = (float *)malloc(width * sizeof(float));
        b[i] = (float *)malloc(width * sizeof(float));
        c[i] = (float *)malloc(width * sizeof(float));
    }

    /* assign random float numbers to the two input arrays */
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < width; j++) {
        /* generate random numbers between 0 and 10.0 */
         a[i][j] = (float)rand() / RAND_MAX * 10.0;
         b[i][j] = (float)rand() / RAND_MAX * 10.0;
      }
    }

    start = clock(); /* start the timer */
    matrixMult(width, a, b, c);
    end = clock(); /* end the timer */

     /* output the execution time of the function to the terminal */
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total execution time: %f seconds\n", total_time);

    /* move the output content to the output file, which is "product.dat" */
    freopen(argv[1], "w", stdout);

    /* print the output array, which is the array c */
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            printf("%f\t", c[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < width; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
}

void matrixMult (int width, float** a, float** b, float** c) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            float sum = 0.0;
            for (int k = 0; k < width; k++) {
                float m = a[i][k];
                float n = b[k][j];
                sum += m * n;
            }
            c[i][j] = sum;
        }
    }
}