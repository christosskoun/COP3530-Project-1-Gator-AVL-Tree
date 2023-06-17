#include <iostream>
#include <sstream>
#include "AVL_Tree.h"

// Note:
	//1. You will have to comment main() when unit testing your code because catch uses its own main().
	//2. You will submit this main.cpp file and any header files you have on Gradescope.


bool verifyName(const std::string& name) {

    //make sure each character is a-z or A-Z
    for (char c: name) {
        if (!isalpha(c) && !isdigit(c))
            return false;
    }
    return true;
}

bool verifyID(std::string ID){
    try{
        int temp;
        temp=stoi(ID);
        return (ID.length() == 8);
    }
    catch(...) {
        return false; //would occur is the passed in ID is not all numbers
    }
}

int main(){
    short operationCount;
    std::cin>>operationCount;
    AVLTree GatorAVLTree;//Created a Tree (Default constructor)
    std::cin.ignore(); //basically ignores the /n as a cin and is ready for "currLine" later to just include the 2nd line

    while(operationCount>0) {

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
            std::string ID;

            //read up to the first quotation mark
            getline(lineStream, name, '"');

            //read up to the last quotation mark (so just saves "name" with no quotation marks)
            getline(lineStream, name, '"');

            // Ignore leading whitespace in the lineStream
            lineStream >> std::ws;

            //last of stream should just be the ID
            getline(lineStream, ID);

            if(verifyName(name)&& verifyID(ID))
                GatorAVLTree.insert(name, ID);

            else
                std::cout<<"unsuccessful"<<std::endl;

            operationCount--;//decrement operationCount as we just completed 1 operation
        }

        else if (command=="remove"){
            std::string ID;

            // Ignore leading whitespace in the lineStream
            lineStream >> std::ws;

            //last of stream should just be the ID
            getline(lineStream, ID);

            if(verifyID(ID))
                GatorAVLTree.remove(ID);

            else
                std::cout<<"unsuccessful"<<std::endl;

            operationCount--;//decrement operationCount as we just completed 1 operation
        }

        else if (command=="search"){
            std::string name_or_ID;

            // Ignore leading whitespace in the lineStream
            lineStream >> std::ws;

            //last of stream should just be the string
            getline(lineStream, name_or_ID);

            // Remove surrounding quotes if they exist
            if (name_or_ID.front() == '"' && name_or_ID.back() == '"')
                name_or_ID = name_or_ID.substr(1, name_or_ID.size() - 2); //-2 bc one is to get rid of last quote and the other is because we start counting at 0 not 1, so this is just to get to the correct spot

            GatorAVLTree.search(name_or_ID);

            operationCount--;//decrement operationCount as we just completed 1 operation

        }

        else if (command=="printInorder"){
            GatorAVLTree.printInorder();
            operationCount--;//decrement operationCount as we just completed 1 operation
        }

        else if (command=="printPreorder"){
            GatorAVLTree.printPreorder();
            operationCount--;//decrement operationCount as we just completed 1 operation
        }

        else if (command=="printPostorder"){
            GatorAVLTree.printPostorder();
            operationCount--;//decrement operationCount as we just completed 1 operation
        }

        else if (command=="printLevelCount"){
            GatorAVLTree.printLevelCount();
            operationCount--;//decrement operationCount as we just completed 1 operation
        }

        else if (command=="removeInorder"){
            std::string str_n;
            int n;

            getline(lineStream, str_n);
            n=stoi(str_n);//convert to integer

            GatorAVLTree.removeInorder(n);

            operationCount--;//decrement operationCount as we just completed 1 operation
        }

        else{ //will execute if not a valid command
            std::cout<<"unsuccessful"<<std::endl;
            operationCount--;//decrement operationCount as we just completed 1 operation
        }
    }
	return 0;
}