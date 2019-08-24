#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

ListNode* intersect(ListNode* list1, ListNode* list2) {
    unordered_set<ListNode*> store;
    while(list1) store.insert(list1), list1 = list1->next;
    while(list2) {
        if(store.find(list2) != store.end()) return list2;
        list2 = list2->next;
    }
    return NULL;
}