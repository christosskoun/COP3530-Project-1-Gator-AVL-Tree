#include <iostream>
#include <sstream>
#include "AVL_Tree.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/


std:: string verifyWord(std::istringstream& wordStream) {

    //read in the next word
    std::string word;
    wordStream >> word;

    if (word.length() > 20)
        return "";

    //make sure each character is a-z, A-Z, or 0-9
    for (char c: word) {
        if (!isalpha(c) && !isdigit(c))
            return "";
    }
    return word;
}

int main(){
    short operationCount;
    std::cin>>operationCount;
    new TreeNode;//TODO don't think I did this correctly

    while(operationCount>=0) {

        //reading one line of input from cin
        std::string currLine;
        getline(std::cin, currLine);

        //create an input stream from that line
        std::istringstream lineStream(currLine);

        //read the first word from the input stream
        std::string command;
        lineStream >> command;

        if (command=="insert"){
            TreeNode::insert();

        }

        else if (command=="remove"){
            TreeNode::remove();

        }

        else if (command=="search"){
            TreeNode::search();

        }

        else if (command=="printInorder"){
            TreeNode::search();

        }

        else if (command=="printPreorder"){
            TreeNode::printPreorder();

        }

        else if (command=="printPostorder"){
            TreeNode::printPostorder();

        }

        else if (command=="printLevelCount"){
            TreeNode::printLevelCount();

        }

        else if (command=="removeInorder"){
            TreeNode::removeInorder();

        }


        operationCount--;//decrement operationCount as we just completed 1 operation
    }

	return 0;
}



/*
        //read up to the next quotation mark
        std::string next;
        getline(lineStream, next, '"');
*/

