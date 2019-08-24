#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

ListNode* rotateRight(ListNode* head, int k) {
    int n = 0, flag = 0;
    ListNode* start, *end, *temp;
    temp = start = head;
    while(temp && temp->next) n++, temp = temp->next, flag = 1;
    if(flag) n++; 
    end = temp;
    end->next = start;
    k = k%n;
    int i = 1;
    while(i < n-k && start) start = start->next, i++;
    head = start->next;
    start->next = NULL;
    return head;
}