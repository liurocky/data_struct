//Symmetric Tree

// C++ program to check if a given Binary Tree is symmetric or not 
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node 
struct Node
{
    int key;
    struct Node* left, * right;
};

// Utility function to create new Node 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

// Returns true if trees with roots as root1 and root2 are mirror 
bool isMirror(struct Node* root1, struct Node* root2)
{
    // If both trees are emptu, then they are mirror images 
    if (root1 == NULL && root2 == NULL)
        return true;

    // For two trees to be mirror images, the following three 
    // conditions must be true 
    // 1 - Their root node's key must be same 
    // 2 - left subtree of left tree and right subtree 
    //      of right tree have to be mirror images 
    // 3 - right subtree of left tree and left subtree 
    //      of right tree have to be mirror images 
    if (root1 && root2 && root1->key == root2->key)
        return isMirror(root1->left, root2->right) &&
        isMirror(root1->right, root2->left);

    // if neither of above conditions is true then root1 
    // and root2 are not mirror images 
    return false;
}

// Returns true if a tree is symmetric i.e. mirror image of itself 
bool isSymmetric(struct Node* root)
{
    // Check if tree is mirror of itself 
    return isMirror(root, root);
}


// Returns true if a tree is symmetric  
// i.e. mirror image of itself 
bool isSymmetric2(struct Node* root)
{
    if (root == NULL)
        return true;

    // If it is a single tree node, then  
    // it is a symmetric tree. 
    if (!root->left && !root->right)
        return true;

    queue <Node*> q;

    // Add root to queue two times so that 
    // it can be checked if either one child 
    // alone is NULL or not. 
    q.push(root);
    q.push(root);

    // To store two nodes for checking their 
    // symmetry. 
    Node* leftNode, * rightNode;

    while (!q.empty()) {

        // Remove first two nodes to check 
        // their symmetry. 
        leftNode = q.front();
        q.pop();

        rightNode = q.front();
        q.pop();

        // if both left and right nodes  
        // exist, but have different  
        // values--> inequality, return false 
        if (leftNode->key != rightNode->key) {
            return false;
        }

        // Push left child of left subtree node 
        // and right child of right subtree 
        // node in queue. 
        if (leftNode->left && rightNode->right) {
            q.push(leftNode->left);
            q.push(rightNode->right);
        }

        // If only one child is present alone 
        // and other is NULL, then tree  
        // is not symmetric. 
        else if (leftNode->left || rightNode->right)
            return false;

        // Push right child of left subtree node 
        // and left child of right subtree node 
        // in queue. 
        if (leftNode->right && rightNode->left) {
            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        // If only one child is present alone 
        // and other is NULL, then tree  
        // is not symmetric.  
        else if (leftNode->right || rightNode->left)
            return false;
    }

    return true;
}


// Driver program 
int main()
{
    // Let us construct the Tree shown in the above figure 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    cout << isSymmetric(root);
    return 0;
}