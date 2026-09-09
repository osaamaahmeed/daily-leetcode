#include <bits/stdc++.h>
using namespace std;

int countCommas(int n)
{ // Easy
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i > 999)
        {
            ans += 1;
        }
    }
    return ans;
}

int main()
{
    long long t = 1002;
    cout << countCommas(t);
}

// Can be solved with brute force, cause n <= 10^5