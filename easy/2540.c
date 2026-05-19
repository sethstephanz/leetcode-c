// 2540. Minimum Common Value
// https://leetcode.com/problems/minimum-common-value/submissions/2006828218/?envType=daily-question&envId=2026-05-19

// Given two int arrays sorted in descending order, find smallest value common to both.
// If none exist, return -1.

// pattern: two-pointer

int getCommon(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int n1 = 0;
    int n2 = 0;

    while (n1 < nums1Size && n2 < nums2Size) {
        if (nums1[n1] == nums2[n2]) {
            return nums1[n1];
        } else if (nums1[n1] > nums2[n2]) {
            n2++;
        } else if (nums1[n1] < nums2[n2]) {
            n1++;
        }
    }
    return -1;
}
