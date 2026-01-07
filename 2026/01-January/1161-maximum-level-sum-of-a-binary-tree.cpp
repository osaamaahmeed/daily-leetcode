// LeetCode #1161 - Maximum Level Sum of a Binary Tree
// Date Solved: 2026-01-06
// Difficulty: Medium


/* Problem Summary:
    - We have a binary tree and we want the level number with biggest sum of that level numbers
*/

/* Approach: BFS

Complexity:
Time: O(N)
Space: O(H) hight of the tree

We use BFS to traverse the tree level be level
and keep track of the biggest sum and its level
*/


#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right; 
    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

int levelOver (TreeNode *root) {
    queue<TreeNode *>q;
    int maxSum = root->val, maxLevel = 1;
    q.push(root);
    int currLevel = 1;
    while (!q.empty()) {
        int len = q.size();
        int temp = 0;
        for (int i = 0; i < len; i++) {
            TreeNode *node = q.front();
            temp += node->val;
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        if (temp > maxSum) {
            maxLevel = currLevel;
            maxSum = temp;
        }
        currLevel++;

    }
    return maxLevel;
}

int main() {
    // Example 1:
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    // Example 2:
    // TreeNode *root = new TreeNode(989);
    // root->right = new TreeNode(10250);
    // root->right->left = new TreeNode(98693);
    // root->right->right = new TreeNode(-89388);
    // root->right->right->right = new TreeNode(-32127);


    cout << levelOver(root);

    // vector<vector<int>> ans = levelOver(root);
    // for (auto i:ans) {
    //     for (auto j: i) cout << j << " ";
    //     cout << "\n";
    // }

    return 0;
}
