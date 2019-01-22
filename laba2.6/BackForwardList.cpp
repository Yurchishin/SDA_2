#include "BackForwardList.h"
#include <cassert>
#include <iostream>

using namespace std;

List List_Contstr() {
    List list{
            .head = NULL,
            .tail = NULL
    };
    return list;
}

ListNode * new_BackForwardListNode(double value) {
    ListNode * node = (ListNode *)malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void free_BackForwardListNode(ListNode * self) {
    assert(NULL != self);
    free(self);
}

void addFirst_BackForwardList(List * self, double value) {
    ListNode * node = new_BackForwardListNode(value);

    if(self->head == NULL){
        self->head = node;
        self->tail = self->head;
    } else{
        node->next = self->head;
        self->head->prev = node;
        self->head = node;
    }
}

void addLast_BackForwardList(List * self, double value) {
    ListNode * node = new_BackForwardListNode(value);
    if (self->head == NULL) {
        self->head = node;
        self->tail = node;
    }
    else {
        ListNode * cur = self->tail;
        node->prev = self->tail;
        cur->next = node;
        self->tail = node;
    }
}

void insert_BackForwardList(List * self, int position, double value) {
    assert(position >= 0);
    if (position == 0) {
        addFirst_BackForwardList(self, value);
        return;
    }
    ListNode * node = new_BackForwardListNode(value);
    int i = 0;
    ListNode * cur = self->head;
    while (cur->next != NULL && i != position - 1) {
        cur = cur->next;
        i++;
    }
    assert(i == position - 1);
    node->prev = cur;
    node->next = cur->next;
    cur->next->prev = node;
    cur->next = node;
}

double removeFirst_BackForwardList(List * self) {
    double value;
    if(self->tail == self->head){
        value = self->head->value;
        free_BackForwardListNode(self->head);
        return  value;
    }
    ListNode * node = self->head;
    if (node == NULL) assert(0);
    value = node->value;
    self->head = node->next;
    self->head->prev = NULL;
    free_BackForwardListNode(node);
    return value;
}

double removeLast_BackForwardList(List * self) {
    double value;
    if(self->tail == self->head) {
        value = removeFirst_BackForwardList(self);
        return value;
    }
    ListNode * cur = self->tail->prev;
    if (cur == NULL) assert(0);
    if (cur->next == NULL) {
        return removeFirst_BackForwardList(self);
    }

    value = self->tail->value;
    free_BackForwardListNode(self->tail);
    cur->next = NULL;
    self->tail = cur;
    return value;
}

double removeAt_BackForwardList(List * self, int position) {
    assert(position >= 0);
    if (position == 0) {
        return removeFirst_BackForwardList(self);
    }
    int i = 0;
    ListNode * cur = self->head;
    while (cur->next->next != NULL && i != position - 1) {
        i += 1;
        cur = cur->next;
    }
    assert(i == position - 1);
    ListNode * node = cur->next;
    double value = node->value;
    cur->next = node->next;
    node->next->prev = cur;
    free_BackForwardListNode(node);
    return value;
}

void print_BackForwardList(List * self) {
    ListNode *cur = self->head;
    while (cur != NULL) {
        cout << cur->value << ' ';
        cur = cur->next;
    }
    cout << endl;
}

int count_BackForwardList(List * self) {
    int count = 0;
    ListNode * cur = self->head;
    while (cur != NULL) {
        count += 1;
        cur = cur->next;
    }
    return count;
}

double elementAt_BackForwardList(List * self, int position) {
    assert(self != NULL);
    assert(self->head != NULL);
    assert(position >= 0);
    int i = 0;
    ListNode * cur = self->head;
    while (cur->next != NULL && i != position) {
        i++;
        cur = cur->next;
    }
    assert(i == position);
    return cur->value;
}

int sum_BackForwardList(List * self)
{
    int sum = 0;
    ListNode * cur = self->head;
    while (cur != NULL) {
        sum += cur->value;
        cur = cur->next;
    }
    return sum;
}
