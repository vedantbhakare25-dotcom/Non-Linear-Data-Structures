#include<bits/stdc++.h>
using namespace std;
struct treenode
{
    int data;
    treenode *left;
    treenode *right;
    treenode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> postordertraversal(treenode *root)
{
    vector<int> postorder;
    stack<treenode*> st1,st2;
    if(root==NULL) return postorder;
    st1.push(root);
    while(!st1.empty())
    {
      root=st1.top();
      st1.pop();
      st2.push(root);
      if(root->left!=NULL){st1.push(root->left);}
      if(root->right!=NULL){st1.push(root->right);}
    }
    while(!st2.empty())
    {

        postorder.push_back(st2.top()->data);
        st2.pop();
    }  
    return postorder;
}
int main()
{
    treenode *node=new treenode(1);
    node->left= new treenode(2);
    node->right= new treenode(3);
    node->left->left= new treenode(4);
    node->left->right= new treenode(5);
    vector<int> postorder=postordertraversal(node);
    for(int i=0;i<postorder.size();i++)
    {
        cout<<postorder[i]<<" ";
    }
}