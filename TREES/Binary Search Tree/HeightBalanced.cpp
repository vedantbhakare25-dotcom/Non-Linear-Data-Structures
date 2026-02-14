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
int Diameter(treenode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return nodeCount++;
    }
    Diameter(root->left);
    Diameter(root->right);
    return nodeCount;
}
int isBalanced(treenode *root)
{
    if(root==NULL) return 1;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);

    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

int main()
{
    treenode *root=new treenode(1);
    root->left=new treenode(2);
    root->right=new treenode(3);
    root->left->left=new treenode(4);
    root->left->right=new treenode(5);
    root->left->left->left=new treenode(6);

    if(isBalanced(root))
        cout<<"The tree is height balanced"<<endl;
    else
        cout<<"The tree is not height balanced"<<endl;

    return 0;
}