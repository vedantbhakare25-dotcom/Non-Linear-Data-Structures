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

// void  postorder(Node* root)
// {
//     if(root== NULL)
//     {
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     cout<<root->data<<" ";
// }

vector<int> inorderTraversal(Node* root) {
vector<int> result;

if(root == NULL)
    return result;

vector<int> left = inorderTraversal(root->left);
vector<int> right = inorderTraversal(root->right);

// Left
result.insert(result.end(), left.begin(), left.end());

// Root
result.push_back(root->data);

// Right
result.insert(result.end(), right.begin(), right.end());

return result;
}
int main()
{
    Node *root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    vector<int> result = inorderTraversal(root);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }   
    return 0;
}