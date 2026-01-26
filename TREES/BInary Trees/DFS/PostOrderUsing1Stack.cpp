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
vector<int> IterativePostOrder(treenode *root)
{
    vector<int> postorder;
    stack<treenode*> st1;
    treenode *temp;
    while (root!=NULL||!st1.empty())
    {
        if(root!=NULL)
        {
            st1.push(root);
            root=root->left;
        }
        else
        {
            temp=st1.top()->right;
            if(temp==NULL)
            {
                temp=st1.top();
                st1.pop();
                postorder.push_back(temp->data);
                while(!st1.empty() && temp==st1.top()->right)
                {
                    temp=st1.top();
                    st1.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                root=temp;
            }
        } 
    }
    return postorder;
}
int main()
{
    treenode *root=new treenode(1);
    root->left=new treenode(2);
    root->right=new treenode(3);
    root->left->left=new treenode(4);
    root->left->right=new treenode(5);
    vector<int> postorder=IterativePostOrder(root);
    for(int i=0;i<postorder.size();i++)
        cout<<postorder[i]<<" ";
}