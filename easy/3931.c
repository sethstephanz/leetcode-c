/*

3931. Check Adjacent Digit Differences
https://leetcode.com/problems/check-adjacent-digit-differences/description/

Return true if absolute value between any adjacent pair of digits in a digit string > 2. Else, false

pattern: simulation, ~two-pointer
*/

bool isAdjacentDiffAtMostTwo(char* s) {
    int s_len = strlen(s);
    for (int i = 1; i < s_len; i++) {
        if (abs(s[i-1] - s[i]) > 2) {
            return false;
        }
    }
    return true;
}
