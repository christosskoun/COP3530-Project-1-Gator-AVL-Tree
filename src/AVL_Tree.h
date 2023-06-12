#pragma once
#include <string>
struct AVLTree {
    AVLTree* head;
    struct TreeNode {
        int ID;
        int height;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int userID) : ID(userID), left(nullptr), right(nullptr), height(0) {} //constructor

        //Helper functions to keep tree Balanced (AKA rotation functions)
        TreeNode *rotateLeft(TreeNode *node); //O(1)
        TreeNode *rotateRight(TreeNode *node); //O(1)
        TreeNode *rotateLR(TreeNode *node); //O(1)
        TreeNode *rotateRL(TreeNode *node); //O(1)

        void insert(std::string name, int ID);

        void remove(int ID);

        void search(int ID); //searches for a Node with a specific ID
        void search(std::string name); //searches for a Node with a specific name
        void printInorder();

        void printPreorder();

        void printPostorder();

        void printLevelCount();

        void removeInorder(int n);
//TODO need a "traverse" function???? (would be forced to traverse entire tree so O(n)
    };
};

AVLTree::TreeNode *AVLTree::TreeNode::rotateLeft(TreeNode *node) {
    TreeNode* grandchild=node->right->right;//TODO was originally right->left from slides (look at stepik)
    TreeNode* newParent=node->right;
    newParent->left=node;
    node->right=grandchild;
    return newParent;
}

AVLTree::TreeNode *AVLTree::TreeNode::rotateRight(TreeNode *node) {
    TreeNode* grandchild=node->left->left;
    TreeNode* newParent=node->left;
    newParent->left=grandchild;
    node->right=node;
    return newParent;
}

AVLTree::TreeNode *AVLTree::TreeNode::rotateLR(TreeNode *node) {
    rotateLeft(node); //TODO pass in parameter nodes for rotations by reference?
    rotateRight(node);
}

AVLTree::TreeNode *AVLTree::TreeNode::rotateRL(TreeNode *node) {
    rotateRight(node);
    rotateLeft(node);
}

void AVLTree::TreeNode::insert(std::string name, int ID) {
    //search for location to put Node in
    //actually put node in
    //if/else statements to take care of rotations

}

void AVLTree::TreeNode::remove(int ID) {

}

void AVLTree::TreeNode::search(int ID) {

}

void AVLTree::TreeNode::search(std::string name) {

}

void AVLTree::TreeNode::printInorder() {

}

void AVLTree::TreeNode::printPreorder() {

}

void AVLTree::TreeNode::printPostorder() {

}

void AVLTree::TreeNode::printLevelCount() {

}

void AVLTree::TreeNode::removeInorder(int n) {

}

