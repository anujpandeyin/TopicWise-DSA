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
    }
};

void BFSTravarsal(node* root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data;
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    node* root=new node(2);
    root->left=new node(6);
    root->right=new node(8);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(9);
    BFSTravarsal(root);

    return 0;
}
