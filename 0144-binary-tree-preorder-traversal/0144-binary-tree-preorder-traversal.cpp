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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {

            // No left subtree
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {

                // Find inorder predecessor
                TreeNode* pred = curr->left;

                while (pred->right != NULL && pred->right != curr)
                    pred = pred->right;

                // Create thread
                if (pred->right == NULL) {
                    ans.push_back(curr->val);   // Visit before going left
                    pred->right = curr;
                    curr = curr->left;
                }
                // Thread already exists
                else {
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};