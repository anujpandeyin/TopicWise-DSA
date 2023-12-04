#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    };
};
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    };

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
};

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    };

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
};
void postorder(node *root)
{

    if (root == NULL)
    {
        return;
    };

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
};
int main()
{
    node *root = new node(2);
    root->left = new node(6);
    root->right = new node(8);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(9);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
};
//         2
//    6          8
// 3    4    5    6