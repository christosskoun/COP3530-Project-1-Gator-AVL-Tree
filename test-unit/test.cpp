#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <src/AVL_Tree.h>

TEST_CASE("Basic Insert and print with Inorder Traversal", "[1]"){
    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

    AVLTree GatorAVLTree;   // Create a Tree object
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("two", "22222222");
    GatorAVLTree.insert("three", "33333333");

    // Call the printInorder() function
    GatorAVLTree.printInorder();

    // Restore cout's original buffer
    std::cout.rdbuf(coutBuffer);
    outputFile.close();

    // Open the generated output file
    std::ifstream generatedFile("output.txt");

    // Read the contents of the generated output file
    std::string actualOutput((std::istreambuf_iterator<char>(generatedFile)),std::istreambuf_iterator<char>());

    // Define the expected output
    std::string expectedOutput = "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "one, two, three\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}

TEST_CASE("Medium Insert and print with PostOrder Traversal and Print Level Order", "[2]"){

    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

    AVLTree GatorAVLTree;   // Create a Tree object
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("two", "22222222");
    GatorAVLTree.insert("three", "33333333");
    GatorAVLTree.insert("four", "44444444");
    GatorAVLTree.insert("five", "55555555");
    GatorAVLTree.insert("six", "66666666");
    GatorAVLTree.insert("seven", "77777777");


    // Call the printPostorder() function
    GatorAVLTree.printPostorder();

    // Call the printLevelCount() function
    GatorAVLTree.printLevelCount();

    // Restore cout's original buffer
    std::cout.rdbuf(coutBuffer);
    outputFile.close();

    // Open the generated output file
    std::ifstream generatedFile("output.txt");

    // Read the contents of the generated output file
    std::string actualOutput((std::istreambuf_iterator<char>(generatedFile)),
                             std::istreambuf_iterator<char>());

    // Define the expected output
    std::string expectedOutput = "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "one, three, two, five, seven, six, four\n"
                                 "3\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}

TEST_CASE("Medium Insert with remove and Preorder Traversal followed by Print Level Order", "[3]"){

    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

    AVLTree GatorAVLTree;   // Create a Tree object

    // Call the insert() function
    GatorAVLTree.insert("five", "55555555");
    GatorAVLTree.insert("seven", "77777777");
    GatorAVLTree.insert("nine", "99999999");
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("two", "22222222");
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("two", "22222222");

    // Call the printPreorder() function
    GatorAVLTree.printPreorder();

    // Call the printPreorder() function
    GatorAVLTree.remove("11111111");
    GatorAVLTree.remove("55555555");

    // Call the printLevelCount() function
    GatorAVLTree.printLevelCount();

    // Restore cout's original buffer
    std::cout.rdbuf(coutBuffer);
    outputFile.close();

    // Open the generated output file
    std::ifstream generatedFile("output.txt");

    // Read the contents of the generated output file
    std::string actualOutput((std::istreambuf_iterator<char>(generatedFile)),
                             std::istreambuf_iterator<char>());

    // Define the expected output
    std::string expectedOutput = "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "unsuccessful\n"
                                 "unsuccessful\n"
                                 "seven, two, one, five, nine\n"
                                 "successful\n"
                                 "successful\n"
                                 "2\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}

TEST_CASE("Remove Inorder and Search", "[4]"){

    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

    AVLTree GatorAVLTree;   // Create a Tree object
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("seven", "77777777");
    GatorAVLTree.insert("three", "33333333");
    GatorAVLTree.insert("four", "44444444");
    GatorAVLTree.insert("two", "22222222");

    // Call the search() function
    GatorAVLTree.search("three");
    GatorAVLTree.search("33333333");

    // Call the remove() function
    GatorAVLTree.remove("33333333");

    // Call the search() function again to see if remove worked
    GatorAVLTree.search("three");
    GatorAVLTree.search("33333333");

    // Call the removeInorder() function
    GatorAVLTree.removeInorder(1);

    // Call the printInorder() function
    GatorAVLTree.printInorder();

    // Restore cout's original buffer
    std::cout.rdbuf(coutBuffer);
    outputFile.close();

    // Open the generated output file
    std::ifstream generatedFile("output.txt");

    // Read the contents of the generated output file
    std::string actualOutput((std::istreambuf_iterator<char>(generatedFile)),
                             std::istreambuf_iterator<char>());

    // Define the expected output
    std::string expectedOutput = "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "33333333\n"
                                 "three\n"
                                 "successful\n"
                                 "unsuccessful\n"
                                 "unsuccessful\n"
                                 "successful\n"
                                 "one, four, seven\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}

TEST_CASE("Hard Insert with remove and printPostorder as well as printPreorder", "[5]"){

    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

    AVLTree GatorAVLTree;   // Create a Tree object
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("three", "33333333");
    GatorAVLTree.insert("nine", "99999999");
    GatorAVLTree.insert("four", "44444444");
    GatorAVLTree.insert("seven", "77777777");
    GatorAVLTree.insert("zero", "00000000");
    GatorAVLTree.insert("two", "22222222");
    GatorAVLTree.insert("five", "55555555");
    GatorAVLTree.insert("eight", "88888888");
    GatorAVLTree.insert("six", "66666666");

    // Call the printPreorder() function
    GatorAVLTree.printPreorder();

    // Call the remove() function
    GatorAVLTree.remove("11111111");

    // Call the printPostorder() function
    GatorAVLTree.printPostorder();

    // Restore cout's original buffer
    std::cout.rdbuf(coutBuffer);
    outputFile.close();

    // Open the generated output file
    std::ifstream generatedFile("output.txt");

    // Read the contents of the generated output file
    std::string actualOutput((std::istreambuf_iterator<char>(generatedFile)),
                             std::istreambuf_iterator<char>());

    // Define the expected output
    std::string expectedOutput = "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "three, one, zero, two, seven, five, four, six, nine, eight\n"
                                 "successful\n"
                                 "zero, two, four, six, five, eight, nine, seven, three\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}

TEST_CASE("Test 8 from Gradescope", "[6]"){

    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

    AVLTree GatorAVLTree;   // Create a Tree object
    GatorAVLTree.insert("A", "55555555");
    GatorAVLTree.insert("B", "33333333");
    GatorAVLTree.insert("C", "77777777");
    GatorAVLTree.insert("D", "11111111");
    GatorAVLTree.insert("E", "44444444");
    GatorAVLTree.insert("F", "66666666");
    GatorAVLTree.insert("A", "88888888");
    GatorAVLTree.insert("A", "99999999");


    // Call the search() function
    GatorAVLTree.search("D");
    GatorAVLTree.search("F");
    GatorAVLTree.search("A");

    // Restore cout's original buffer
    std::cout.rdbuf(coutBuffer);
    outputFile.close();

    // Open the generated output file
    std::ifstream generatedFile("output.txt");

    // Read the contents of the generated output file
    std::string actualOutput((std::istreambuf_iterator<char>(generatedFile)),
                             std::istreambuf_iterator<char>());

    // Define the expected output
    std::string expectedOutput = "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "successful\n"
                                 "11111111\n"
                                 "66666666\n"
                                 "55555555\n"
                                 "88888888\n"
                                 "99999999\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}