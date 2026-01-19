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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    stack<TreeNode* > st;
    if(root==NULL) return preorder;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        preorder.push_back(node->val);
        if(node->right!=NULL) st.push(node->right);
        if(node->left!=NULL) st.push(node->left);
    }
    return preorder;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = preorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}