/* private.c
 * ... illustrates why private variables are needed with OpenMP's parallel for loop
 *
 * Joel Adams, Calvin College, November 2009.
 *
 * Usage: ./private 
 *
 * TODO: Experiment with how to parallelize properly so that array indices are
 * private to each thread rather than shared (where threads will interfere with
 * each other)
 */

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 100

int main(int argc, char** argv) {
    int i, j, ok = 1;
    int m[SIZE][SIZE];

    printf("\n");
    // set all array entries to 1
//    #pragma omp parallel for                     // A
//    #pragma omp parallel for private(i,j)        // B
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m[i][j] = 1;
        }
    }

    // test (without using threads)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if ( m[i][j] != 1 ) {
                printf("Element [%d,%d] not set... \n", i, j);
                ok = 0;
            }
        }
    }

    if ( ok ) {
        printf("\nAll elements correctly set to 1\n\n");
    }

    return 0;
}

