#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

ListNode* partition(ListNode* head, int x) {
    ListNode* temp = head;
    vector<int> smaller, greater;
    while(temp) {
        if(temp->val < x) smaller.push_back(temp->val); 
        else greater.push_back(temp->val);
        temp = temp->next;
    }
    if(smaller.size() == 0) return head;
    ListNode* start = new ListNode(smaller[0]); 
    temp = start;
    
    for(int i = 1; i < smaller.size(); i++) {
        ListNode* node = new ListNode(smaller[i]);
        temp->next = node;
        temp = temp->next;
    } 

    for(auto k:greater) {
        ListNode* node = new ListNode(k);
        temp->next = node;
        temp = temp->next;
    } 
    return start;
}