#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2784. Check if Array is Good
// https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14

typedef struct {
    char *data;
    size_t size;
    size_t cap;
} Str;

int print_int_array(int *arr, int arr_size) {
    if (arr_size == 0) {
        fprintf(stderr, "[]");
    }
    fprintf(stderr, "[");
    for (int i = 0; i < arr_size - 1; i++) {
        fprintf(stderr, "%d ", arr[i]);
    }
    fprintf(stderr, "%d]\n", arr[arr_size - 1]);
    return 0;
}

int comp(const void *a, const void *b) {
    // comp is passed to qsort as a function pointer later
    // but it needs this function signature, then just cast everything
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y) {
        return 1;
    } else if (x < y) {
        return -1;
    } else {
        return 0;
    }
}

bool isGood(int *nums, int numsSize) {
    // make sure sorted array includes all values 1-(n-1),
    // ensure the maximum value occurs exactly twice

    // array has to start with 1 and last two elements have to be maximum of array
    // so, [1, 1] is fine, but [9, 9] is invalid because does not include numbers up to 9
    // basically, [1, 1] is only two-element array that works

    if (numsSize < 2) {
        // array too small
        return false;
    }

    qsort(nums, numsSize, sizeof(nums[0]), comp);

    if (nums[0] != 1) {
        // can't include full sequence
        return false;
    }

    for (int i = 1; i < numsSize - 2; i++) {
        if (nums[i] != (nums[i - 1] + 1)) {
            return false;
        }
    }

    if (nums[numsSize - 2] != nums[numsSize - 1]) {
        return false;
    }

    return true;
}
