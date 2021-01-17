#include <vector>
using std::vector;


#include <iostream>
using namespace std;


// Most people have figured out the binary search solution but are not able to understand how its working. 
//I will try to explain it simply. What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current).
//How does that guarantee the result? Think about it, there are 2 possibilities.a) rising slope has to keep rising till end of the array b) rising slope will encounter a lesser element and go down.
//In both scenarios we will have an answer.In a) the answer is the end element because we take the boundary as - INFINITY b) the answer is the largest element before the slope falls.Hope this makes things clearer.
// 1 2 3 4 5 6 4 7 3  -> 5 
int find_peak(const vector<int>& v) {
    for (int i = 1; i + 1< v.size(); i++) {
        if (v[i] > v[i - 1] && v[i] > v[i+1]) return i;
    }
    return -1;
} 

int findPeakElement(const vector<int>& nums)
{
    int n = nums.size();
    if (0 == n) return -1;
    if (1 == n) return 0;
    if (2 == n) return nums[0] > nums[1] ? 0 : 1;
    // 
    int low = 0, high = n - 1;
    while (low + 2 <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;
        if (nums[mid - 1] > nums[mid])
            high = mid;
        else
            low = mid;
    }
    // 
    return nums[low] > nums[high] ? low : high;
}
#include <algorithm>

struct TimeWindow {
    uint32_t beg_time;
    uint32_t end_time;

    TimeWindow(uint32_t a, uint32_t b) : beg_time(a), end_time(b) {

    }
    TimeWindow() {
        memset(this, 0, sizeof(*this));
    }
    bool operator < (const TimeWindow& rhs) {
        return this->end_time < rhs.end_time;
    }
};

int findMaxMovie( vector<TimeWindow>& tw_vec ) {
    std::sort(tw_vec.begin(), tw_vec.end());
    uint32_t back_time = 0;
    int ret = 0;
    for (int i = 0; i < tw_vec.size(); i++) {
        if (back_time == 0 || tw_vec[i].beg_time > back_time) {
            ret++;
            back_time = tw_vec[i].end_time;
        }
    }
    return ret;
}

void TestMovie() {
    vector<TimeWindow> tw_vec;
    tw_vec.push_back(TimeWindow(1, 3));
    tw_vec.push_back(TimeWindow(1, 4));
    tw_vec.push_back(TimeWindow(2, 5));
    tw_vec.push_back(TimeWindow(3, 5));
    tw_vec.push_back(TimeWindow(7, 8));
    tw_vec.push_back(TimeWindow(6, 7));

    int ret = findMaxMovie(tw_vec);
    cout << ret << endl;
}



struct sNode {
    int value;
    sNode* next;
    sNode() {
        memset(this, 0, sizeof(*this));
    }
};

class  sList {
    sNode* m_pHead;
    sNode* m_pTail;
public:
    sList() {
        m_pHead = m_pTail = NULL;
    }

    sNode* Make(int v) {
        sNode* pNode = new sNode();
        pNode->value = v;
        return pNode;
    }
    void Push(int value) {
        if (m_pTail) {
            if (m_pHead == m_pTail) {
                m_pHead->next = m_pTail;
            }
            m_pTail->next = Make(value);
            m_pTail = m_pTail->next;
        }
        else {
            m_pHead = m_pTail = Make(value);
        }
    }

    void Reverse() {
         
        sNode* pCur = m_pHead;
        sNode* pPrev = NULL;
        while (pCur) {
            sNode* pNext = pCur->next;
            pCur->next = pPrev;
            pPrev = pCur;
            pCur = pNext;
        }

        m_pHead = pPrev;
    }

    bool IsCircle() {

        //1 2 3 4 5 6 7 8 1
        //1  2   3  4  5  6  7
        //1  3   5  7  1  3  5 7 
        // 
        sNode* p1 = m_pHead;
        sNode* p2 = m_pHead;
        while (p1 && p2) {
            if (p1 > p2) return true;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return false;
    }

    void Print() {

        sNode* pNode = m_pHead;
        while (pNode)
        {
            cout << pNode->value << "->";
            pNode = pNode->next;
        }
        cout << endl;
    }
};


// Iterative C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node* prev = NULL, * next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int f_step(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return f_step(n - 1) + f_step(n - 2);
}


int f_step_3(int n) {
    if (n <= 0)return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    return f_step_3(n - 1) + f_step_3(n - 2) + f_step_3(n-3);
}


#include <algorithm>
#include <numeric>

bool is_same_shape(const string& s, const string& t) {

    if (s.length() != t.length()) return false;
    vector<char> vs((1<<8), 0);
    for (int i = 0; i < s.length(); i++) {
        vs[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++) {
        vs[t[i]]--;
    }

    return std::accumulate(vs.begin(), vs.end(), 0) == 0;
}

int find_in_rotate_array(vector<int>& v, int target) {
    if (v.empty()) return -1;
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (v[mid] == target)  return mid;
        else if (v[mid] < target) {
            if (v[mid] > v[0]) {
                left = mid + 1;
            }
            else {
                if (v[0] > target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        else { // v[mid] > target
            if (v[mid] > v[0]) {
                right = mid - 1;
            }
            else {
                if (v[0] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

        }

    }
    return -1;
}

// 给一棵非空二叉搜索树以及一个target值，找到在BST中最接近给定值的节点值 
// 实现 int sqrt(int x) 函数，计算并返回 x 的平方根
/*
Convert a Binary Tree to a Circular Doubly Link List
Last Updated : 27 - 08 - 2019
Given a Binary Tree, convert it to a Circular Doubly Linked List(In - Place).

The leftand right pointers in nodes are to be used as previousand next pointers respectively in converted Circular Linked List.
The order of nodes in List must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal must be head node of the Circular List.
*




// C++ Program to convert a Binary Tree
// to a Circular Doubly Linked List
#include<iostream>
using namespace std;

// To represents a node of a Binary Tree
struct Node
{
    struct Node *left, *right;
    int data;
};

// A function that appends rightList at the end
// of leftList.
Node *concatenate(Node *leftList, Node *rightList)
{
    // If either of the list is empty
    // then return the other list
    if (leftList == NULL)
        return rightList;
    if (rightList == NULL)
        return leftList;

    // Store the last Node of left List
    Node *leftLast = leftList->left;

    // Store the last Node of right List
    Node *rightLast = rightList->left;

    // Connect the last node of Left List
    // with the first Node of the right List
    leftLast->right = rightList;
    rightList->left = leftLast;

    // Left of first node points to
    // the last node in the list
    leftList->left = rightLast;

    // Right of last node refers to the first
    // node of the List
    rightLast->right = leftList;

    return leftList;
}

// Function converts a tree to a circular Linked List
// and then returns the head of the Linked List
Node *bTreeToCList(Node *root)
{
    if (root == NULL)
        return NULL;

    // Recursively convert left and right subtrees
    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);

    // Make a circular linked list of single node
    // (or root). To do so, make the right and
    // left pointers of this node point to itself
    root->left = root->right = root;

    // Step 1 (concatenate the left list with the list
    //         with single node, i.e., current node)
    // Step 2 (concatenate the returned list with the
    //         right List)
    return concatenate(concatenate(left, root), right);
}

// Display Circular Link List
void displayCList(Node *head)
{
    cout << "Circular Linked List is :\n";
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout << "\n";
}


// Create a new Node and return its address
Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver Program to test above function
int main()
{
    Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    Node *head = bTreeToCList(root);
    displayCList(head);

    return 0;
}



/* Driver code*/
int main1()
{



    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}




int main(int argc, char** argv) {

    vector<int> vv = { 1,2,3,4,5,6 };
    cout << find_in_rotate_array(vv, 4) << endl;
    vector<int> vv2 = { 5,6,1,2,3,4};
    cout << find_in_rotate_array(vv2, 4) << endl;

    const char* s = "anagram";
    const char* t = "nagaram";
    cout << is_same_shape(s, t) << endl; 

    cout << f_step(3) << endl;
    cout << f_step(4) << endl;
    cout << f_step(5) << endl;

    // 1 1 1, 3,  1 2 , 2,1  
    //(1 3) (2 2) (1 1 1 1) (1 2 1) (1 1 2) (3 1) (2 1 1)
    for (int i = 1; i < 6; i++)
    {
        cout << i << "\t" << f_step_3(i) << endl;
    }
    

    sList list;
    list.Push(1);
    list.Push(2);
    list.Push(3);
    list.Push(4);
    list.Print();
    list.Reverse();
    list.Print();

    vector<int> v = {4,4,3,2,1,6,3};
    vector<int> v2 = { 1,2,3,4,3,4,3,2,1 };
    cout << find_peak(v) << endl;
    cout << findPeakElement(v2) << endl;
    return 0;
}