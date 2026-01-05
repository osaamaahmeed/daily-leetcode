// LeetCode #3606 - Coupon Code Validator
// Date Solved: 2025-12-13
// Difficulty: Easy

/* Notes:

- No Tricks here, easy problem
- Need Optimization

*/


#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    if (s.empty()) return false;
    for (auto i : s) {
        if ( !((i >= 48 && i <= 57)  ||  (i >= 65 && i <= 90) || (i >= 97 && i <= 122 ) || (i == '_')) ) {
            return false;
        }
    }
    return true;
}
vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    vector<string> e, g, p, r;
    for (int i = 0; i < code.size(); i++)
    {
        if (isActive[i])
        {
            if (check(code[i]))
            {
                if (businessLine[i] == "electronics")
                    e.push_back(code[i]);
                else if (businessLine[i] == "grocery")
                    g.push_back(code[i]);
                else if (businessLine[i] == "pharmacy")
                    p.push_back(code[i]);
                else if (businessLine[i] == "restaurant")
                    r.push_back(code[i]);
            }
        }
    }

    vector<string> ans;
    if (!e.empty())
    {
        sort(e.begin(), e.end());
        for (auto i : e)
            ans.push_back(i);
    }

    if (!g.empty())
    {
        sort(g.begin(), g.end());
        for (auto i : g)
            ans.push_back(i);
    }
    if (!p.empty())
    {
        sort(p.begin(), p.end());
        for (auto i : p)
            ans.push_back(i);
    }
    if (!r.empty())
    {
        sort(r.begin(), r.end());
        for (auto i : r)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<string> code = {"GROCERY15","ELECTRONICS_50","DISCOUNT10"};
    vector<string> businessLine = {"grocery","electronics","invalid"};
    vector<bool> isActive = {false,true,true};
    vector<string> ans = validateCoupons(code, businessLine, isActive);
    for (auto i : ans)
        cout << i << " ";
}