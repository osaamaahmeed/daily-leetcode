// LeetCode #944 - Delete Columns to Make Sorted
// Date Solved: 2025-12-20
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    int ans = 0;
    for (int i = 0; i < strs[0].size(); i++) {
        for (int j = 1; j < strs.size(); j++) {
            if (int(strs[j-1][i]) > int(strs[j][i])) {
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main () {
    vector<string>strs = {"cba","daf","ghi"};
    cout << minDeletionSize(strs);
}
