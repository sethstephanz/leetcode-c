/*

3931. Check Adjacent Digit Differences
https://leetcode.com/problems/check-adjacent-digit-differences/description/

Return true if absolute value between any adjacent pair of digits in a digit string > 2. Else, false

pattern: simulation, ~two-pointer

optimization: if string is guaranteed to be valid, 
use while not null terminator in loops instead of finding strlen directly to save O(n) operation 
*/

bool isAdjacentDiffAtMostTwo(char* s) {
    for (int i = 1; s[i] != '\0'; i++) {
        if (abs(s[i-1] - s[i]) > 2) {
            return false;
        }
    }
    return true;
}
