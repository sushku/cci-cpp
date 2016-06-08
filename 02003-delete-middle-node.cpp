#include <iostream>
#include <vector>
#include "common.hpp"

using namespace std;

extern ListNode* createLinkedList(vector<int>);
extern void printLinkedList(ListNode*);

void deleteMiddleNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main() {
    int arrList[] = {9, 2, 9, 4, 5, 2, 3, 7, 8, 4, 6, 6, 2, 9, 1, 3};
    vector<int> vecList(arrList, arrList + (sizeof(arrList) / sizeof(arrList[0])));

    ListNode* list = createLinkedList(vecList);
    printLinkedList(list);

    ListNode* node = list->next->next->next->next;

    deleteMiddleNode(node);

    printLinkedList(list);
    return 0;
}
