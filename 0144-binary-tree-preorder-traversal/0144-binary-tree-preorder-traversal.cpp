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
    void preorder(TreeNode* r, vector<int>& ans) {
        if(r == NULL) return;
        ans.push_back(r->val);
        if(r->left) {
            preorder(r->left, ans);
        }
        if(r->right) {
            preorder(r->right, ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> ans;
        preorder(temp, ans);
        return ans;
    }
};