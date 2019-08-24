#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} Node;

Node* mergeList(Node *list1, Node *list2) {
    Node *start, *res;

    if(list1 && list2) {
        int d = (list1->val + list2->val)%10;
        int carry = (list1->val + list2->val)/10;
        start = new Node(d);
        list1 = list1->next;
        list2 = list2->next;
        res = start;

        while(list1 != NULL && list2 != NULL) {
            int d = (list1->val + list2->val)%10;
            int carry = (list1->val + list2->val)/10;
            start = new Node(d);
            list1 = list1->next;
            list2 = list2->next;
        }

        while(list1 != NULL) {
            Node *node = new Node(list1->val);
            start->next = node;
            start = start->next;
            list1 = list1->next;
        }

        while(list2 != NULL) {
            Node *node = new Node(list2->val);
            start->next = node;
            start = start->next;
            list2 = list2->next;
        }
    } 
    else if(list2) return list2;
    else return list1;

    return res;
}


int main(int argc, char const *argv[]) {
    
    return 0;
}
