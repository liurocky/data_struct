// C++ program to check if binary tree 
// is subtree of another binary tree 
#include <stdlib.h>
#include <iostream>
using namespace std;

#if 0

/* A binary tree node has data,
left child and right child */
class node
{
public:
    int data;
    node* left;
    node* right;
};

/* A utility function to check
whether trees with roots as root1 and
root2 are identical or not */
bool areIdentical(node* root1, node* root2)
{
    /* base cases */
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    /* Check if the data of both roots is
    same and data of left and right
    subtrees are also same */
    return (root1->data == root2->data &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right));
}


/* This function returns true if S
is a subtree of T, otherwise false */
bool isSubtree(node* T, node* S)
{
    /* base cases */
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    /* Check the tree with root as current node */
    if (areIdentical(T, S))
        return true;

    /* If the tree with root as current
    node doesn't match then try left
    and right subtrees one by one */
    return isSubtree(T->left, S) ||
        isSubtree(T->right, S);
}


/* Helper function that allocates
a new node with the given data
and NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}

/* Driver code*/
int main()
{
    // TREE 1  
    /* Construct the following tree
            26
            / \
        10 3
        / \ \
    4 6 3
    \
        30
    */
    node* T = newNode(26);
    T->right = newNode(3);
    T->right->right = newNode(3);
    T->left = newNode(10);
    T->left->left = newNode(4);
    T->left->left->right = newNode(30);
    T->left->right = newNode(6);

    // TREE 2  
    /* Construct the following tree
        10
        / \
    4 6
    \
        30
    */
    node* S = newNode(10);
    S->right = newNode(6);
    S->left = newNode(4);
    S->left->right = newNode(30);


    if (isSubtree(T, S))
        cout << "Tree 2 is subtree of Tree 1";
    else
        cout << "Tree 2 is not a subtree of Tree 1";

    return 0;
}

#else 
// A recursive CPP program to find 
// LCA of two nodes n1 and n2.  

class node
{
public:
    int data;
    node* left, * right;
};

/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node* lca(node* root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller 
    // than root, then LCA lies in left  
    if (root->data > n1&& root->data > n2)
        return lca(root->left, n1, n2);

    // If both n1 and n2 are greater than  
    // root, then LCA lies in right  
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}

/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return(Node);
}

//Approach: For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1and n2 
// is the LCA of the nodes, i.e.the first node n with the lowest depth which lies in between n1and n2(n1 <= n <= n2) n1 < n2.
//So just recursively traverse the BST in, if node's value is greater than both n1 and n2 then our LCA lies in the left side of the node,
//if it's is smaller than both n1 and n2, then LCA lies on the right side.Otherwise, the root is LCA(assuming that both n1 and n2 are present in BST).
//
//    Algorithm :
//
//    Create a recursive function that takes a nodeand the two values n1and n2.
//    If the value of the current node is less than both n1and n2, then LCA lies in the right subtree.Call the recursive function for thr right subtree.
//    If the value of the current node is greater than both n1and n2, then LCA lies in the left subtree.Call the recursive function for thr left subtree.
//    If both the above cases are false then return the current node as LCA.

/* Driver code*/
int main()
{
    // Let us construct the BST  
    // shown in the above figure  
    node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    node* t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
    return 0;
}

// This code is contributed by rathbhupendra 
#endif