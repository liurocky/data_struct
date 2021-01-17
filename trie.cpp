#include <iostream>
#include <string>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool is_end;

    TrieNode (){
        memset(this, 0, sizeof(*this));
    }
};

TrieNode* GetNode() {
    return new TrieNode;
}

bool Insert(TrieNode* root, const string& key) {

    if (!root) {
        return false;
    }
    TrieNode* pCur = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (!pCur->children[index]) {
            pCur->children[index] = GetNode();
        }
        pCur = pCur->children[index];
    }
    pCur->is_end = true;
    return true;
}

bool Search(TrieNode* root, const string& key) {
    TrieNode* pCur = root;

    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (index >= ALPHABET_SIZE) return false;
        if (pCur->children[index]) {
            pCur = pCur->children[index];
        }
        else {
            return false;
        }
    }
    if (pCur->is_end) return true;
}

//  
bool Delete(TrieNode* root, const string& key) {
    TrieNode* pCur = root;

    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (index >= ALPHABET_SIZE) return false;
        if (pCur->children[index]) {
            pCur = pCur->children[index];
        }
        else {
            return false;
        }
    }
    if (pCur->is_end) pCur->is_end = 0;
}

int main() {

    string keys[] = { "the", "a", "there",
                    "answer", "any", "by",
                    "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);
    struct TrieNode* root = GetNode();

    // Construct trie 
    for (int i = 0; i < n; i++) {
        Insert(root, keys[i]);
        cout << keys[i] << "||" << Search(root, keys[i]) << endl;
    }
    
    Delete(root, "hero");
    cout << Search(root, "heroplane") << endl;

    return 0;
}