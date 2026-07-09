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
    void checkVal(TreeNode* l, TreeNode* r, bool& ans) {
        if(!ans) return;
        if(l == NULL && r == NULL) {
            return;
        }
        if(l == NULL || r == NULL) {
            ans = false;
            return;
        }
        if(l->val != r->val){
            ans = false;
            return;
        }
        checkVal(l->left, r->right, ans);
        checkVal(l->right, r->left, ans);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        bool ans = true;
        checkVal(root->left, root->right, ans);
        return ans;
    }
};