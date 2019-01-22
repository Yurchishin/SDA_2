#ifndef BINTREE_H
#define BINTREE_H

struct  BinTree{
    int key;
    BinTree * left;
    BinTree * right;
};

BinTree * new_BinTree(int);

void free_BinTree(BinTree * self);

#endif //BINTREE_H
