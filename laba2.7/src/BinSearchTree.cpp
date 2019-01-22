#include "../include/BinSearchTree.h"
#include <iostream>

using namespace std;

void insert_BSTree(BinTree*& node, int key) {
    if(node == NULL){
        node = new_BinTree(key);
        return;
    }
    if(node->key == key) return;
    if(node->key > key) insert_BSTree(node->right,key);
    else insert_BSTree(node->left,key);
}

void f(int i, int n){
    while(i < n){
        cout << "..";
        i++;
    }
}

void print_inOrder_BSTree(BinTree* node){

    if(node->left != NULL) {
        print_inOrder_BSTree(node->left);
    }

    cout << node->key << ' ';

    if(node->right != NULL) {
        print_inOrder_BSTree(node->right);
    }

}

void print_Format_BSTree(BinTree* node, int n,bool flag){
    f(0,n);
    cout << node->key << endl;

    if(node->left != NULL) {
        print_Format_BSTree(node->left, n+1,false);
    }
    if(node->left == NULL){
        f(0,n);
        cout << "(null)" << endl;
    }

    if(node->right != NULL) {
        print_Format_BSTree(node->right, n+1,false);
    }
}

void insert_rand_BSTree(BinTree* node, int size){
    for(int i = 0; i < size; i++){
        insert_BSTree(node,rand() % 15 + 5);
    }
}

BinTree* findNum(BinTree* node){


    if(node->key < node->left->key){
        if(node->key < node->right->key){
            return node;
        }
    }
    if(node->left->key < node->key){
        if(node->left->key < node->right->key){
            return node->left;
        }
    }
    if(node->right->key < node->key){
        if(node->right->key < node->left->key){
            return node->right;
        }
    }


    if(node->key > node->left->key){
        if(node->key > node->right->key){
            return node;
        }
    }
    if(node->left->key > node->key){
        if(node->left->key > node->right->key){
            return node->left;
        }
    }
    if(node->right->key > node->key){
        if(node->right->key > node->left->key){
            return node->right;
        }
    }


    if(node->key == node->left->key == node->right->key){
        return node->right;
    }
}

void print_labs_BSTree(BinTree* node){

    if(node->right != NULL) {
        print_labs_BSTree(node->right);
    }

    cout << node->key << ' ';

    if(node->left != NULL) {
        print_labs_BSTree(node->left);
    }

}