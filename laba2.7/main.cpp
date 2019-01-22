#include <iostream>
#include "include/BinSearchTree.h"

int main() {

    BinTree * tree = new_BinTree(18);

    insert_rand_BSTree(tree,20);

    print_labs_BSTree(tree);
    return 0;
}