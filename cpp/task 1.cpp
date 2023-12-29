#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSumHelper(root, max_sum);
        return max_sum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& max_sum) {
        if (!node) {
            return 0;
        }

        int left_max = max(0, maxPathSumHelper(node->left, max_sum));
        int right_max = max(0, maxPathSumHelper(node->right, max_sum));
        max_sum = max(max_sum, left_max + right_max + node->val);
        return max(left_max, right_max) + node->val;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(0);
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
