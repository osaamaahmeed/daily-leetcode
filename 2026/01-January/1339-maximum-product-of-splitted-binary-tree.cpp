// LeetCode #1339 - Maximum Product of Splitted Binary Tree
// Date Solved: 2026-01-07
// Difficulty: Medium


/* Problem Summary:
    - We have a Binary Tree and we want to remove 1 edge
    - By removing this edge we create 2 sperate Binary Trees
    - We want to calculate the sum of each tree and muliply each summition
    - We now want the max product.
*/

/* Approach:
We Will use this formula:  Max(SubTreeSum * (maxSum-SubTreeSum) ) in each node
First We use DFS to calculate the maxSum by using normal DFS
then we use use another dfs function this functions does 2 things:
1. calculate the subTreeSum of each node
2. Treats the edge between the current node and its parent as a possible cut, and updates the maximum product using the formula.
then in the main problem function we run both functions and return the answer

Complexity:
Time: O(N)
Space: O(H) hight of the tree

*/

// Notes:

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


long long mxProduct = 0, totalSum = 0;

void totSum(TreeNode* node) {
    if (node == nullptr)
        return;
    totSum(node->left);
    totSum(node->right);
    totalSum += node->val;
}

long long dfs(TreeNode* node) {
    if (!node)
        return 0;
    long long left = dfs(node->left);
    long long right = dfs(node->right);

    long long subTreeSum = node->val + left + right;

    mxProduct = max(
        mxProduct, ((subTreeSum * (totalSum - subTreeSum))));

    return subTreeSum;
}

int maxProduct(TreeNode* root) {
    totSum(root);
    dfs(root);
    return mxProduct% (1000000000+7);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    cout << maxProduct(root);

    return 0;
}
