#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node, int current, int& sum) {
    if (!node) return;
    current = current * 10 + node->val;
    if (!node->left && !node->right) {
        sum += current;
        return;
    }
    dfs(node->left, current, sum);
    dfs(node->right, current, sum);
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    dfs(root, 0, sum);
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sumNumbers(root) << endl;
    return 0;
}
