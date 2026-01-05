// LeetCode #2483 - Minimum Penalty for a Shop
// Date Solved: 2025-12-26
// Difficulty: Medium

/*  Notes:

I understod the statment wrong

The Correct understanding is If I say the Shop closes at hour 2 then customers 0,1 are served not 0,1,2

Then If I said the Shop closed at 0 -> No Customers Served -> Penalty = total sum of Y
then I keep decreasing everytime I see Y while iterating through customers
if I found N I will increase it

i -> index of last served customer
i+1 -> the hour the shop closes at

*/

#include <bits/stdc++.h>
using namespace std;

int bestClosingTime(string customers) {
    // int ys = 0, ns = 0;
    // for (auto &i : customers) i == 'Y' ? ys++ : ns++;
    // if (ns == customers.size()) return 0;
    // int min = ns, minIndex = customers.size();

    // vector<int>penalty(customers.size());
    // int currN = 0;
    // for (int i = 0; i < customers.size(); i++) { 
    //     if (customers[i] == 'N') {
    //         currN++;
    //         penalty[i] = ys+currN;
    //     } else penalty[i] = ys+currN;

    //     if (customers[i] != 'N') ys--;

    //     if (min >= penalty[i]) {
    //         min = penalty[i];
    //         minIndex = i;
    //     }
    // }
    // for (auto &i : penalty) cout << i << " ";
    // return minIndex;
    int ys = 0;
    for (char &i : customers) if (i == 'Y') ys++;
    int minPel = ys;
    int minHour = 0;
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i] == 'Y') ys--;
        else ys++;

        if (minPel > ys) {
            minHour = i+1;
            minPel = ys;
        }
    }
    return minHour;
}

int main () {
    cout << "\n" << bestClosingTime("NNNYNN");
    // cout << "\n";
    // cout << bestClosingTime("NYYN");

    return 0;
}


