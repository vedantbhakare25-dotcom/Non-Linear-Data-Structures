#include<bits/stdc++.h>
using namespace std;

struct treenode
{
    int data;
    treenode *left;
    treenode *right;

    treenode(int val)
    {
        data=val;        
        left=right=NULL;
    }
};

bool isBST(treenode *root, int minVal, int maxVal)
{
    if(root==NULL)
        return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main()
{
    treenode *root=new treenode(4);
    root->left=new treenode(2);
    root->right=new treenode(5);
    root->left->left=new treenode(1);
    root->left->right=new treenode(3);

    if(isBST(root, INT_MIN, INT_MAX))
        cout << "The tree is a binary search tree" << endl;
    else
        cout << "The tree is not a binary search tree" << endl;

    return 0;
}
