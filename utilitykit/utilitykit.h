/* utilitykit.h - A group of methods for working with arrays */

#ifndef _UTILITYKIT_H
#define _UTILITYKIT_H

// allocate - Used for dynamic memory allocation
void allocate(int **ptr, int n);

// deallocate - Used for releasing allocated memory
void deallocate(int *ptr);

// generate - Populates an array with n random elements
void generate (int *ptr, int n);

// print - Prints n elements of an array
void print (int *arr, int n);

// copy - Copies n elements from one array to another
void copy (int *source, int *dest, int n);

#endif /* _UTILITYKIT_H */
