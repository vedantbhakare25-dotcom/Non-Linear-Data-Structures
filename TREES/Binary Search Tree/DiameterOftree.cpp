#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    int data;
    treenode *left;
    treenode *right;
    int diameter;
    treenode(int val)
    {
        data = val;
        left = right = NULL;
        diameter = 0;
    }
};
int height(treenode*root, int &diameter)
{
    if(!root)
    {
        return 0;
    }
    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfTree(treenode* root)
{
    int diameter=0;
    height(root,diameter);
    return diameter;
}


int main()
{
    treenode *root = new treenode(1);
    root->left = new treenode(2);
    root->right = new treenode(3);
    root->left->left = new treenode(4);
    root->left->right = new treenode(5);
    cout << "Diameter of the tree is: " << diameterOfTree(root) << endl;
    return 0;
}