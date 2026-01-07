class Solution {
public:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};