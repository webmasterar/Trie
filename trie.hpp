//License MIT 2016 Ahmad Retha
#ifndef __TRIE__
#define __TRIE__

#include <string>
#include <vector>

using namespace std;

struct Node
{
    char value;
    unsigned int id;
    vector<struct Node> children;
    bool word;
};

class Trie
{
private:
    struct Node root;
    unsigned int mTotal;
    void recPrint(struct Node * node);

public:
        Trie();
        int find(const string pattern);
        void insert(const string pattern);
        void print();
};

#endif
