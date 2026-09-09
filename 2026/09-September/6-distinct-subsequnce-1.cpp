#include <bits/stdc++.h>
using namespace std;

int numDistinct(string s, string t) // Hard
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int MOD = (int)1e9 + 7;

    for (int i = 0; i <= n; i++)
    {
        dp[i][m] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            dp[i][j] = dp[i + 1][j];
            if (s[i] == t[j])
            {
                dp[i][j] = (dp[i][j] + dp[i + 1][j + 1]) % MOD;
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t);
}

/* String, DP
We used something called Tabulation (built bottom up)
(I attached a visualization for better understanding)

*/