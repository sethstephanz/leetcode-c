#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct
{
    int *data;
    int size;     // number of places in memory in array
    int capacity; // number of elements in the array
} DynamicArray;

// init & utility functions
DynamicArray *create_arr(int initial_length); // initialize dynamic array
void free_arr(DynamicArray *arr);             // free memory allocated for array
void print_arr(DynamicArray *arr);            // print contents from array
int resize_arr(DynamicArray *arr);            // doubles size of array if run out of room

// methods
void append(DynamicArray *arr, int val);          // append element to dynamic array
void insert(DynamicArray *arr, int val, int idx); // insert element at index
void delete(DynamicArray *arr, int idx);          // delete element by index
int search(DynamicArray *arr, int val);           // search for element. returns first index found
int get(DynamicArray *arr, int idx);              // return value of element at index
void set(DynamicArray *arr, int idx, int val);    // replace value of element at index with provided value
int avg(DynamicArray *arr, float *res);           // return average of values in array
int max(DynamicArray *arr, int *res);             // return maximum value in array
int min(DynamicArray *arr, int *res);             // return minimum value in array
int sum(DynamicArray *arr, int *res);             // return sum of values in array
void reverse_arr(DynamicArray *arr);              // reverse array
void shift_left(DynamicArray *arr);               // shift elements in array left (leftmost will be lost)
void rotate_left(DynamicArray *arr);              // shift elements in array left (leftmost inserted at end)
void shift_right(DynamicArray *arr);              // shift elements right (rightmost will be lost)
void rotate_right(DynamicArray *arr);             // shift elements in array right (right inserted at end)

#endif // DYNAMIC_ARRAY_H
