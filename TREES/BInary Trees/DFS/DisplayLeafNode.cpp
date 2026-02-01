#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
vector<int> LeafNode(Node *root)
{
    vector<int> leafs;
    if(root==NULL)
    {
        return leafs;
    }  
    if(root->left==NULL && root->right==NULL)
    {
        leafs.push_back(root->data);
    }
    vector<int> leftLeafs=LeafNode(root->left);
    vector<int> rightLeafs=LeafNode(root->right);
    leafs.insert(leafs.end(),leftLeafs.begin(),leftLeafs.end());
    leafs.insert(leafs.end(),rightLeafs.begin(),rightLeafs.end());
    return leafs;
}

int main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    vector<int> result=LeafNode(root);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}

