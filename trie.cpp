//License MIT 2016 Ahmad Retha
#include <iostream>
#include <string>
#include <vector>
#include "trie.hpp"

using namespace std;

/**
 * Prints out all the nodes/edges of the trie using depth first traversal (pre-order)
 *
 * @private
 * @param node A reference to the trie or a node of the trie
 */
void Trie::recPrint(struct Node * node)
{
    vector<struct Node>::iterator it;
    for (it = (*node).children.begin(); it != (*node).children.end(); ++it)
    {
        this->recPrint(&(*it));
    }
    if ((*node).value != '\0') {
        cout << "Value: " << (*node).value << " Id: " << (*node).id << " isWord? " << (*node).word << endl;
    }
}

/**
 * Constructor
 */
Trie::Trie()
{
    this->mTotal = 0;
    this->root.value = '\0';
    this->root.id = 0;
    this->root.word = false;
}

/**
 * Searches the trie for a given string. -1 or 1 mean a partial or exact word
 * match is found, while 0 means it did not match
 *
 * @param needle The pattern to look for in the trie
 * @return Returns 1 if the needle is a complete word in the trie, -1 if it
 * exists as a prefix of a word, or 0 if it doesn't exist in the trie
 */
int Trie::find(const string needle)
{
    unsigned int i = 0;
    unsigned int m = needle.length();
    struct Node * currNode = &this->root;
    vector<struct Node>::iterator it;
    bool found;

    for (i = 0; i <= m; i++)
    {
        if (i == m) {
            if ((* currNode).word)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        found = false;
        for (it = (* currNode).children.begin(); it != (* currNode).children.end(); ++it)
        {
            if ((*it).value == needle[i])
            {
                currNode = &(*it);
                found = true;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 0;
}

/**
 * Insert words into the trie
 *
 * @param word A word
 */
void Trie::insert(const string word)
{
    unsigned int i, m = word.length();
    struct Node * currNode = &this->root;

    vector<struct Node>::iterator it;
    bool found;
    for (i = 0; i < m; i++)
    {
        //check to see if char exists as child of current node
        found = false;
        for (it = (* currNode).children.begin(); it != (* currNode).children.end(); ++it) {
            if ((*it).value == word[i]) {
                found = true;
                if (i == m - 1) {
                    (*it).word = true;
                }
                currNode = &(*it);
                break;
            }
        }

        //if the char does not already exist we create it as a new child node and set it as currentNode
        if (!found) {
            this->mTotal++;

            struct Node newNode;
            newNode.value = word[i];
            newNode.id = this->mTotal;
            newNode.word = (i == m - 1);

            (* currNode).children.push_back(newNode);
            currNode = &((* currNode).children.back());
        }
    }
}

/**
 * Prints out the items in the trie in depth first pre-order
 */
void Trie::print()
{
    this->recPrint(&this->root);
}
