#include <iostream>
#include <vector>
#include <stack>
#include "common.hpp"

using namespace std;

extern ListNode* createLinkedList(vector<int>);
extern void printLinkedList(ListNode*);

ListNode* sumListsBackward(ListNode* l1, ListNode* l2) {
    int sum = 0, carry = 0;
    ListNode* head = NULL;
    ListNode* prev = NULL;
    while(l1 != NULL || l2 != NULL) {
        sum = 0;
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        if(sum >= 10) {
            sum = sum % 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ListNode* node = new ListNode(sum);
        if(!head) {
            head = node;
        }
        else {
            prev->next = node;
        }
        prev = node;
    }
    if(carry) {
        prev->next = new ListNode(carry);
    }
    return head;
}

ListNode* sumListsForward(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2, sum;

    while (l1 != NULL) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2 != NULL) {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int digit = 0, carry = 0, v1 = 0, v2 = 0;
    while (s1.size() > 0 || s2.size() > 0) {
        v1 = 0;
        v2 = 0;
        if (s1.size() > 0) {
            v1 = s1.top();
            s1.pop();
        }
        if (s2.size() > 0) {
            v2 = s2.top();
            s2.pop();
        }
        digit = v1 + v2 + carry;
        if (digit >= 10) {
            digit = digit - 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        sum.push(digit);
    }
    if (carry > 0) sum.push(carry);

    ListNode* sumList;
    ListNode* prev;
    bool first = true;

    while (sum.size() > 0) {
        ListNode* node = new ListNode(sum.top());
        if (first) {
            sumList = node;
            first = false;
        }
        else {
            prev->next = node;
        }
        prev = node;
        sum.pop();
    }
    return sumList;
}

int main(int argc, char * argv[]) {
    int arr1[] = {2, 4, 3};
    vector<int> vec1(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    int arr2[] = {5, 6, 4};
    vector<int> vec2(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));

    ListNode* list1 = createLinkedList(vec1);
    ListNode* list2 = createLinkedList(vec2);
    printLinkedList(list1);
    printLinkedList(list2);
    ListNode* sum1= sumListsBackward(list1, list2);
    printLinkedList(sum1);

    int arr3[] = {2, 4, 3};
    vector<int> vec3(arr3, arr3 + (sizeof(arr3) / sizeof(arr3[0])));
    int arr4[] = {1, 0, 2, 4};
    vector<int> vec4(arr4, arr4 + (sizeof(arr4) / sizeof(arr4[0])));

    ListNode* list3 = createLinkedList(vec3);
    ListNode* list4 = createLinkedList(vec4);
    printLinkedList(list3);
    printLinkedList(list4);
    ListNode* sum2 = sumListsForward(list3, list4);
    printLinkedList(sum2);
    return 0;
}
