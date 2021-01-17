// A recursive CPP program to find 
// LCA of two nodes n1 and n2.  
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* left, * right;
};


/*
Approach: For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. So just recursively traverse the BST in, if node's value is greater than both n1 and n2 then our LCA lies in the left side of the node, if it's is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST).

Algorithm:

Create a recursive function that takes a node and the two values n1 and n2.
If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for thr right subtree.
If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for thr left subtree.
If both the above cases are false then return the current node as LCA.
*/

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

//Iterative Implementation: The above solution uses recursion.
//The recursive solution requires extra space in the form of the function call stack.
//So an iterative solution can be implemented which does not occupy space in the form of the function call stack.
/* Function to find LCA of n1 and n2.
The function assumes that both n1 and n2
are present in BST */
struct node* lca2(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
        // If both n1 and n2 are smaller than root, 
        // then LCA lies in left 
        if (root->data > n1&& root->data > n2)
            root = root->left;

        // If both n1 and n2 are greater than root,  
        // then LCA lies in right 
        else if (root->data < n1 && root->data < n2)
            root = root->right;

        else break;
    }
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
