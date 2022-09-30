/**
 * file: bst-student-proj3.h
 * author: Luke Smith
 * course: CSI 3334
 * assignment: project 3
 * due date: October 2, 2022
 *
 * This file contains the driver for the binary search tree.
 */

#ifndef BST_STUDENT_PROJ3
#define BST_STUDENT_PROJ3 

#include "bst-prof-proj3.h"
#include <queue>
#include <string>

/* Place your implementation of the BSTNode, BST, and EncryptionTree classes
 * here.
 *
 * Your driver should #include this file, which (as you can see above) will also
 * #include the professor file.
 */

/**
 * BSTNode Constructor
 *
 * This function is the default constructor for BSTNode.
 *
 * Parameters: None.
 *
 * Return value: None.
 */
template<class Base>
BSTNode<Base>::~BSTNode() {
    if (getLeft()) {
        delete left;
    }
    if (getRight()) {
        delete right;
    }
}

/**
 * printPreorder
 *
 * This function traverses the tree and prints it in preorder.
 *
 * Parameters:
 *      -os: output stream containing preorder traversal
 *      -indent: indentation representing depth of node in tree
 *
 * Return value: None.
 */
template<class Base>
void BSTNode<Base>::printPreorder(ostream &os, string indent) const {
    if (this) {
        os << indent << getData() << endl;
        indent += "  ";
        getLeft()->printPreorder(os, indent);
        getRight()->printPreorder(os, indent);
    } else {
        os << indent << "NULL" << endl;
        indent.pop_back();

    }
}


template<class Base>
const BSTNode<Base> *BSTNode<Base>::minNode() const {
    if (getLeft() != NULL) {
        getLeft()->minNode();
    } else {
        return this;
    }
}

template<class Base>
const BSTNode<Base> *BSTNode<Base>::maxNode() const {
    if (getRight() != NULL) {
        getRight()->maxNode();
    } else {
        return this;
    }
}

template<class Base>
void BST<Base>::insert(const Base &item) {
    // Declare new node to be inserted
    BSTNode<Base> *node = new BSTNode<Base>(item);

    // Create a previous and temporary node for iteration
    BSTNode<Base> *par = NULL;
    BSTNode<Base> *cur = this->root;

    // While temp is not null iterate through tree
    while (cur) {
        par = cur;
        // If item < temp, temp = left node
        if (item < cur->data) {
            cur = cur->left;
        }
        // If item > temp, temp = right node
        else if (cur->data < item) {
            cur = cur->right;
        }
    }

    // If the root is null then assign root to item
    if (!root) {
        this->root = node;
    }
    // Insert new node at location left
    else if (item < par->getData()) {
        par->left = node;
    }
    // Insert new node at location right
    else {
        par->right = node;
    }
}

template<class Base>
void BST<Base>::remove(const Base &item) {
    BSTNode<Base> *parent = this->root;
    BSTNode<Base> *toRemove = this->root;

    if (!toRemove) {
        return;
    }

    while (toRemove != NULL) {
        // Key is found
        if (!(toRemove->data < item) && !(item < toRemove->data)) {
            // Remove leaf node
            if (toRemove->left == NULL && toRemove->right == NULL) {
                if (parent->left == toRemove) {
                    parent->left = NULL;
                }
                else {
                    parent->right = NULL;
                }
                delete toRemove;
            }

            // Remove node with one child
            else if (toRemove->left == NULL || toRemove->right == NULL) {
                BSTNode<Base> *grandChild;
                if (toRemove->left != NULL) {
                    grandChild = toRemove->left;
                    toRemove->left = NULL;
                }
                else {
                    grandChild = toRemove->right;
                    toRemove->right = NULL;
                }
                if (parent->left == toRemove) {
                    parent->left = grandChild;
                }
                else {
                    parent->right = grandChild;
                }
                delete toRemove;
            }

            // Remove node with two children
            else {
                BSTNode<Base> *leftMost = toRemove->right;
                BSTNode<Base> *leftMostParent = toRemove;

                if (leftMost->left != NULL) {
                    while (leftMost->left != NULL) {
                        leftMostParent = leftMost;
                        leftMost = leftMost->left;
                    }
                    leftMostParent->left = leftMost->right;
                    leftMost->right = toRemove->right;
                }
                leftMost->left = toRemove->left;

                if (parent->left == toRemove) {
                    parent->left = leftMost;
                }
                else {
                    parent->right = leftMost;
                }

                toRemove->left = toRemove->right = NULL;

                delete toRemove;
            }
        }

        // Search Right
        else if (toRemove->data < item) {
            parent = toRemove;
            toRemove = toRemove->right;
        }

        // Search Left
        else {
            parent = toRemove;
            toRemove = toRemove->left;
        }
    }

}

template<class Base>
string EncryptionTree<Base>::encrypt(const Base &item) const {
    const BSTNode<Base> *cur = this->root;
    string path = "r";

    while (cur != NULL) {

        // Equivalent comparison that returns path
        if (!(cur->getData() < item) && !(item < cur->getData())) {
            return path;
        }

        // Traverses left and adds 0
        else if (item < cur->getData()) {
            cur = cur->getLeft();
            path += "0";
        }

        // Traverses right and adds 1
        else if (cur->getData() < item) {
            cur = cur->getRight();
            path += "1";
        }
    }

    // If not found, returns ? for invalid word
    return "?";
}

template<class Base>
const Base *EncryptionTree<Base>::decrypt(const string &path) const {
    const BSTNode<Base> *cur = this->root;
    queue<char> decrypt;

    for (int i = 0; i < path.size() - 1; i++) {
        decrypt.push(path.at(i));
    }

    while (!decrypt.empty()) {
        if (decrypt.front() == 'r') {
            cur = this->root;
            decrypt.pop();
        }
        else if (decrypt.front() == '0') {
            cur = cur->getLeft();
            decrypt.pop();
        }
        else if (decrypt.front() == 1) {
            cur = cur->getRight();
            decrypt.pop();
        }
        else {
            cur = NULL;
        }
    }

    return cur->getData();
}


#endif

