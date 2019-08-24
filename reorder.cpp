#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

ListNode* mid(ListNode* head){
    if(!head)
        return head;
    ListNode *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head){
    if(head==NULL || head->next == NULL)
        return head;
    ListNode *r = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return r;
}

ListNode* reorder(ListNode* head) {
    if( !head || !head->next) return ;
        
    ListNode* a = head;
    ListNode* b = reverse(mid(head));
    
    while(b->next){
        ListNode* temp = a->next;
        ListNode* temp1 = b->next;
        a->next = b;
        b->next = temp;
        a = temp;
        b = temp1;
    }
}