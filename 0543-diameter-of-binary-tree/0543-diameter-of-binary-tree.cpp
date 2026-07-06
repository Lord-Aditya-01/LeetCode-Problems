/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* temp, int& ans) {
        if(temp == NULL) return 0;
        int lh = find(temp->left, ans);
        int rh = find(temp->right, ans);
        ans = max(ans, lh+rh);
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        find(root, ans);
        return ans;
    }
};