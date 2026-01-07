class Solution {
public:
    int maxCount = 0;
    int currentCount = 0;
    TreeNode* prev = nullptr;
    vector<int> result;

    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (prev && prev->val == node->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }
        
        if (currentCount > maxCount) {
            maxCount = currentCount;
            result.clear();
            result.push_back(node->val);
        } else if (currentCount == maxCount) {
            result.push_back(node->val);
        }
        
        prev = node;
        
        inorder(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};