#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2784. Check if Array is Good
// https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14

// qsort, callback practice (pointer decay applies to functions, too!). otherwise just condition checking

int comp(const void *a, const void *b) {
    // comp callback for qsort
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

    // array too small
    if (numsSize < 2) {
        return false;
    }

    qsort(nums, (size_t)numsSize, sizeof(nums[0]), comp); // sort array

    // can't include full sequence
    if (nums[0] != 1) {
        return false;
    }

    // [1, 1, 1], etc.
    if (numsSize > 2 && nums[0] == 1 && nums[numsSize - 1] == 1) {
        return false;
    }

    // check sequence
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] != (nums[i - 1] + 1)) {
            return false;
        }
    }

    // last and second-to-last elements don't match
    if (nums[numsSize - 2] != nums[numsSize - 1]) {
        return false;
    }

    return true;
}
