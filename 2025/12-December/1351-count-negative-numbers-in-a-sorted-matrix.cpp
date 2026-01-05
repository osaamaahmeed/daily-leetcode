// LeetCode #1351 - Count Negative Numbers in a Sorted Matrix
// Date Solved: 2025-12-28
// Difficulty: Easy


/* Notes:

For This Problem I Coded 3 Solutions with 3 Different Time Complixty:

1. O(n*m):
the easiest and simplest which is to go throught the whole matrix and keep checking for negative numbers

2. O(n*log(m)):
which is using the fact that rows and columns are sorted so I used lower_bound on reverse iterators to find the first value that is equal to 0
then used that iterator to calculate the length remainning and kept using this on each row

3. O(n+m):
Using a Staircase method which is I search from the bottom left (bottom means lowest value column wise and left means biggest value row wise)
if that value is negative then the rest of the row is also negative so we calculate it and go up 
if the value is postive then we go to the next value in the row untill we find the first negative value


*/

#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int cnt = 0;
    int index = 0;
    for (int i = grid.size()-1; i >= 0; i--) {
        while (index < grid[i].size() && grid[i][index] >= 0) {
            index++;
        }
        cnt += grid[i].size()-index;
    }
    return cnt;
}

int main () {
    // vector<vector<int>>grid = {
    //     {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}
    // };
    vector<vector<int>>grid = {
        {3,2},{1,0}
    };
    cout << countNegatives(grid);
}