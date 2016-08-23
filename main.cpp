//License MIT 2016 Ahmad Retha
#include <iostream>
#include "trie.hpp"

int main()
{
    Trie tr;
    cout << "Inserting 'he'" << endl;
    tr.insert("he");
    tr.print();
    cout << "Inserting 'she'" << endl;
    tr.insert("she");
    tr.print();
    cout << "Inserting 'his'" << endl;
    tr.insert("his");
    tr.print();
    cout << "Inserting 'hers'" << endl;
    tr.insert("hers");
    tr.print();

    return 0;
}
