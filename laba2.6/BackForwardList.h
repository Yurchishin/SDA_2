#ifndef UNCONNECTEDLIST_LIST_H
#define UNCONNECTEDLIST_LIST_H

#include <cstdlib>
#include <cassert>

    struct ListNode {
        double value;
        ListNode *next;
        ListNode *prev;
    };

    struct List {
        ListNode *head;
        ListNode *tail;
    };

    List List_Contstr();

    ListNode * new_BackForwardListNode(double);

    void free_BackForwardListNode(ListNode*);

    void addFirst_BackForwardList(List*,double);

    void addLast_BackForwardList(List*,double);

    void insert_BackForwardList(List*,int,double);


    double removeFirst_BackForwardList(List*);

    double removeLast_BackForwardList(List*);

    double removeAt_BackForwardList(List*,int);


    void print_BackForwardList(List*);

    int count_BackForwardList(List*);

    double elementAt_BackForwardList(List*,int);

    int sum_BackForwardList(List*);

#endif
