#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value)
    {
        val=value;
        left=NULL;
        right=NULL;
    }
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    stack<TreeNode* > st;
    if(root==NULL) return inorder;
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        if(node->right!=NULL) st.push(node->right);
        inorder.push_back(node->val);
        if(node->left!=NULL) st.push(node->left);
    }
    return inorder;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = inorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}