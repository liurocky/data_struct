#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#if 1

struct Node {
    int data;
    Node* left;
    Node* right;
    Node() {
        memset(this, 0, sizeof(*this));
    }
    Node(int d) : data(d) {
        left = right = NULL;
    }
};

class BST {
    
public: 
    BST() {
        root = NULL;
    }
    Node* root;
    Node* insert(Node* node, int data) {
        if (!node) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        }
        else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void Insert(int data) {
        if (!root)  root = insert(root, data);
        else  insert(root, data);
    }

    void Print(Node* cur) {
        if (!cur) return;
       
        Print(cur->left);
        cout << cur->data << endl;
        Print(cur->right);
    }

    Node* search(Node* cur, int data) {
        if (!cur || cur->data == data) {
            return cur;
        }

        if (data < cur->data) {
            search(cur->left, data);
        }
        else {
            search(cur->right, data);
        }
    }
    Node* Search(int data) {

        return search(root, data);
    }
};

#include <vector>
using namespace std;

int main(int argc, char** argv) {

    vector<int> arr = { 5,3,7,8,10 };
    BST bst;
    for (int i = 0; i < arr.size(); i++) {
        bst.Insert(arr[i]);
    }

    bst.Print(bst.root);


    Node* fn = bst.Search(7);
    cout << fn->data << "||" << 7 << endl;
}


#else 

// C++ program to demonstrate insertion 
// in a BST recursively. 
#include <iostream> 
using namespace std;

class BST
{
    int data;
    BST* left, * right;

public:
    // Default constructor. 
    BST();

    // Parameterized constructor. 
    BST(int);

    // Insert function. 
    BST* Insert(BST*, int);

    // Inorder traversal. 
    void Inorder(BST*);
};

// Default Constructor definition. 
BST::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

// Parameterized Constructor definition. 
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition. 
BST* BST::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL. 
        return new BST(value);
    }

    // Insert data. 
    if (value > root->data)
    {
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 

        // Process right nodes. 
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 

        // Process left nodes. 
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion. 
    return root;
}

// Inorder traversal function. 
// This gives data in sorted order. 
void BST::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

// Driver code 
int main()
{
    BST b, * root = NULL;
    root = b.Insert(root, 5);
    b.Insert(root, 3);
    b.Insert(root, 7);
    b.Insert(root, 8);
    b.Insert(root, 10);
    //b.Insert(root, 60);
    //b.Insert(root, 80);

    b.Inorder(root);
    return 0;
}

// This code is contributed by pkthapa

#endif