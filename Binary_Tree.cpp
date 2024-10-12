#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void InOrder(Node *root) // order is--> left-->root-->right
{
    if(!root) return;
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}

void Print_LevelOrder(Node *root) // order is--> Level Wise left--> right
{
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
}

void PostOrder(Node *root) // order is--> left-->right-->root
{
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
}

void PreOrder(Node *root) // order is--> root-->left-->right
{
    if(!root) return;
    cout<<root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);
        p->left = myLeft;
        p->right = myRight;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
void level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree nai" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
int main()
{
    Node *root = input_tree();
    Print_LevelOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    return 0;
}
