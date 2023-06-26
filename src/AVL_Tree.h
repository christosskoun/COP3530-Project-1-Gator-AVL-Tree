#pragma once
#include <string>

struct AVLTree {

    struct TreeNode {//Trees are made up of tree nodes
        std::string ID; //this must be a unique value compared to other Nodes
        std::string name; //does not have to be unique compared to other Nodes
        int height; //will be zero if node is a leaf. Each level higher is +1 height
        TreeNode *left;
        TreeNode *right;
        int balanceFactor; //left subtree height - right subtree height
        TreeNode(std::string userName, std::string userID) :  name(userName), ID(userID), left(nullptr), right(nullptr), height(0),balanceFactor(0) {} //parameterized constructor
    };

    //unique to a TREE (not a node)
    TreeNode* root;
    int size; //indicates total nodes in a tree

    AVLTree() : root(nullptr), size(0) {} //Default constructor

    int getHeight(AVLTree::TreeNode* node); //Helper function to assist with keeping variables up to date

    //Helper functions to keep tree Balanced (AKA rotation functions)
    TreeNode* rotateLeft(TreeNode* node); //O(1)
    TreeNode* rotateRight(TreeNode* node); //O(1)
    TreeNode* rotateLR(TreeNode* node); //O(1)
    TreeNode* rotateRL(TreeNode* node); //O(1)

    TreeNode* rotations(TreeNode* node); //Takes into account prior four methods and allocated them to the node and its neighbors respectively

    void insert(std::string name, std::string ID);
    TreeNode * insertHelper(TreeNode* root, std::string name, std::string ID);

    void remove(std::string ID);
    TreeNode * removeHelper(TreeNode* root, std::string ID);

    void search(std::string name_or_ID); //searches for a Node with a specific ID/Name
    TreeNode* searchHelper(TreeNode* node, std::string name_or_ID, bool& found);

    void printInorder();
    void printInorderHelper(TreeNode* node, bool& isFirstNode);

    void printPreorder();
    void printPreorderHelper(TreeNode* node, bool& isFirstNode);

    void printPostorder();
    void printPostorderHelper(TreeNode* node, bool& isFirstNode);

    void printLevelCount();    //Prints the number of levels that exist in the tree.

    void removeInorder(int n); //traverses Tree (Inorder method) and removes the nth indexed node
    void removeInorderHelper(int n, int& count, TreeNode* node);
};

int AVLTree::getHeight(AVLTree::TreeNode *node) {
    if (node == nullptr)
        return -1; //doesn't just indicate error, this -1 is accounted for as we add 1 at the end of the calculation and leaf nodes will have a height of "0"
    return node->height; //
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
    if (node->balanceFactor == -2) { // Tree is "right-heavy"
        if (getHeight(node->right->left) - getHeight(node->right->right) ==1) { // Right subtree is "left-heavy"
            node = rotateRL(node);

            //update heights
            node->height++;
            node->right->height--;
            node->left->height-=2;
        }
        else if (getHeight(node->right->left) - getHeight(node->right->right) ==-1) { // Right subtree is "right-heavy"
            node = rotateLeft(node);

            //update heights
            node->left->height-=2;
        }
    }
    else if (node->balanceFactor == 2) { // Tree is "left-heavy"
        if (getHeight(node->left->left) - getHeight(node->left->right) ==-1) { // Left subtree is "right-heavy"
            node = rotateLR(node);

            //update heights
            node->height++;
            node->left->height--;
            node->right->height-=2;
        }
        else if(getHeight(node->left->left) - getHeight(node->left->right) ==1) { // Left subtree is "left-heavy"
            node = rotateRight(node);

            //update heights
            node->right->height-=2;
        }
    }

    node->balanceFactor= getHeight(node->left)- getHeight(node->right);

    return node;
}

void AVLTree::insert(std::string name, std::string ID) {
    if (this->root== nullptr) {
        this->root = new TreeNode(name, ID);
        this->size++;
        std::cout<<"successful"<<std::endl;
    }
    else
        this->root=insertHelper(this->root, name, ID); //needed as we need to add a few more parameters
}

AVLTree::TreeNode * AVLTree::insertHelper(AVLTree::TreeNode* node, std::string name, std::string ID) {
    if (node == nullptr) { //edge case
        std::cout<<"successful"<<std::endl;
        this->size++;
        node = new TreeNode(name, ID);
    }

    else if (ID==node->ID) //base case for recursion
        std::cout<<"unsuccessful"<<std::endl; //and nothing else will happen because duplicate IDs are not allowed!

    else if(ID<node->ID) //recursion case
        node->left= insertHelper(node->left, name, ID);

    else if (ID>node->ID) //recursion case
        node->right= insertHelper(node->right, name, ID);

    node->height=std::max(getHeight(node->left), getHeight(node->right))+1;

    node->balanceFactor= getHeight(node->left)- getHeight(node->right);
    node=rotations(node); //update rotations if needed

    return node;
}

void AVLTree::remove(std::string ID) {
    this->root=removeHelper(this->root, ID); //needed as we need to add more parameters
}

AVLTree::TreeNode * AVLTree::removeHelper(AVLTree::TreeNode* node, std::string ID) {

    // covers "empty-tree" case as well as case where inputted UFID does not exist (edge case)
    if (node==nullptr) {
        std::cout << "unsuccessful" << std::endl;
        return nullptr;
    }

    //check if node to delete is "more-left"
    else if (ID < node->ID) //recursion case
        node->left = removeHelper(node->left, ID);

    //check if node to delete is "more-right"
    else if (ID > node->ID) //recursion case
        node->right = removeHelper(node->right, ID);

    //If we go in here that means we are now dealing with node->ID==ID (base case)
    else{
        //if tree node has no children
        if (node->right == nullptr && node->left == nullptr) {
            delete node;
            this->size--;
            std::cout << "successful" << std::endl;
            return nullptr;
        }

        //else 2 childs
        else if (node->right != nullptr&&node->left!= nullptr) {
            //node will be left-most node on right subtree (aka inorder successor)
            TreeNode* successor=node->right;
            while(successor->left!= nullptr)
                successor= successor->left;

            node->ID= successor->ID;
            node->name=successor->name;

            node->right=removeHelper(node->right,successor->ID); //to delete the previous position of the inorder successor, call remove on the right subtree (so ignores ID of node that matches)
        }

        //else 1 child
        else if (node->right != nullptr) {//the one child is on the right of the node
            TreeNode* tempNode=node->right;
            delete node;
            node = tempNode;
            this->size--;
            std::cout << "successful" << std::endl;
            return node;
        }

        else if (node->left != nullptr) {//the one child is on the left of the node
            TreeNode* tempNode=node->left;
            delete node;
            node = tempNode;
            this->size--;
            std::cout << "successful" << std::endl;
            return node;
        }
    }

    node->height=std::max(getHeight(node->left), getHeight(node->right))+1;

    node->balanceFactor= getHeight(node->left)- getHeight(node->right);
    node=rotations(node);

    return node;
}

void AVLTree::search(std::string name_or_ID) {
    bool found= false; //will be true if a matching node is found after traversal
    searchHelper(this->root, name_or_ID, found); //needed as we need to add more parameters

    //will always be looked at end of recursion
    if (!found)
        std::cout << "unsuccessful" << std::endl;
}

AVLTree::TreeNode* AVLTree::searchHelper(AVLTree::TreeNode* node, std::string name_or_ID, bool& found) {
    int numTester; //used just temporarily to see if the input was an ID or a name

    //in the special case where the tree is empty
    if (node == nullptr)
        return nullptr;

    // If this goes through, the parameter passed in was for a Gator ID /Worst Case: O(logn)
    try {
        numTester = std::stoi(name_or_ID);

        if (node->ID == name_or_ID){
            std::cout<<node->name<<std::endl;
            found=true;
            return nullptr;
        }

        if (name_or_ID < node->ID)
            searchHelper(node->left, name_or_ID, found);

        else if (name_or_ID > node->ID)
            searchHelper(node->right, name_or_ID, found);
    }

    // The idea is if this catches, then the parameter passed in was for a name /Will always be O(n) (because may have duplicate names with different IDs)
    catch (...) {
        if (node->name == name_or_ID){
            std::cout<<node->ID<<std::endl;
            found= true;
        }

        //longer worst case time complexity for searching with name because have to traverse the whole BST
        if (node->left!= nullptr)
            searchHelper(node->left, name_or_ID, found);
        if (node->right!= nullptr)
            searchHelper(node->right, name_or_ID, found);
    }
}

void AVLTree::printInorder() {
    bool isFirstNode = true; //directions for project makes us make sure nodes are listed with a comma after every value (except for cast value)
    printInorderHelper(this->root, isFirstNode); //needed as we need to add more parameters
    std::cout << std::endl; //so next input is placed on the next line
}

void AVLTree::printInorderHelper(TreeNode* node, bool& isFirstNode) {
    if (node == nullptr) //edge case
        return;

    printInorderHelper(node->left, isFirstNode);

    if (isFirstNode) {//can't do last node because we don't know when that'll be so we do formatting based off of if it's the first node
        std::cout << node->name;
        isFirstNode = false;
    }

    else
        std::cout << ", " << node->name; //comma before every node except first node

    printInorderHelper(node->right, isFirstNode);
}

void AVLTree::printPreorder() {
    bool isFirstNode = true; //directions for project makes us make sure nodes are listed with a comma after every value (except for cast value)
    printPreorderHelper(this->root, isFirstNode); //needed as we need to add more parameters
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
        std::cout << ", " << node->name; //comma before every node except first node

    printPreorderHelper(node->left, isFirstNode);

    printPreorderHelper(node->right, isFirstNode);
}

void AVLTree::printPostorder() {
    bool isFirstNode = true; //directions for project makes us make sure nodes are listed with a comma after every value (except for cast value)
    printPostorderHelper(this->root, isFirstNode); //needed as we need to add more parameters
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
        std::cout << ", " << node->name; //comma before every node except first node
}

void AVLTree::printLevelCount() {

    //Prints 0 if the head of the tree is null. Prints 1 is there is only one node in tree. And so on.
    if (this->root== nullptr)
        std::cout<<"0"<<std::endl;
    else
        std::cout<< this->root->height+1<<std::endl; //add one because that's the relationship between tree levels and root height (assuming 0-based index)
}

void AVLTree::removeInorder(int n) {

    if(n>size||this->root == nullptr) { //we passed the target so the user asked to remove something that doesn't exist
        std::cout << "unsuccessful" << std::endl;
        return;
    }

    int count = -1; //because first node should be indexed at "0"

    removeInorderHelper(n,count, this->root); //needed as we need to add more parameters
}

void AVLTree::removeInorderHelper(int n, int &count, TreeNode* node) {

    if (node->left != nullptr) //make sure we don't go to far!
        removeInorderHelper(n, count, node->left);

    count++;

    if (n==count) {
        remove(node->ID); //no need to print "successful" because remove() will do it automatically
        return;
    }

    if (node->right != nullptr) //make sure we don't go to far!
        removeInorderHelper(n, count, node->right);
}