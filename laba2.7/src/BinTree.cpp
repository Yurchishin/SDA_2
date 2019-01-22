#include "../include/BinTree.h"
#include <iostream>

using namespace std;

BinTree * new_BinTree(int key){
    BinTree * tree = (BinTree*)malloc(sizeof(BinTree*));
    tree->key = key;
    tree->left = NULL;
    tree->right = NULL;
    return  tree;
}

void free_BinTree(BinTree * self){
    free(self);
}