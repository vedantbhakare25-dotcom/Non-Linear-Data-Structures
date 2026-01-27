#include<bits/stdc++.h>
using namespace std;

struct treenode
{
    int data;
    treenode *left;
    treenode *right;
    treenode(int val)
    {
        left=NULL;
        right=NULL;
        data=val;
    }
};

treenode* CopyTree(treenode* root)
{
    if(root==NULL) 
    {
        return NULL;
    }
    treenode *newnode=new treenode(root->data);
    newnode->left=CopyTree(root->left);
    newnode->right=CopyTree(root->right);
    return newnode;
}
int main()
{
    treenode *root=new treenode(1);
    root->left=new treenode(2);
    root->right=new treenode(3);
    root->left->left=new treenode(4);
    root->left->right=new treenode(5);
    treenode *copy=CopyTree(root);

}