#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <src/AVL_Tree.h>

TEST_CASE("Basic Insert and print with Inorder Traversal", "[1]"){
    AVLTree GatorAVLTree;   // Create a Tree object
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("two", "22222222");
    GatorAVLTree.insert("three", "33333333");

    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

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
    std::string expectedOutput = "one, two, three\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}


TEST_CASE("Basic Insert and print with PostOrder Traversal", "[2]"){
    AVLTree GatorAVLTree;   // Create a Tree object
    GatorAVLTree.insert("one", "11111111");
    GatorAVLTree.insert("two", "22222222");
    GatorAVLTree.insert("three", "33333333");

    // Redirect cout to a file
    std::ofstream outputFile("output.txt");
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

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
    std::string expectedOutput = "one, three, two\n";

    // Compare the actual and expected outputs
    REQUIRE(expectedOutput.size() == actualOutput.size());
    REQUIRE(actualOutput == expectedOutput);

    REQUIRE(1 == 1);
}