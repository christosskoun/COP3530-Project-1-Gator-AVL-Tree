#pragma once
#include <string>

struct TreeNode{
    int value;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): value(x), left(nullptr), right(nullptr) {}

    //Helper functions to keep tree Balanced (AKA rotation functions)
    TreeNode * rotateLeft (TreeNode* node); //O(1)
    TreeNode *  rotateRight (TreeNode* node); //O(1)
    TreeNode *  rotateLR (TreeNode* node); //O(1)
    TreeNode *  rotateRL (TreeNode* node); //O(1)

    void insert(std::string name, int ID);
    void remove(int ID);
    void search(int ID); //searches for a Node with a specific ID
    void search(std::string name); //searches for a Node with a specific name
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(unsigned int n);
//TODO need a "traverse" function???? (would be forced to traverse entire tree so O(n)
};


TreeNode * TreeNode::rotateLeft(TreeNode *node) {
    TreeNode* grandchild=node->right->right;//was originally right->left from slides
    TreeNode* newParent=node->right;
    newParent->left=node;
    node->right=grandchild;
    return newParent;
}

TreeNode * TreeNode::rotateRight(TreeNode *node) {
    TreeNode* grandchild=node->left->left;
    TreeNode* newParent=node->left;
    newParent->left=grandchild;
    node->right=node;
    return newParent;
}

TreeNode * TreeNode::rotateLR(TreeNode *node) {
    rotateLR(node); //TODO pass in parameter nodes for rotations by reference?
    rotateRight(node);
}

TreeNode * TreeNode::rotateRL(TreeNode *node) {
    rotateRight(node);
    rotateLR(node);
}



void TreeNode::insert(std::string name, int ID) {
    //search for location to put Node in
    //actually put node in
    //if/else statements to take care of rotations

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

