#include "bits/stdc++.h"
using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL) {}
} ListNode;

bool cycle(ListNode *head) {
    unordered_set<ListNode*> pos;
    while(head) {
        if(pos.find(head) != pos.end()) return true;
        head = head->next;
    }
    return false;
}