#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 1752. Check if Array Is Sorted and Rotated
 * https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23
 *
 * pattern: logic, counting
 *
 * explanation: 
 * naive solution: iterate through each element in array, seeing if array built from that starting point is valid. O(n ** 2) time, O(1) space.
 * optimized naive: find minimum values in array. repeat naive solution over those minima. ~O(n ** 2) time, O(n) space
 * optimal solution: find the number of pivots, or positions that could serve as starting points
 *      of a valid array, given by strict decrease in value from one element, i, to another element, (i+1) % len(arr). 
 *      if there's more than one pivot, then it's impossible to have a valid array. otherwise, there's a valid array. O(n) time, O(1) space
 * */

bool check(int *nums, int numsSize) {
    int pivot_found = false;

    if (nums[0] < nums[numsSize - 1]) {
        pivot_found = true;
    }

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            if (pivot_found == true) {
                return false;
            } else {
                pivot_found = true;
            }
        }
    }

    return true;
}
