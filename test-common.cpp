#include <iostream>
#include <vector>
#include <string>
#include "common.hpp"

using namespace std;

extern TreeNode* createBinaryTree(vector<string>);
extern void printBinaryTree(TreeNode*);
extern ListNode* createLinkedList(vector<int>);
extern void printLinkedList(ListNode*);

int main() {
    string arrTree[] = {"1", "2", "3", "4", "5"};
    vector<string> vecTree(arrTree, arrTree + (sizeof(arrTree) / sizeof(arrTree[0])));

    TreeNode* tree = createBinaryTree(vecTree);
    printBinaryTree(tree);

    int arrList[] = {1, 2, 3, 4, 5};
    vector<int> vecList(arrList, arrList + (sizeof(arrList) / sizeof(arrList[0])));

    ListNode* list = createLinkedList(vecList);
    printLinkedList(list);
    return 0;
}
