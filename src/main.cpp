#include <iostream>
#include <sstream>
#include "AVL_Tree.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

bool verifyName(const std::string& name) {

    //make sure each character is a-z or A-Z
    for (char c: name) {
        if (!isalpha(c) && !isdigit(c))
            return false;
    }
    return true;
}

bool verifyID(int ID) {
    int digitCount = 0;
    while (ID > 0) {
        ID /= 10; //floor division for is did 4/10, would yield "0"
        digitCount++;
    }
    return digitCount == 8;
}

int main(){
    short operationCount;
    std::cin>>operationCount;
    AVLTree GatorAVLTree;//Created a Tree (Default constructor)

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
            std::string name;
            std::string strID;
            int ID;

            //read up to the first quotation mark
            getline(lineStream, name, '"');

            //read up to the last quotation mark (so just saves "name" with no quotation marks)
            getline(lineStream, name, '"');

            //last of stream should just be the ID
            getline(lineStream, strID);
            ID=stoi(strID);//convert to integer

            if(verifyName(name)&& verifyID(ID)) {
                GatorAVLTree.insert(name, ID);
                std::cout << "successful";
            }
            else
                std::cout<<"unsuccessful";
        }

        else if (command=="remove"){
            std::string strID;
            int ID;

            //last of stream should just be the ID
            getline(lineStream, strID);
            ID=stoi(strID);//convert to integer

            if(verifyID(ID)) {
                GatorAVLTree.remove(ID);
                std::cout << "successful";
            }
            else
                std::cout<<"unsuccessful";
        }

        else if (command=="search"){
            std::string strID;
            int ID;

            //last of stream should just be the ID
            getline(lineStream, strID);

            //if the search is for a GatorID
            try {
                ID = stoi(strID);//convert to integer
                GatorAVLTree.search(ID);
            }

            //if the search is for a name and not a GatorID
            catch(...){
            std::string name;

            //read up to the first quotation mark
            getline(lineStream, name, '"');

            //read up to the last quotation mark (so just saves "name" with no quotation marks)
            getline(lineStream, name, '"');

            GatorAVLTree.search(name);
            //TODO if found, print name
            // if not found print "unsuccessful"
            }
        }

        else if (command=="printInorder"){
            GatorAVLTree.printInorder();

        }

        else if (command=="printPreorder"){
            GatorAVLTree.printPreorder();

        }

        else if (command=="printPostorder"){
            GatorAVLTree.printPostorder();

        }

        else if (command=="printLevelCount"){
            GatorAVLTree.printLevelCount();

        }

        else if (command=="removeInorder"){
            std::string str_n;
            int n;

            getline(lineStream, str_n);
            n=stoi(str_n);//convert to integer

            GatorAVLTree.removeInorder(n);
            //TODO if found, print "successful"
            // if not found print "unsuccessful"
        }
/*        else
            std::cout<<"unsuccessful";*/

        operationCount--;//decrement operationCount as we just completed 1 operation
    }

	return 0;
}