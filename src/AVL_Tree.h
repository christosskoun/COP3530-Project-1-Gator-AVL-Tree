#pragma once
#include <string>
struct AVLTree {

    struct TreeNode {
        int ID;
        std::string name;
        int height;
        TreeNode *left;
        TreeNode *right;
        TreeNode(std::string userName, int userID) :  name(userName), ID(userID), left(nullptr), right(nullptr), height(0) {} //constructor
    };

    TreeNode* root;
    float ratio;

    AVLTree() : root(nullptr), ratio(0.0) {} //constructor

    //Helper functions to keep tree Balanced (AKA rotation functions)
    TreeNode* rotateLeft(TreeNode* node); //O(1)
    TreeNode* rotateRight(TreeNode* node); //O(1)
    TreeNode* rotateLR(TreeNode* node); //O(1)
    TreeNode* rotateRL(TreeNode* node); //O(1)
    TreeNode* rotations(TreeNode* node);

    void insert(std::string name, int ID);
    TreeNode * insertHelper(TreeNode* root, std::string name, int ID);

    void remove(int ID);

    void search(int ID); //searches for a Node with a specific ID

    void search(std::string name); //searches for a Node with a specific name

    void printInorder();

    void printPreorder();

    void printPostorder();

    void printLevelCount();

    void removeInorder(int n);

};

AVLTree::TreeNode* AVLTree::rotateLeft(TreeNode *node) {//right-right case
    TreeNode* newParent=node->right;
    TreeNode* grandchild=node->right->left;
    newParent->left=node;
    node->right=grandchild;
    return newParent;
}

AVLTree::TreeNode *AVLTree::rotateRight(TreeNode *node) {//left-left case
    TreeNode* newParent=node->left;
    TreeNode* grandchild=node->left->right;
    newParent->right=node;
    node->left=grandchild;
    return newParent;
}

AVLTree::TreeNode *AVLTree::rotateLR(TreeNode *node) {//left-right case
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

AVLTree::TreeNode *AVLTree::rotateRL(TreeNode *node) {//right-left case
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

AVLTree::TreeNode *AVLTree::rotations(AVLTree::TreeNode *node) {//TODO fix this
    //if(tree is right heavy){
        //if(tree's right subtree is left heavy){
            //rotateRL()
            //update height}
        //else{
            //rotateLeft()
            //update height}
   //}

    //else if(tree is left heavy ){
        //if(tree's left subtree is right heavy){
            //rotateLR();
            //update height;}
        //else{
            //rotateRight;
            //update height}
    //}
    //TODO dont forget to update node heights
 }

void AVLTree::insert(std::string name, int ID) {//TODO fix this
    if (root == nullptr)
        root=new TreeNode(name,ID);

    else if(ID<root->ID)
        root->left= insertHelper(this->root->left, name, ID);

    else
        root->right= insertHelper(this->root->right, name, ID);

    //rotations();
}

AVLTree::TreeNode * AVLTree::insertHelper(AVLTree::TreeNode *root, std::string name, int ID) {//TODO fix this
    if (root == nullptr)
        root=new TreeNode(name,ID);

    else if(ID<root->ID)
        root->left= insertHelper(this->root->left, name, ID);

    else
        root->right= insertHelper(this->root->right, name, ID);

    //rotations();
}

void AVLTree::remove(int ID) {

}

void AVLTree::search(int ID) {
    //Search for the student with the specified ID from the tree.
    //If the ID was found, print out their NAME.
    //If the ID does not exist within the tree, print “unsuccessful”.

}

void AVLTree::search(std::string name) {
    //Search for the student with the specified name, NAME in the tree.
    //If the student name was found, print the associated ID.
    //If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
    //If the name does not exist within the tree, print “unsuccessful”.
    //NAME identifier will be surrounded by double quotes for parsing, e.g. "Josh Smith".
}

void AVLTree::printInorder() {
    //Print out a comma separated inorder traversal of the names in the tree.

}

void AVLTree::printPreorder() {
    //Print out a comma separated preorder traversal of the names in the tree.

}

void AVLTree::printPostorder() {
    //Print out a comma separated postorder traversal of the names in the tree.

}

void AVLTree::printLevelCount() {
    //Prints the number of levels that exist in the tree.
    //Prints 0 if the head of the tree is null. For example, the tree in Fig. 1 has 4 levels.
}

void AVLTree::removeInorder(int n) {
    //Remove the Nth GatorID from the inorder traversal of the tree (N = 0 for the first item, etc).
    //If removal is successful, print “successful”.
    //[Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit]
    //If the Nth GatorID does not exist within the tree, print “unsuccessful”.
}