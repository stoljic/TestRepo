/* utilitykit.c - A kit of tools for working with arrays */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM(min, max) (rand( ) % (max - min + 1) + min)

void allocate(int **ptr, int n) {

    (*ptr) = (int*) calloc(n, sizeof(int));
}

void deallocate (int *ptr) {

    free(ptr);
}

void generate (int *ptr, int n) {

    srand(time(0));

    for (int i = 0; i < n; ++i) {
        (*ptr++) = RANDOM(0, 100);
    }
}

void copy (int *source, int *dest, int n) {

    for (int i = 0; i < n; ++i) {
        (*dest++) = (*source++);
    }
}

void print (int *arr, int n) {

    printf("\n( ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", (*arr++));
    }
    printf(")\n");
}
