#include<bits/stdc++.h>
using namespace std; 
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// void preorder(Node* root)
// {
//     if(root== NULL)
//     {
//         return;
//     }
//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
// }
vector<int> preorder(Node* root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    vector<int> left=preorder(root->left);  
    vector<int> right=preorder(root->right);
    ans.insert(ans.end(),left.begin(),left.end());
    ans.insert(ans.end(),right.begin(),right.end());
    return ans;
    

}
int main()
{
    Node *root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    vector<int> result=preorder(root);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}