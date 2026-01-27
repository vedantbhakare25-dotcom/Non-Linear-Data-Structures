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

vector<int> levelOrder(treenode *root)
{
    vector<int> result;
    queue<treenode*>q;
    if(root==NULL)
    {
        return result;
    }
    q.push(root);
    while(!q.empty())
    {
        treenode *curr=q.front();
        q.pop();
        result.push_back(curr->data);

        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
    return result;
}
int main()
{
    treenode *root=new treenode(1);
    root->left=new treenode(2);
    root->right=new treenode(3);
    root->left->left=new treenode(4);
    root->left->right=new treenode(5);

    vector<int> result=levelOrder(root);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}