/*
 * trie.cpp
 *
 * Method definitions for the trie class.
 *
 * Author: <your name here>
 */

#include "trie.h"

trie::trie() {
    root = new node();
}

trie::~trie() {
    destroy(root);
}

void trie::insert(const string &s) {
    if (root->is_terminal) {
        root->is_terminal = false;
    }
    node* currNode = root;
    for (int i = 0; i < s.length() - 1; i++) {
        if (currNode->children[(int)s[i] - 61] != nullptr) {
            currNode = currNode->children[s[i] - 61];
        }
        else {
            currNode->children[(int)s[i] - 61] = new node();
            currNode = currNode->children[s[i] - 61];

        }
    }
    if (currNode->children[(int)s[s.length() - 1] - 61]) {

    }
}

bool trie::contains(const string &s) {
    return true;
}

bool trie::is_prefix(const string &s) {
    return true;
}

void trie::extend(const string &prefix, vector<string> &result) {
    return;
}

void trie::destroy(node* root) {
    if (root == nullptr) {
        return;
    }

    if (!root->is_terminal) {
        for (int i = 0; i < 26; i++) {
                destroy(root->children[i]);
        }
    }
    delete root;
}