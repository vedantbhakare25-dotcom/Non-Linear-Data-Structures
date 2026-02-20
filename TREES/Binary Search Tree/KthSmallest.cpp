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
        left = right = NULL;
    }
};

vector<int> traversal(treenode *root)
{
    vector<int> v;
    if(root==NULL) return v;
    vector<int> left = traversal(root->left);
    v.insert(v.end(), left.begin(), left.end());
    v.push_back(root->data);
    vector<int> right = traversal(root->right);
    v.insert(v.end(), right.begin(), right.end());

    return v;
}
int kthsmallest(treenode *root, int k)
{
    vector<int> v=traversal(root);
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
    {
        if(i==k-1)
        {
            return v[i];
        }
    }
    return -1;
}
int main()
{
    treenode *root = new treenode(5);
    root->left = new treenode(3);
    root->right = new treenode(6);
    root->left->left = new treenode(2);
    root->left->right = new treenode(4);
    int k=3;
    cout<<"Kth smallest element is: "<<kthsmallest(root,k)<<endl;
    return 0;
}