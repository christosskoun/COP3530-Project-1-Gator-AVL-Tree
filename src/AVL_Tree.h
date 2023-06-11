#pragma once
#include <string>

struct TreeNode{
    int value;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): value(x), left(nullptr), right(nullptr) {}
    void insert(std::string name, int ID);
    void remove(int ID);
    void search(int ID); //searches for a Node with a specific ID
    void search(std::string name); //searches for a Node with a specific name
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(unsigned int n);

};

void TreeNode::insert(std::string name, int ID) {

}

void TreeNode::remove(int ID) {

}

void TreeNode::search(int ID) {

}

void TreeNode::search(std::string name) {

}

void TreeNode::printInorder() {

}

void TreeNode::printPreorder() {

}

void TreeNode::printPostorder() {

}

void TreeNode::printLevelCount() {

}

void TreeNode::removeInorder(unsigned int n) {

}
