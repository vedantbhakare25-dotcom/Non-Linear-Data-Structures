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
        left=NULL;
        right=NULL;
    }
};
int maxDepth(treenode *root)
{
    if(root==NULL) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);

    return 1+max(lh,rh);
}
int  main()
{
    treenode * root=new treenode(1);
    root->left=new treenode(2);
    root->right=new treenode(3);
    root->left->left=new treenode(4);
    root->left->right=new treenode(5);
    root->left->left->left=new treenode(6);
    cout<<maxDepth(root);
}