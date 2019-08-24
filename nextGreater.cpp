#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

vector<int> nextGreater(ListNode *head) {
    vector<int> nodes;

    while(head != NULL) {
        nodes.push_back(head->val);
        head = head->next;
    }

    int n = nodes.size();
    vector<int> res(n, 0);
    stack<int> store;
    store.push(nodes[n-1]);
    for(int i = n-2; i >= 0; i--) {
        while(!store.empty() && nodes[i] >= store.top()) store.pop();
        if(!store.empty()) res[i] = store.top();
        store.push(nodes[i]);
    }
    return res;
}