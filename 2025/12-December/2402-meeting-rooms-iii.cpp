// LeetCode #2402 - Meeting Rooms III
// Date Solved: 2025-12-27
// Difficulty: Hard


// Notes: Attempted but not solved yet

#include<bits/stdc++.h>
using namespace std;



int mostBooked(int n, vector<vector<int>>& meetings) {
    // vector<pair<int,int>> rooms(meetings.size());
    multimap<int,int>rooms;
    int nextIndex = 0;
    for (int i = 0; i < n && i < meetings.size(); i++) {
    //     rooms[i].first = i;
    //     rooms[i].second = meetings[i][1];
    //     if (rooms[i].second < rooms[nextIndex].second) {
    //         nextIndex = i;
    //     }
    rooms.insert({meetings[i][1], i});       
    }
    auto it = rooms.begin();
    for (int i = n; i < meetings.size(); i++) {        
        rooms.insert({(*it).first+(meetings[i][1]-meetings[i][0]) , (*it).second});
        it++;
    }
    vector<int>freq(n,0);
    for (auto &i : rooms) {
        freq[i.second]++;
    }
    int maxFreq = 0, minIndex = 0;
    for (auto &i : freq) maxFreq = max(i, maxFreq);
    for (int i = 0; i < n; i++) {
        if (freq[i] == maxFreq) {
            minIndex = i;
            break;
        }
    }
    return minIndex;
}

int main () {
    vector<vector<int>> meetings = {
        {1,20},{2,10},{3,5},{4,9},{6,8}
    };
    cout << mostBooked(100, meetings);
}