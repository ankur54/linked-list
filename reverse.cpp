#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

ListNode* reverse(ListNode* head) {
    ListNode* curr = head;
    ListNode* res = NULL;
    
    while(curr) {
        ListNode* nxt = curr->next;
        curr->next = res;
        res = curr;
        curr = nxt;
    }

    return res;
}