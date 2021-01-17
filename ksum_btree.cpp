#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int data;
    Node* left, * right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
    Node() {
        memset(this, 0, sizeof(Node));
    }
};

// utility function to print contents of
//a vector from index i to it's end 
void printVector(const vector<int> & v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void printKPathUtil(Node* root, vector<int>& path,
    int k)
{
    if (!root) return;

    path.push_back(root->data);

    printKPathUtil(root->left, path, k);
    printKPathUtil(root->right, path, k);
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if (sum == k) {
            printVector(path, i);
        }
    }
    path.pop_back();
}

// Utility function to find maximum of two integers 
int max(int a, int b)
{
    return (a >= b) ? a : b;
}

// 对任何一个节点
// left_sum 求出到其左子树的最大path
// right_sum 求出到其右子树额最大path
// left_sum+right_sum
int MaxSumPathOfLeaf(Node* root, int& n) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;

    int ls = MaxSumPathOfLeaf(root->left, n);
    int rs = MaxSumPathOfLeaf(root->right, n);
    if (root->left && root->right) {
        n = max(ls + rs + root->data, n);
        // Return maxium possible value for root being 
        // on one side 
        return max(ls, rs) + root->data;
    }
    // If any of the two children is empty, return 
    // root sum for root being on one side 
    return (!root->left) ? rs + root->data :
        ls + root->data;
}

// The main function which returns sum of the maximum 
// sum path between two leaves. This function mainly 
// uses maxPathSumUtil() 
int maxPathSum(struct Node* root)
{
    int res = INT_MIN;
    MaxSumPathOfLeaf(root, res);
    return res;
}

// Utility function to allocate memory for a new node 
struct Node* newNode(int data)
{
    struct Node* node = new(struct Node);
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void TestMaxSumK() {
    struct Node* root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right = newNode(0);
    root->right->right->right->left = newNode(4);
    root->right->right->right->right = newNode(-1);
    root->right->right->right->right->left = newNode(10);
    cout << "Max pathSum of the given binary tree is "
        << maxPathSum(root);
}
void PreOrder(Node* root) {
    if (!root) {
        cout << "leaf" << endl;
        return;
    }
    cout << root->data << endl;
    PreOrder(root->left);
    PreOrder(root->right);
    cout << root->data << " finish."  << endl;
}

int main(int agrc, char** argv) {
    TestMaxSumK();

    return 0;

    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    PreOrder(root);

    int k = 5;
    vector<int> path;
    printKPathUtil(root, path, k);

    return 0;
}