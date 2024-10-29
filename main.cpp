#include <iostream>
#include "Class.h"
using namespace std;

int main()
{

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
    //FIXED: found was the wrong type.. search
    bool found = rootNode->searchNode(rootNode, testValue);

    // check if the key is found or not
    if (found) {
        cout << "Node " << testValue << " found in the BST." << endl;
    }
    else {
        cout << "Node " << testValue << " not found in the BST." << endl;
    }

    return 0;
}
