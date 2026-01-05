// LeetCode #1975 - Maximum Matrix Sum
// Date Solved: 2026-01-05
// Difficulty: Medium


/* Problem Summary:
- We have an N*N matrix 
- We can multiply 2 adjacent (share the same border)  elements by -1
- We want to calculate the max sum of the matrix items
*/

/* Approach: 
I calculate how many negative values in the matrix if there are:
- Even number of negative values then all the negative values will become postive
- Odd number of negative values then only 1 value will still be negative
    and we can keep multiplying by -1 until that 1 value becomes the smallest

Complexity:
Time: O(n*n)
Space: O(1)
*/

// Notes: I don't think we can optimize it more, also I had to submit twice to handle the smallest negative value and the zero case

#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int negt = 0;
    int minVal = INT_MAX;
    long long ans = 0;
    for (auto &i : matrix) {
        for (auto &j : i) {
            minVal = min(minVal, abs(j));
            ans += abs(j);
            if (j <= 0) negt++;
        }
    }
    if (negt % 2 == 1) {
        ans -= (minVal * 2);
    }
    return ans;   
}

int main() {
    vector<vector<int>>input = { {1,2,3}, {-1,-2,-3}, {1,2,3} };
    cout << maxMatrixSum(input);
    return 0;
}
