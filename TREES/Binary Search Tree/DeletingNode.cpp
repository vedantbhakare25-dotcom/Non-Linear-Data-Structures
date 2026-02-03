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
treenode* findright(treenode *root)
{
    while(root->right != NULL)
        root = root->right;
    return root;
}

treenode* helper(treenode* root)
{
    if(root->left == NULL)
    {
        treenode* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL)
    {
        treenode* temp = root->left;
        delete root;
        return temp;
    }

    treenode* rightchild = root->right;
    treenode* lastright = findright(root->left);
    lastright->right = rightchild;

    treenode* temp = root->left;
    delete root;
    return temp;
}

treenode* deletenode(treenode *root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return helper(root);
    }
    treenode *dummy=root;
    while(root!=NULL)
    {
        if(root->data>key)
        {
            if(root->left!=NULL && root->left->data==key)
            {
                root->left=helper(root->left);
            }
            else
            {
                root=root->left;
            }
        }
        else
        {
            if(root->right!=NULL && root->right->data==key)
            {
                root->right=helper(root->right);
            }
            else
            {
                root=root->right;
            }
        }
    }
    return dummy;
}


int main()
{
    treenode *root=new treenode(5);
    root->left=new treenode(3);
    root->right=new treenode(6);
    root->left->left=new treenode(2);
    root->left->right=new treenode(4);
    root->right->right=new treenode(7);

    int key=3;
    treenode *newroot=deletenode(root,key);
    // The tree now has the node with value 3 deleted.
    cout << "Node with value " << key << " deleted from the BST." << endl;
    return 0;
}