/*
    Sorting comparison

    This program runs multiple sorting algorithms in succession and measures the
    running time of each method. The same test vector is used for each algorithm.

    Sorting algorithms:
        - Quick sort
        - Bubble sort
        - Merge sort

    Input sizes: 10, 100, 1000, 10000, 100000, 1000000
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "quicksort/quicksort.h"
#include "bublesort/bublesort.h"
#include "mergesort/mergesort.h"
#include "utilitykit/utilitykit.h"

#define ARR_LEN_1   10
#define ARR_LEN_2   100
#define ARR_LEN_3   1000
#define ARR_LEN_4   10000
#define ARR_LEN_5   100000
#define ARR_LEN_6   1000000

typedef void (*fun_ptr) (int*, int len);

static double measure_time (fun_ptr sort, int *ptr, int len);
static void quick_test (int len);

int main () {

    quick_test(ARR_LEN_1);
    quick_test(ARR_LEN_2);
    quick_test(ARR_LEN_3);
    quick_test(ARR_LEN_4);
    quick_test(ARR_LEN_5);
    quick_test(ARR_LEN_6);

    return 0;
}

static double measure_time (fun_ptr sort, int *ptr, int len) {

    struct timeval begin, end;
    long seconds, microseconds;
    double elapsed;

    // Start measuring time
    gettimeofday(&begin, NULL);

    // Execute sorting algorithm
    sort(ptr, len);

    // Calculate elapsed time
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds * 1e-6;

    return elapsed;
}

static void quick_test (int len) {

    int *ptr;
    double time;

    // Allocate memory and generate elements
    allocate(&ptr, len);
    generate(ptr, len);

    // Sort the array, measure the time and free the memory
    time = measure_time(&quick_sort, ptr, len);
    printf("Time spent: %.6f\n", time);
    deallocate(ptr);
}
