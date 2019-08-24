#include "bits/stdc++.h"
using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL) {}
} ListNode;

ListNode* mergeList(ListNode *list1, ListNode *list2) {
    if(list1 && list2) {
        ListNode *start, *res;
        if(list1->val <= list2->val) {
            start = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            start = new ListNode(list2->val);
            list2 = list2->next;
        }
        res = start;

        while(list1 != NULL && list2 != NULL) {
            ListNode *Listnode;
            if(list1->val <= list2->val) {
                Listnode = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                Listnode = new ListNode(list2->val);
                list2 = list2->next;
            }
            start->next = Listnode;
            start = start->next;
        }

        while(list1 != NULL) {
            ListNode *Listnode = new ListNode(list1->val);
            list1 = list1->next;
            start->next = Listnode;
            start = start->next;
        }

        while(list2 != NULL) {
            ListNode *Listnode = new ListNode(list2->val);
            list2 = list2->next;
            start->next = Listnode;
            start = start->next;
        }

        return res;
    } else if(list1) return list1;
    return list2;
}


int main(int argc, char const *argv[]) {
    
    return 0;
}
