#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    treenode *left;
    treenode *right;
    int data;
    treenode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> traversal(treenode *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    vector<int> left = traversal(root->left);
    v.insert(v.end(), left.begin(), left.end());
    v.push_back(root->data);
    vector<int> right = traversal(root->right);
    v.insert(v.end(), right.begin(), right.end());

    return v;
}
int kthsmallest(treenode *root)
{
    vector<int> v = traversal(root);
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < v[i + 1])
        {
            return v[i + 1];
        }
    }
        return -1;
}
int main()
{
    treenode *root = new treenode(5);
    root->left = new treenode(1);
    root->right = new treenode(6);
    root->left->left = new treenode(2);
    root->left->right = new treenode(4);
    cout << "Second minimum element is: " << kthsmallest(root) << endl;
    return 0;
}