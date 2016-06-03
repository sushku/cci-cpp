#include <iostream>
#include <vector>
#include <map>
#include "common.hpp"

using namespace std;

extern ListNode* createLinkedList(vector<int>);
extern void printLinkedList(ListNode*);

void removeDupsHashTable(ListNode* list) {
    if (list == NULL) return;
    ListNode* node = list;
    ListNode* prev = list;
    map<int, int> hm;
    while (node != NULL) {
        if (hm[node->val] == 1) {
            prev->next = node->next;
        }
        else {
            hm[node->val] = 1;
            prev = node;
        }
        node = node->next;
    }
}

void removeDupsInPlace(ListNode* list) {
    if (list == NULL) return;
    ListNode* node = list;
    while (node != NULL) {
        ListNode* runner = node->next;
        ListNode* prev = node;
        while (runner != NULL) {
            if (node->val == runner->val)
                prev->next = runner->next;
            else
                prev = runner;
            runner = runner->next;
        }
        node = node->next;
    }
}

int main() {
    int arrList[] = {9, 2, 9, 4, 5, 2, 3, 7, 8, 4, 6, 6, 2, 9, 1, 3};
    vector<int> vecList(arrList, arrList + (sizeof(arrList) / sizeof(arrList[0])));

    ListNode* list = createLinkedList(vecList);
    printLinkedList(list);

    //removeDupsHashTable(list);
    removeDupsInPlace(list);
    printLinkedList(list);

    return 0;
}
