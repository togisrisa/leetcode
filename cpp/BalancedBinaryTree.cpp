#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};


class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return (checkHeight(root) != -1);
    }

private:
    int checkHeight(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) {
            return -1;
        }

        if ((leftHeight - rightHeight) > 1) {
            return -1;
        }

        return std::max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    using namespace std::literals;

    // test case 1
    //   3
    //  / \
    // 9  20
    //   /  \
    //  15   7
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        Solution solution;
        std::cout << "Test case 1: "s << std::boolalpha << solution.isBalanced(root) << std::endl;

        delete root->right->right;
        delete root->right->left;
        delete root->right;
        delete root->left;
        delete root;
    }

    // test case 2
    //       1
    //      / \
    //     2   2
    //    / \
    //   3   3
    //  / \
    // 4   4
    {

        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(3);
        root->left->left->left = new TreeNode(4);
        root->left->left->right = new TreeNode(4);

        Solution solution;
        std::cout << "Test case 2: "s << std::boolalpha << solution.isBalanced(root) << std::endl;

        delete root->left->left->right;
        delete root->left->left->left;
        delete root->left->right;
        delete root->left->left;
        delete root->right;
        delete root->left;
        delete root;
    }

    // test case 3
    // []
    {
        TreeNode *root = nullptr;
        Solution solution;
        std::cout << "Test case 3: "s << solution.isBalanced(root) << std::endl;
    }
}
