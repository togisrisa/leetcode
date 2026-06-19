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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return RecursiveCheck(p, q);
    }

private:
    bool RecursiveCheck(TreeNode *l, TreeNode *r) {
        if (!l && !r) {
            return true;
        }
        if (!l || !r) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }

        return RecursiveCheck(l->left, r->left) && RecursiveCheck(l->right, r->rigth);
    }
};

int main() {
}
