/**
 * @file main.cpp
 * @brief showcasing of a Binary Search Tree
 *
 * This program was written for a group project in CS355.
 * It is written to showcase a Binary Search Tree; what it is and how it works.
 * The driver program makes use of a user-defined Class.h file that we wrote which
 * includes the operations of a BST: insertion, post/pre/in order traversal, deletion,
 *                                   searching, and finding min node.
 *
 * @authors Ethan Smith, Emily Monroe
 * @date 10/30/2024
 */
#include <iostream>
#include <chrono> //used to get the execution runtime
#include <iomanip>
#include "Class.h"
using namespace std;

int main()
{
    /*
     * Anything relating to figuring out the execution time was done with
     * the help from the GeeksForGeeks website
     */
    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    /*
     * Since the node class is templated, you have to declare it with a type-argument.
     * In this case, primitive int.
     */
    Node<int>* rootNode = new Node<int>();
    // create a BST
    rootNode = rootNode->insertNode(rootNode, 50);
    rootNode = rootNode->insertNode(rootNode, 30);
    rootNode = rootNode->insertNode(rootNode, 20);
    rootNode = rootNode->insertNode(rootNode, 40);
    rootNode = rootNode->insertNode(rootNode, 70);
    rootNode = rootNode->insertNode(rootNode, 60);
    rootNode = rootNode->insertNode(rootNode, 80);

    // Print the inorder traversal of a BST
    cout << "Inorder traversal of the given Binary Search "
            "Tree is: ";
    rootNode->inOrderTrav(rootNode);
    cout << endl;

    // delete a node in BST
    rootNode = rootNode->deleteNode(rootNode, 20);
    cout << "After deletion of 20: ";
    rootNode->inOrderTrav(rootNode);
    cout << endl;

    // Insert a node in BST
    rootNode = rootNode->insertNode(rootNode, 25);
    cout << "After insertion of 25: ";
    rootNode->inOrderTrav(rootNode);
    cout << endl;

    // Search a key in BST
    int testValue = 25;
    //FIXED: found was the wrong type... search
    bool found = rootNode->searchNode(rootNode, testValue);

    // check if the key is found or not
    if (found) {
        cout << "Node " << testValue << " found in the BST." << endl;
    }
    else {
        cout << "Node " << testValue << " not found in the BST." << endl;
    }

    //getting the execution time
    auto end = chrono::high_resolution_clock::now();

    //calculate time taken
    double timeTaken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();

    timeTaken *= 1e-9;

    cout << "**************************************\n";
    cout << "TIME TAKEN TO EXECUTE -- " << fixed
         << timeTaken << setprecision(9)
         << " seconds\n";
    cout << "**************************************\n";

    return 0;
}
