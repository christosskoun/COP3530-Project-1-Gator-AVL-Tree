#pragma once
#include <string>
struct AVLTree {

    struct TreeNode {
        std::string ID;
        std::string name;
        int height;
        TreeNode *left;
        TreeNode *right;
        TreeNode(std::string userName, std::string userID) :  name(userName), ID(userID), left(nullptr), right(nullptr), height(0) {} //constructor
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

    void insert(std::string name, std::string ID);
    TreeNode * insertHelper(TreeNode* root, std::string name, std::string ID);

    void remove(std::string ID);
    TreeNode * removeHelper(TreeNode* root, std::string ID);

    void search(std::string name_or_ID); //searches for a Node with a specific ID/Name
    TreeNode* searchHelper(TreeNode* node, std::string name_or_ID);

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

void AVLTree::insert(std::string name, std::string ID) {
    if (this->root== nullptr) {
        std::cout<<"successful"<<std::endl;
        this->root = new TreeNode(name, ID);
    }
    else
        this->root=insertHelper(this->root, name, ID);
}

AVLTree::TreeNode * AVLTree::insertHelper(AVLTree::TreeNode* node, std::string name, std::string ID) {
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

void AVLTree::remove(std::string ID) {
    if (this->root== nullptr)
        std::cout<<"unsuccessful"<<std::endl; //can't remove if nothing there
    else
        this->root=removeHelper(this->root, ID);

}

AVLTree::TreeNode * AVLTree::removeHelper(AVLTree::TreeNode* node, std::string ID) {
    //special case where you are removing the root of the tree
    if (this->root->ID == ID) {

        //if tree node has no children
        if(this->root->right==nullptr&&this->root->left== nullptr) {
            delete node;
            node = nullptr;
            std::cout << "successful" << std::endl;
        }

            //else 2 childs
        else if (this->root->right != nullptr&&this->root->left!= nullptr) {

            //node will be left-most node on right subtree (aka inorder successor)
            TreeNode* successor=this->root->right;
            while(node->left!= nullptr)
                successor= successor->left;

            this->root->ID= successor->ID;
            this->root->name=successor->name;

            removeHelper(this->root->right,successor->ID);
            std::cout << "successful" << std::endl;
        }

            //else 1 child
        else if (this->root->right != nullptr ||this->root->left!= nullptr) {
            if (this->root->right != nullptr) {//the one child is on the right of the node
                TreeNode* tempNode=this->root;
                node=this->root->right;
                delete this->root;
                std::cout << "successful" << std::endl;
            }
            else if (this->root->left != nullptr) {//the one child is on the left of the node
                TreeNode* tempNode=this->root;
                node=this->root->left;
                delete this->root;
                std::cout << "successful" << std::endl;
            }
        }
    }

    //base case for recursion (one of the children is the node that must be removed)
    if (ID == node->right->ID || ID == node->left->ID) {

        //the parent's right node is the one to delete
        if (node->right->ID == ID) {

            //if tree node has no children
            if (node->right->right == nullptr && node->right->left == nullptr) {
                delete node->right;
                node->right = nullptr;
                std::cout << "successful" << std::endl;
            }
                //else 2 childs
            else if (node->right->right != nullptr&&node->right->left!= nullptr) {
                //node will be left-most node on right subtree (aka inorder successor)
                TreeNode* successor=node->right->right;
                while(successor->left!= nullptr)
                    successor= successor->left;

                node->right->ID= successor->ID;
                node->right->name=successor->name;

                removeHelper(node->right,successor->ID);
                std::cout << "successful" << std::endl;
            }
                //else 1 child
            else if (node->right->right != nullptr ||node->right->left!= nullptr) {
                if (node->right->right != nullptr) {//the one child is on the right of the node
                    TreeNode* tempNode=node->right->right;
                    delete node->right;
                    node->right = tempNode;
                    std::cout << "successful" << std::endl;
                }
                else if (node->right->left != nullptr) {//the one child is on the left of the node
                    TreeNode* tempNode=node->right->left;
                    delete node->right;
                    node->right = tempNode;
                    std::cout << "successful" << std::endl;
                }
            }
        }

        //the parent's left node is the one to delete
        else if (node->left->ID == ID) {

            //if tree node has no children
            if (node->left->right == nullptr && node->left->left == nullptr) {
                delete node->left;
                node->left = nullptr;
                std::cout << "successful" << std::endl;
            }
                //else 2 childs
            else if (node->left->right != nullptr&&node->left->left!= nullptr) {
                //node will be left-most node on right subtree (aka inorder successor)
                TreeNode* successor=node->left->right;
                while(successor->left!= nullptr)
                    successor= successor->left;

                node->left->ID= successor->ID;
                node->left->name=successor->name;

                removeHelper(node->left,successor->ID);
                std::cout << "successful" << std::endl;
            }
                //else 1 child
            else if (node->left->right != nullptr ||node->left->left!= nullptr) {
                if (node->left->right != nullptr) {//the one child is on the right of the node
                    TreeNode* tempNode=node->left->right;
                    delete node->left;
                    node->left = tempNode;
                    std::cout << "successful" << std::endl;
                }
                else if (node->left->left != nullptr) {//the one child is on the left of the node
                    TreeNode* tempNode=node->left->left;
                    delete node->left;
                    node->left = tempNode;
                    std::cout << "successful" << std::endl;
                }
            }
        }
    }
    else if (ID < node->ID)
        node->left = removeHelper(node->left, ID);

    else if (ID > node->ID)
        node->right = removeHelper(node->right, ID);

    if (node != nullptr)
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

void AVLTree::search(std::string name_or_ID) {
    searchHelper(this->root, name_or_ID);
}

AVLTree::TreeNode* AVLTree::searchHelper(AVLTree::TreeNode* node, std::string name_or_ID) {
    int numTester;
    bool found=false;

    //in the special case where the tree is empty
    if (node == nullptr) {
        std::cout << "unsuccessful" << std::endl;
        return nullptr;
    }

    // If this goes through, the parameter passed in was for a Gator ID
    try {
        numTester = std::stoi(name_or_ID);

        if (node->ID == name_or_ID){
            std::cout<<node->name<<std::endl;
            found=true;
        }

        if (name_or_ID < node->ID)
            return searchHelper(node->left, name_or_ID);

        else if (name_or_ID > node->ID)
            return searchHelper(node->right, name_or_ID);
    }

    // The idea is if this catches, then the parameter passed in was for a name
    catch (...) {
        if (node->name == name_or_ID){
            std::cout<<node->ID<<std::endl;
            found= true;
        }

        //longer average time complexity for searching with name because have to attempt to search whole BST
        else{
            searchHelper(node->left, name_or_ID);
            searchHelper(node->right, name_or_ID);        }
        }

    //will always be looked at end of recursion
    if (!found)
        std::cout<<"unsuccessful"<<std::endl;
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