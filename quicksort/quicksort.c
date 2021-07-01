/* quicksort.c - Quick sort, a divide and conquer algorithm */

#include <stdio.h>

#include "../utilitykit/utilitykit.h"

static int partition (int *ptr, int l, int h);
static void algorithm (int *ptr, int l, int h);
static void swap (int* ptr, int n, int m);

void quick_sort (int *ptr, int len) {

    int l = 0;
    int h = len;

    algorithm(ptr, l, h);
}

static void algorithm (int* ptr, int l, int h) {

    int j;  // partitioning position

    // Check if there are 2 or more elements
    if (l < h) {
        j = partition(ptr, l, h);
        algorithm(ptr, l, j);
        algorithm(ptr, j + 1, h);
    }
}

static int partition (int *ptr, int l, int h) {

    int pivot = ptr[l];
    int i = l;
    int j = h;

    while (i < j) {
        do {
            ++i;
        } while (ptr[i] <= pivot);

        do {
            --j;
        } while (ptr[j] > pivot);

        if (i < j)
            swap(ptr, i, j);
    }

    // Partitioning position found
    swap(ptr, l, j);

    return j;
}

static void swap (int *ptr, int n, int m) {

    int temp;

    temp = ptr[n];
    ptr[n] = ptr[m];
    ptr[m] = temp;
}
