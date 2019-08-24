#include "bits/stdc++.h"
using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {}
} ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            if(curr->next && curr->val != curr->next->val) {
                prev = curr;
                curr = curr->next;
            } else if(curr->next) {
                while(curr && curr->next && curr->val == curr->next->val) curr = curr->next;

                if(curr->next) {
                    curr = curr->next;
                    if(!curr->next || curr->val != curr->next->val) {
                        if(prev) prev->next = curr;
                        else head = curr;
                    }
                } else {
                    if(prev) prev->next = NULL;
                    else head = NULL;
                }
            } else curr = curr->next;
        }

        return head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().deleteDuplicates(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}