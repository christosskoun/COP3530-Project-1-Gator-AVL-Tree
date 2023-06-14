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

    int getHeight(AVLTree::TreeNode* node);

    //Helper functions to keep tree Balanced (AKA rotation functions)
    TreeNode* rotateLeft(TreeNode* node); //O(1)
    TreeNode* rotateRight(TreeNode* node); //O(1)
    TreeNode* rotateLR(TreeNode* node); //O(1)
    TreeNode* rotateRL(TreeNode* node); //O(1)
    TreeNode* rotations(TreeNode* node);

    void insert(std::string name, int ID);
    TreeNode * insertHelper(TreeNode* root, std::string name, int ID);

    void remove(int ID);
    TreeNode * removeHelper(TreeNode* root, int ID);


    void search(int ID); //searches for a Node with a specific ID

    void search(std::string name); //searches for a Node with a specific name

    void printInorder();
    void printInorderHelper(TreeNode* node, bool& isFirstNode);

    void printPreorder();
    void printPreorderHelper(TreeNode* node, bool& isFirstNode);

    void printPostorder();
    void printPostorderHelper(TreeNode* node, bool& isFirstNode);

    void printLevelCount();
    void printLevelCountHelper();

    void removeInorder(int n);
    void removeInorderHelper(int n, int& count, TreeNode* node);
};

int AVLTree::getHeight(AVLTree::TreeNode *node) {
    if (node == nullptr)
        return -1;
    return node->height;
}

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

AVLTree::TreeNode* AVLTree::rotations(AVLTree::TreeNode* node) {
    if (ratio == -2) { // Tree is "right-heavy"
        if (getHeight(node->right->left) - getHeight(node->right->right) ==1) { // Right subtree is "left-heavy"
            node = rotateRL(node);
            node->left->height--;
            node->height++;

            //update heights
            node->height++;
            node->right--;
            node->left-=2;
        }
        else if (getHeight(node->right->left) - getHeight(node->right->right) ==-1) {
            node = rotateLeft(node);

            //update heights
            node->left->height-=2;
        }
    }
    else if (ratio == 2) { // Tree is "left-heavy"
        if (getHeight(node->left->left) - getHeight(node->left->right) ==-1) { // Left subtree is "right-heavy"
            node = rotateLR(node);

            //update heights
            node->height++;
            node->left->height--;
            node->right-=2;
        }
        else if(getHeight(node->left->left) - getHeight(node->left->right) ==1) {
            node = rotateRight(node);

            //update heights
            node->right-=2;
        }
    }

    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1; // Update height of the current node

    this->ratio= getHeight(this->root->left)- getHeight(this->root->right);

    return node;
}

void AVLTree::insert(std::string name, int ID) {
    if (this->root== nullptr) {
        std::cout<<"successful"<<std::endl;
        this->root = new TreeNode(name, ID);
    }
    else
        this->root=insertHelper(this->root, name, ID);
}

AVLTree::TreeNode * AVLTree::insertHelper(AVLTree::TreeNode* node, std::string name, int ID) {
    if (node == nullptr) {//base case for recursion
        std::cout<<"successful"<<std::endl;
        return node = new TreeNode(name, ID);
    }

    else if (ID==node->ID)
        std::cout<<"unsuccessful"<<std::endl; //and nothing else will happen because duplicate IDs are not allowed!

    else if(ID<node->ID)
        node->left= insertHelper(node->left, name, ID);

    else if (ID>node->ID)
        node->right= insertHelper(node->right, name, ID);

    node->height=std::max(getHeight(node->left), getHeight(node->right))+1;

    this->ratio= getHeight(this->root->left)- getHeight(this->root->right);
    node=rotations(node);

    return node;
}

void AVLTree::remove(int ID) {
    if (this->root== nullptr)
        std::cout<<"unsuccessful"<<std::endl; //can't remove if nothing there
    else
        this->root=removeHelper(this->root, ID);
}

AVLTree::TreeNode * AVLTree::removeHelper(AVLTree::TreeNode* node, int ID) {
    if(ID == node->ID&&ID==this->root->ID){//base case for recursion
        delete node; //and nothing else will happen because duplicate IDs are not allowed!
        node= nullptr;
        this->root= nullptr;//and nothing else will happen because duplicate IDs are not allowed!
        std::cout << "successful" << std::endl;
    }

    else if (ID == node->ID&&ID!=this->root->ID) {//base case for recursion
        delete node; //and nothing else will happen because duplicate IDs are not allowed!
        node= nullptr;



        //TODO fix this (account for how many children)

        std::cout << "successful" << std::endl;
    }
    else if (ID < node->ID)
        node->left = removeHelper(node->left, ID);

    else if (ID > node->ID)
        node->right = removeHelper(node->right, ID);

    if(node!= nullptr)
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

    if (this->root != nullptr) {
        this->ratio = getHeight(this->root->left) - getHeight(this->root->right);
        node = rotations(node);
    }

    return node;
}

void AVLTree::search(int ID) {
    //Search for the student with the specified ID from the tree.
    //If the ID was found, print out their NAME.
    //If the ID does not exist within the tree, print “unsuccessful”.
}

void AVLTree::search(std::string name) {
    //traverse tree
    //Search for the student with the specified name, NAME in the tree.
    //If the student name was found, print the associated ID.
    //If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
    //If the name does not exist within the tree, print “unsuccessful”.
    //NAME identifier will be surrounded by double quotes for parsing, e.g. "Josh Smith".
}

void AVLTree::printInorder() {
    bool isFirstNode = true;
    printInorderHelper(this->root, isFirstNode);
    std::cout << std::endl; //so next input is placed on the next line
}

void AVLTree::printInorderHelper(TreeNode* node, bool& isFirstNode) {
    if (node == nullptr)
        return;

    printInorderHelper(node->left, isFirstNode);

    if (isFirstNode) {//can't do last node because we don't know when that'll be so we do formatting based off of if it's the first node
        std::cout << node->name;
        isFirstNode = false;
    }

    else
        std::cout << ", " << node->name;

    printInorderHelper(node->right, isFirstNode);
}

void AVLTree::printPreorder() {
    bool isFirstNode = true;
    printPreorderHelper(this->root, isFirstNode);
    std::cout << std::endl; //so next input is placed on the next line
}

void AVLTree::printPreorderHelper(TreeNode *node, bool &isFirstNode) {
    if (node == nullptr)
        return;

    if (isFirstNode) {//can't do last node because we don't know when that'll be so we do formatting based off of if it's the first node
        std::cout << node->name;
        isFirstNode = false;
    }

    else
        std::cout << ", " << node->name;

    printPreorderHelper(node->left, isFirstNode);

    printPreorderHelper(node->right, isFirstNode);
}

void AVLTree::printPostorder() {
    bool isFirstNode = true;
    printPostorderHelper(this->root, isFirstNode);
    std::cout << std::endl; //so next input is placed on the next line
}

void AVLTree::printPostorderHelper(TreeNode *node, bool &isFirstNode) {
    if (node == nullptr)
        return;

    printPostorderHelper(node->left, isFirstNode);

    printPostorderHelper(node->right, isFirstNode);

    if (isFirstNode) {//can't do last node because we don't know when that'll be so we do formatting based off of if it's the first node
        std::cout << node->name;
        isFirstNode = false;
    }

    else
        std::cout << ", " << node->name;
}

void AVLTree::printLevelCount() {
    //Prints the number of levels that exist in the tree.
    //Prints 0 if the head of the tree is null. For example, the tree in Fig. 1 has 4 levels.
}

void AVLTree::printLevelCountHelper() {

}


void AVLTree::removeInorder(int n) {
    if (this->root == nullptr)
        std::cout << "unsuccessful" << std::endl;

    int count=0;
    removeInorderHelper(n,count, this->root);

    //Remove the Nth GatorID from the inorder traversal of the tree (N = 0 for the first item, etc).
    //If removal is successful, print “successful”.
    //[Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit]
    //If the Nth GatorID does not exist within the tree, print “unsuccessful”.


}


void AVLTree::removeInorderHelper(int n, int &count, TreeNode* node) {

    count++;
    removeInorderHelper(n,count,node->left);

        std::cout << node->name;


    removeInorderHelper(n, count,node->right);
}