#include<bits/stdc++.h>
using namespace std;

struct Treenode
{
    int data;
    Treenode *left;
    Treenode *right;
    Treenode(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

vector<int> InorderTraversal(Treenode* root)
{
    vector<int> inorder;
    stack<Treenode*> st;
    Treenode* node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);        
            node = node->left;    
        }
        else
        {
            if (st.empty()) break;

            node = st.top();
            st.pop();
            inorder.push_back(node->data);  
            node = node->right;              
        }
    }
    return inorder;
}


int main()
{
    Treenode *root= new Treenode(1);
    root->left= new Treenode(2);
    root->right= new Treenode(3);
    root->left->left= new Treenode(4);
    root->left->right= new Treenode(5);
    vector<int> inorder= InorderTraversal(root);
    for(int i=0;i<inorder.size();i++)
    {
        cout<<inorder[i]<<" ";
    }
}