#include <iostream>
#include <sstream>

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
    short operationCount;
    std::cin>>operationCount;

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

        }

        else if (command=="remove"){

        }

        else if (command=="search"){

        }

        else if (command=="printInorder"){

        }

        else if (command=="printPreorder"){

        }

        else if (command=="printPostorder"){

        }

        else if (command=="printLevelCount"){

        }

        else if (command=="removeInorder"){

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

