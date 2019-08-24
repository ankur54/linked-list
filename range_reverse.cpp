#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

ListNode* reverse(ListNode* head, int m, int n) {
    if(!head) return head;
    ListNode* curr = head;
    ListNode* res = NULL;
    int i = 1;
    while(i < m-1) i++, curr = curr->next;
    ListNode* start = curr;

    if(m > 1) {
        ListNode* end = curr;
        start = curr = curr->next;

        while(curr && ++i <= n) {
            ListNode* nxt = curr->next;
            curr->next = res;
            res = curr;
            curr = nxt;
        }
        start->next = curr;
        end->next = res;
    } else {
        while(curr && i++ <= n) {
            ListNode* nxt = curr->next;
            curr->next = res;
            res = curr;
            curr = nxt;
        }
        start->next = curr;
        head = res;
    }
    return head;
}