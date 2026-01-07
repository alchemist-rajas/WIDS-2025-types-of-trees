class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        
        inorder(node->left);
        
        if (prev != nullptr) {
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node;
        
        inorder(node->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};