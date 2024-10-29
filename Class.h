#include <iostream>
using namespace std;

template<class t>
class Node{
    private:
        t val;
        Node<t>* left;
        Node<t>* right;
    public:
         Node<t>()
         {
            val = t();
            this->left = nullptr;
            this->right = nullptr;
         }
        Node<t>* newNode(t val)
        {
            Node<t>* tempNode = new Node<t>();
            tempNode->val = val;
            tempNode->left = nullptr;
            tempNode->right = nullptr;
            return tempNode;
        }
        Node<t>* insertNode(Node<t>* root, t val)
        {
            if (root==nullptr)
            {
                return newNode(val);;
            }
            if(val < root->val)
            {
                root->left = insertNode(root->left, val);
            }
            else if(val > root->val)
            {
                root->right = insertNode(root->right, val);
            }
            return root;
        }

        void inOrderTrav(Node<t>* root)
        {
             if(root)
             {
                 inOrderTrav(root->left);
                 cout << root->val << ' ';
                 inOrderTrav(root->right);
             }
        }
        void preOrderTrav(Node<t>* root)
        {
            if(root)
            {
                cout << root->val << ' ';
                preOrderTrav(root->left);
                preOrderTrav(root->right);
            }
        }
        void postOrderTrav(Node<t>* root)
        {
             if(root)
             {
                 postOrderTrav(root->left);
                 postOrderTrav(root->right);
                 cout << root->val << ' ';
             }
        }
        void display(Node<t>* root)
        {
             if(root)
             {
                 display(root->left);
                 cout << root->val << ' ';
                 display(root->right);
             }
        }

        bool searchNode(Node<t>* root, t key)
        {
            if (root == nullptr || root->val == key) {
                return root != nullptr;
            }

            // Key is greater than root's key
            if (root->val < key) {
                return searchNode(root->right, key);
            }

            // Key is smaller than root's key
            return searchNode(root->left, key);
        }

        //FIXED: name collision, renamed to givenNode
        Node<t>* findMinNode(Node<t>* givenNode)
        {
            Node<t> *currNode = givenNode;

            while ((currNode) && (currNode->left)) { currNode = currNode->left; }
            return currNode;
        }

        Node<t>* deleteNode(Node<t>* root, t val)
        {
            if (root == nullptr)
            {
                cout << "Tree Empty" << endl;
                return nullptr;
            }
            // If the data to be deleted is smaller than the root's
            // data, then it lies in the left subtree
            if (val < root->val) {
                root->left = deleteNode(root->left, val);
            }
                // If the data to be deleted is greater than the root's
                // data, then it lies in the right subtree
            else if (val > root->val) {
                root->right = deleteNode(root->right, val);
            }
                // if data is same as root's data, then This is the node
                // to be deleted
            else {
                // node with only one child or no child
                if (root->left == nullptr) {
                    Node<t>* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr) {
                    Node<t>* temp = root->left;
                    delete root;
                    return temp;
                }

                // node with two children: Get the inorder successor
                // (smallest in the right subtree)
                Node<t>* temp = findMinNode(root->right);

                // Copy the inorder successor's content to this node
                root->val = temp->val;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->val);
            }
            return root;
    }
};




