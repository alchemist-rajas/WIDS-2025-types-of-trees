class Solution {
public:
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        traverse(node->left, result);
        result.push_back(node->val);
        traverse(node->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};