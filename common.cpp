#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "common.hpp"

ListNode* createLinkedList(std::vector<int> vec) {
    int vsize = vec.size();
    if (vsize == 0) return NULL;
    int i = 0;
    ListNode* list = new ListNode(vec[i]);
    ListNode* prev = list;
    i++;
    while (i < vsize) {
        ListNode* node = new ListNode(vec[i]);
        prev->next = node;
        prev = node;
        i++;
    }
    return list;
}

void printLinkedList(ListNode* list) {
    if (list == NULL) return;
    ListNode* node = list;
    while (node != NULL) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "NULL" << std::endl;
    return;
}

TreeNode* createBinaryTree(std::vector<std::string> vec) {
    int vsize = vec.size();
    if (vsize == 0) return NULL;
    int i = 0;
    TreeNode* tree = new TreeNode(std::stoi(vec[i]));
    std::queue<TreeNode*> q;
    q.push(tree);
    i++;
    while (i < vsize) {
        int s = q.size();
        while (s > 0) {
            TreeNode* node = q.front();
            q.pop();
            if (vec[i] != "#") {
                TreeNode* left = new TreeNode(std::stoi(vec[i]));
                node->left = left;
                q.push(left);
            }
            i++;
            if (i >= vsize) break;
            if (vec[i] != "#") {
                TreeNode* right = new TreeNode(std::stoi(vec[i]));
                node->right = right;
                q.push(right);
            }
            i++;
            if (i >= vsize) break;
            s--;
        }
    }
    return tree;
}

void printBinaryTree(TreeNode* tree) {
    if (tree == NULL) return;
    std::queue<TreeNode*> q;
    q.push(tree);
    std::cout << tree->val << std::endl;
    while (q.size() > 0) {
        int s = q.size();
        while (s > 0) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left == NULL) {
                std::cout << "#  ";
            }
            else {
                std::cout << node->left->val << "  ";
                q.push(node->left);
            }
            if (node->right == NULL) {
                std::cout << "#  ";
            }
            else {
                std::cout << node->right->val << "  ";
                q.push(node->right);
            }
            s--;
        }
        std::cout << std::endl;
    }
    return;
}

