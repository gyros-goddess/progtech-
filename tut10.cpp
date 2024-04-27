#include <iostream>
using namespace std;

struct node
{
    node *right;
    node *left;
    int data;
    int height;
};

node *createNode(int value)
{
    node *newNode = new node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

node *insert(node *t, int key)
{
    if (t == nullptr)
    {
        node *p = new node;
        p->data = key;
        p->left = p->right = nullptr;
        return p;
    }
    if (t->data > key)
        t->left = insert(t->left, key);
    else if (t->data < key)
        t->right = insert(t->right, key);
    return t;
}

void preorder(node *t)
{
    if (t != nullptr)
    {
        cout << t->data << endl;
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(node *t)
{
    if (t != nullptr)
    {
        inorder(t->left);
        cout << t->data << endl;
        inorder(t->right);
    }
}

void postorder(node *t)
{
    if (t != nullptr)
    {
        postorder(t->left);
        postorder(t->right);
        cout << t->data << endl;
    }
}

node *search(node *t, int key)
{
    if (t == nullptr)
        return nullptr; // not found
    if (t->data == key)
        return t; // found
    if (t->data > key)
        return search(t->left, key);
    else
        return search(t->right, key);
}

void deleteLeafKey(node *&t, int key)
{
    node *current = t;
    node *parent = nullptr;

    while (current != nullptr && current->data != key)
    {
        parent = current;
        if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current != nullptr && current->left == nullptr && current->right == nullptr)
    {
        if (parent->left == current)
        {
            parent->left == nullptr;
        }
        else
        {
            parent->right == nullptr;
        }
        delete current;
    }
    else
    {
        cout << "the value is not a leaf" << endl;
    }
}


void deleteKey (node *t, int key){


}

int size(node *t)
{
    if (t == nullptr)
        return 0;
    return 1 + size(t->left) + size(t->right);
}

int height(node *t)
{
    if (t == nullptr)
        return 0;
    return 1 + max(height(t->left), height(t->right));
}

node *rightRotate(node *y)
{ // Δεξιά περιστροφή
    node *x = y->left;
    node *tmpNode = x->right;
    x->right = y; // περιστροφή: x είναι η νέα ρίζα
    y->left = tmpNode;
    y->height = max(height(y->left), height(y->right)) + 1; // ενημέρωση υψών
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node *leftRotate(node *x)
{ // Αριστερή περιστροφή
    node *y = x->right;
    node *tmpNode = y->left;
    y->left = x;
    x->right = tmpNode;
    x->height = max(height(x->left), height(x->right)) + 1; // ενημέρωση υψών
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(node *t)
{
    if (t == nullptr)
        return 0;
    return height(t->left) - height(t->right);
}

node *insert(node *insertedNode, int key)
{
    if (insertedNode == NULL) // 1. εισαγωγή στο BST χωρίς ζύγισμα
        return (createNode(key));
    if (key < insertedNode->data)
        insertedNode->left = insert(insertedNode->left, key);
    else if (key > insertedNode->data)
        insertedNode->right = insert(insertedNode->right, key);
    else // Δεν επιτρέπονται διπλά κλειδιά
        return insertedNode;
    insertedNode->height = 1 + max(height(insertedNode->left), // 2. ενημέρωση υψών
                                   height(insertedNode->right));
    int balance = getBalance(insertedNode);

    if (balance > 1 && key < insertedNode->left->data) // Left Left
        return rightRotate(insertedNode);
    if (balance < -1 && key > insertedNode->right->data) // Right Right
        return leftRotate(insertedNode);
    if (balance > 1 && key > insertedNode->left->data)
    { // Left Right
        insertedNode->left = leftRotate(insertedNode->left);
        return rightRotate(insertedNode);
    }
    if (balance < -1 && key < insertedNode->right->data)
    { // Right Left
        insertedNode->right = rightRotate(insertedNode->right);
        return leftRotate(insertedNode);
    }
    return insertedNode;
}

int main()
{
    node *root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    int a[3] = {1, 2, 3};
    /*
    {1,2,3}, {1,3,2}, {3,2,1}, {3,1,2}, {2,1,3}, {2,3,1}
    */

    postorder(root);
}

// O(1)
// O(log(n))
// O(nlog(n))
// O(3n) = O(n)
// O(5n^2) = O(n^2)
// O(n^3)
// O(2^n)
// O(n!)
// O(n^n)

//    10
//   /  \
//   5   15
//  / \   / \
// 2   7 12  18
