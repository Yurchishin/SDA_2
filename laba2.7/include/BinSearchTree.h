#ifndef BINSEARCHTREE_BINSEARCHTREE_H
#define BINSEARCHTREE_BINSEARCHTREE_H
#include "../include/BinTree.h"

struct BSTree{
    BinTree * root;
};
//
//BinTree *new_BSTree(int i);
//
//void free_BSTree(BinTree*,int);

void insert_BSTree(BinTree*& self, int key);

void print_Format_BSTree(BinTree*,int,bool);

void print_inOrder_BSTree(BinTree*);

void insert_rand_BSTree(BinTree*,int);

void print_labs_BSTree(BinTree*);

#endif //BINSEARCHTREE_BINSEARCHTREE_H
