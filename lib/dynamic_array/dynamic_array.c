#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

// Dynamic array that doubles in size if more elements are added.

DynamicArray *create_array(int initial_length) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (!arr) {
        fprintf(stderr, "create_array: Failed to allocate memory for array\n");
        exit(EXIT_FAILURE);
    }

    arr->data = (int *)malloc(initial_length * sizeof(int)); // this cast is unecessary in C, but is in C++
    if (!arr->data) {
        fprintf(stderr, "create_array: Failed to allocate memory for data\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    arr->size = 0;
    arr->length = initial_length;
    return arr;
}

void resize_array(DynamicArray *arr) {
    arr->length *= 2;
    arr->data = (int *)realloc(arr->data, arr->length * sizeof(int));
    if (!arr->data) {
        fprintf(stderr, "resize_array: Failed to reallocate memory for data\n");
        exit(EXIT_FAILURE);
    }
}

void free_array(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

void print_array(DynamicArray *arr) {
    printf("Array (size: %d, length: %d): ", arr->size, arr->length);
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void append(DynamicArray *arr, int val) {
    if (arr->size >= arr->length) {
        resize_array(arr);
    }

    // add element and increase size
    arr->data[arr->size++] = val;
}

void insert(DynamicArray *arr, int val, int idx) {
    if (arr->size == arr->length) {
        resize_array(arr);
    }
    if (idx >= 0 && idx < arr->length) {
        // shift over elements from size of array + 1 to idx
        int i;
        for (i = arr->length; i > idx; i--) {
            arr->data[i] = arr->data[i - 1];
        }

        // insert el at idx
        arr->data[idx] = val;
        arr->size++;
    } else {
        printf("Insert: Invalid index\n");
    }
}

void delete(DynamicArray *arr, int idx) {
    if (idx >= 0 && idx <= arr->size) {
        for (int i = idx; i < arr->length - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    } else {
        printf("Delete: Invalid index\n");
    }
}

int search(DynamicArray *arr, int val) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == val) {
            return i;
        }
    }
    return -1;
}

int get(DynamicArray *arr, int idx) {
    if (idx >= 0 && idx <= arr->size) {
        return arr->data[idx];
    } else {
        printf("Get: Invalid index\n");
        return -1;
    }
}

void set(DynamicArray *arr, int idx, int val) {
    if (idx >= 0 && idx <= arr->size) {
        arr->data[idx] = val;
    } else {
        printf("Set: Invalid index\n");
    }
}

int avg(DynamicArray *arr, float *res) {
    if (arr->size == 0) {
        fprintf(stderr, "Avg: No elements in array\n");
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->data[i];
    }

    *res = (float)sum / arr->size;
    return 0;
}

int max(DynamicArray *arr, int *res) {
    if (arr->size == 0) {
        printf("Max: No elements in array\n");
        return -1;
    }

    int max = arr->data[0];
    for (int i = 1; i < arr->size; i++) {
        if (max < arr->data[i]) {
            max = arr->data[i];
        }
    }

    *res = max;
    return 0;
}

int min(DynamicArray *arr, int *res) {
    if (arr->size == 0) {
        printf("Min: No elements in array\n");
        return -1;
    }

    int min = arr->data[0];
    for (int i = 1; i < arr->size; i++) {
        if (min > arr->data[i]) {
            min = arr->data[i];
        }
    }

    *res = min;
    return 0;
}

int sum(DynamicArray *arr, int *res) {
    if (arr->size == 0) {
        printf("sum: No elements in array\n");
        return -1;
    }

    int sum = arr->data[0];
    for (int i = 1; i < arr->size; i++) {
        sum += arr->data[i];
    }

    *res = sum;
    return 0;
}

void reverse_arr(DynamicArray *arr) {
    int i = 0;
    int j = arr->size - 1;
    while (i < j) {
        int temp = arr->data[i];
        arr->data[i] = arr->data[j];
        arr->data[j] = temp;
        i++;
        j--;
    }
}

void shift_left(DynamicArray *arr) {
    // shift arr left. leftmost value will be lost. backfill with 0s
    if (!arr) {
        fprintf(stderr, "shift_left: No array\n");
        return;
    }
    for (int i = arr->size; i > -1; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = 0;
}

void rotate_left(DynamicArray *arr) {
    // rotate array left. backfill with leftmost value
    if (!arr) {
        fprintf(stderr, "rotate_left: No array\n");
        return;
    }
    int temp = arr->data[arr->size - 1];

    for (int i = arr->size; i > -1; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = temp;
}

void shift_right(DynamicArray *arr) {
    // shift arr right. rightmost value will be lost. backfill with 0s
    if (!arr) {
        fprintf(stderr, "shift_right: No array\n");
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->data[(arr->size) - 1] = 0;
}

void rotate_right(DynamicArray *arr) {
    if (!arr) {
        fprintf(stderr, "rotate_right: No array\n");
        return;
    }
    int temp = arr->data[0];
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->data[(arr->size) - 1] = temp;
}
