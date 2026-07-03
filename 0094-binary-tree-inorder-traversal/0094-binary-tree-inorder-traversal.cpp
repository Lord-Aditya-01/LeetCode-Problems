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
    void Inorder(TreeNode* r, vector<int>& ans) {
        if(r == NULL) return;
        if(r->left) {
            Inorder(r->left, ans);
        }
        ans.push_back(r->val);
        if(r->right) {
            Inorder(r->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> ans;
        Inorder(temp, ans);
        return ans;
    }
};