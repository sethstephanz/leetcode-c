#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

// Dynamic array that doubles in size if more elements are added.

DynamicArray *create_arr(int initial_capacity) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (!arr) {
        fprintf(stderr, "create_arr: Failed to allocate memory for array\n");
        exit(EXIT_FAILURE);
    }

    arr->data = (int *)malloc(initial_capacity * sizeof(int)); // this cast is unecessary in C, but is in C++
    if (!arr->data) {
        fprintf(stderr, "create_arr: Failed to allocate memory for data\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    arr->size = 0;
    arr->capacity = initial_capacity;
    for (int x = 0; x < arr->capacity; x++) {
        arr->data[x] = 0;
    }
    return arr;
}

int resize_arr(DynamicArray *arr) {
    arr->capacity *= 2;
    arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    if (!arr->data) {
        fprintf(stderr, "resize_arr: Failed to reallocate memory for data\n");
        return -1;
    }
    return 0;
}

void free_arr(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

void print_arr(DynamicArray *arr) {
    printf("Array (size: %d, capacity: %d): ", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void append(DynamicArray *arr, int val) {
    if (arr->size >= arr->capacity) {
        if (resize_arr(arr) < 0) {
            printf("append: error resizing array. Could not append new value.");
            return;
        }
    }

    // add element and increase size
    arr->data[arr->size++] = val;
}

void insert(DynamicArray *arr, int val, int idx) {
    if (idx < 0 || idx > arr->size) {
        printf("insert: Invalid index\n");
        return;
    }
    if (arr->size == arr->capacity) {
        if (resize_arr(arr) < 0) {
            fprintf(stderr, "insert: error resizing array. New value not inserted.\n");
            return;
        }
    }

    for (int i = arr->size; i > idx; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[idx] = val;
    arr->size++;
}

void delete(DynamicArray *arr, int idx) {
    if (idx >= 0 && idx <= arr->size) {
        for (int i = idx; i < arr->capacity - 1; i++) {
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
