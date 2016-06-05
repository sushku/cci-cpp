#include <iostream>
#include <vector>
#include "common.hpp"

using namespace std;

extern ListNode* createLinkedList(vector<int>);
extern void printLinkedList(ListNode*);

int returnKthToLast(ListNode* list, int k) {
    ListNode* node = list;
    ListNode* runner = list;
    int i = 0;
    while (node != NULL) {
        if (i >= k)
            runner = runner->next;
        node = node->next;
        i++;
    }
    return runner->val;
}

int main() {
    int arrList[] = {9, 2, 9, 4, 5, 2, 3, 7, 8, 4, 6, 6, 2, 9, 1, 3};
    vector<int> vecList(arrList, arrList + (sizeof(arrList) / sizeof(arrList[0])));

    ListNode* list = createLinkedList(vecList);
    printLinkedList(list);

    cout << returnKthToLast(list, 1) << endl;
    return 0;
}
