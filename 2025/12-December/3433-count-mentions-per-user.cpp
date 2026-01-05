// LeetCode #3433 - Count Mentions Per User
// Date Solved: 2025-12-12
// Difficulty: Medium

/* Notes:

- Cutom Sort (using 2 factors)
- stoi

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countMentions(int numberOfUsers,
                        vector<vector<string>> &events)
{
    sort(events.begin(), events.end(),
        [](const vector<string> &a, const vector<string> &b)
        {
            int aa = stoi(a[1]);
            int bb = stoi(b[1]);
            if (aa != bb)
            {
                return aa < bb;
            }
            return (a[0] == "OFFLINE" && b[0] != "OFFLINE");
        });

    vector<int> offlineUntil(numberOfUsers, 0);
    vector<int> mentions(numberOfUsers, 0);

    for (int i = 0; i < events.size(); i++)
    {
        int time = stoi(events[i][1]);

        if (events[i][0] == "MESSAGE")
        {
            if (events[i][2] == "ALL")
            {
                for (int j = 0; j < numberOfUsers; j++)
                {
                    mentions[j]++;
                }
            }
            else if (events[i][2] == "HERE")
            {
                for (int j = 0; j < numberOfUsers; j++)
                {
                    if (offlineUntil[j] <= time)
                    {
                        mentions[j]++;
                    }
                }
            }
            else
            {
                string s = events[i][2];
                int idx = 0;
                while (idx < s.size())
                {
                    if (s.substr(idx, 2) == "id")
                    {
                        idx += 2;
                        int num = 0;
                        while (idx < s.size() && isdigit(s[idx]))
                        {
                            num = num * 10 + (s[idx] - '0');
                            idx++;
                        }
                        mentions[num]++;
                    }
                    else
                    {
                        idx++;
                    }
                }
            }
        }
        else if (events[i][0] == "OFFLINE")
        {
            int userId = stoi(events[i][2]);
            offlineUntil[userId] = time + 60;
        }
    }

    return mentions;
}

int main()
{
    vector<vector<string>> a = {{"OFFLINE", "1", "0"}, {"OFFLINE", "2", "1"}, {"MESSAGE", "2", "HERE"}, {"MESSAGE", "61", "HERE"}};
    vector<int> ans = countMentions(3, a);
    for (auto i : ans)
        cout << i << " ";
}
