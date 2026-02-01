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
treenode* insertBST(treenode* root, int val)
{
    if (root == NULL)
        return new treenode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

treenode* bstSearch(treenode* root,int search)
{
    // while(root!=NULL && root->data!=search)
    // {
    //     if(search<root->data)
    //         root=root->left;
    //     else
    //         root=root->right;
    // }
    // return root;
    while(root!=NULL && root->data!=search)
    {
        root=search<root->data ? root->left : root->right;
    }
    return root;
}
int main()
{
    treenode* root = NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 1);
    root = insertBST(root, 3);
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 7);
    root = insertBST(root, 6);

    if (bstSearch(root, 4) != NULL)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}