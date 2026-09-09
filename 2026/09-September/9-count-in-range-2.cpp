#include <bits/stdc++.h>
using namespace std;

long long countCommas(long long n) // Med
{
    long long p = 1000, res = 0;
    while (p <= n)
    {
        res += n - p + 1;
        p *= 1000;
    }
    return res;
}

int main()
{
    long long t = 1002;
    cout << countCommas(t);
}


// Solved using this formula:
// Each power of 1000(p) up to n, contributes an additional n-p+1
// then p*1000