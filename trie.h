/*
 * trie.h
 *
 * Declaration of the trie class.
 * 
 * Author: <your name here>
 */

#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>

using namespace std;

class trie {
public:
    trie();
    ~trie();
    trie(const trie& OTHER) = delete;
    trie& operator=(const trie& OTHER) = delete;
    void insert(const string &s);
    bool contains(const string &s);
    bool is_prefix(const string &s);
    void extend(const string &prefix, vector<string> &result);

private:
    class node {
        public:
            node() {
                for (int i = 0; i < 26; i++) {
                    children[i] = nullptr;
                }
                is_terminal = false;
            }
            bool is_terminal;
            node* children[26];

    };
    node* root;
    size_t size;

    void destroy(node* root);
};

#endif
