#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2553. Separate the Digits in an Array
// https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-12

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

int *separateDigits(int *nums, int numsSize, int *returnSize) {
    // store result
    int res_cap = 10;
    int *res = (int *)malloc(res_cap * sizeof(int)); // freed by external function (in driver, locally)
    memset(res, 0, res_cap * sizeof(res[0]));
    int res_size = 0;

    // store digits from each individual number
    int digits_cap = 10;
    int *digits = malloc(sizeof(int) * digits_cap);
    memset(digits, 0, digits_cap * sizeof(digits[0]));
    int d = 0; // pointer for copying to res

    for (int i = 0; i < numsSize; i++) {
        d = 0;

        // extracts digits backwards
        while (nums[i] > 0) {
            digits[d++] = nums[i] % 10;
            nums[i] = nums[i] / 10;
        }

        d--; // need to start at first/last digit. step back one
        while (d >= 0) {
            if (res_size == res_cap) {
                int new_cap = res_cap * 2;
                int *temp = realloc(res, new_cap * sizeof(int));
                if (temp == NULL) {
                    fprintf(stderr, "error: realloc\n");
                    exit(1);
                }
                res = temp;
                res_cap = new_cap;
            }
            res[res_size++] = digits[d--];
        }
        memset(digits, 0, digits_cap * sizeof(digits[0]));
    }

    *returnSize = res_size;

    free(digits);
    return res;
}
