#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "article.hpp"
#include "btree.hpp"

using namespace std;

int main(int argc, char** argv)
{
    int id = atoi(argv[1]);
    BTree btree;
    Article_t a;
    FILE* indexFile = fopen("test/primaryindex.block", "rb");

    if (indexFile != NULL) {
        auto result = btree.getArticle(id, &a, indexFile);

        if (result.first) {
            cout << a.toString();
            cout << "\n\nNumber of block read in BTree Index to find the record: " << result.second;
            cout << "\n\nTotal number of blocks in primary index file: " << ((ftell(indexFile) / sizeof(AbstractBlock_t)) - 1);
        } else {
            cout << "Record not found.";
        }
    }
    else {
        cout << "There isn't a primary index file.\n";
    }

    return 0;
}