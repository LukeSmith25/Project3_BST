/**
 * file: bst-student-proj3.h
 * author: Luke Smith
 * course: CSI 3334
 * assignment: project 3
 * due date: October 2, 2022
 *
 * This file contains the implementation for the BSTNode, BST, and Encryption/
 * Decryption classes.
 */

#ifndef BST_STUDENT_PROJ3
#define BST_STUDENT_PROJ3 

#include "bst-prof-proj3.h"
#include <queue>
#include <string>

/**
 * BSTNode Destructor
 *
 * This function is the default destructor for a BSTNode.
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
 * This function recursively traverses the tree and prints it in preorder.
 *
 * Parameters:
 *      -os: output stream containing preorder traversal
 *      -indent: indentation representing depth of node in tree
 *
 * Return value: void.
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

/**
 * minNode
 *
 * This function returns the leftmost node.
 *
 * Parameters: None.
 *
 * Return value: Leftmost BSTNode.
 */
template<class Base>
const BSTNode<Base> *BSTNode<Base>::minNode() const {
    if (getLeft() != NULL) {
        getLeft()->minNode();
    } else {
        return this;
    }
}

/**
 * maxNode
 *
 * This function returns the rightmost node.
 *
 * Parameters: None.
 *
 * Return value: Rightmost BSTNode.
 */
template<class Base>
const BSTNode<Base> *BSTNode<Base>::maxNode() const {
    if (getRight() != NULL) {
        getRight()->maxNode();
    } else {
        return this;
    }
}

/**
 * insert
 *
 * This function searches and inserts node into BST.
 *
 * Parameters:
 *      item: item to be inserted into tree
 *
 * Return value: void.
 */
template<class Base>
void BST<Base>::insert(const Base &item) {
    // Create a previous and temporary node for iteration
    BSTNode<Base> *par = NULL;
    BSTNode<Base> *child = this->root;

    // While child is not null iterate through tree
    while (child) {
        par = child;

        // If item == par
        if (!(item < child->getData()) && !(child->getData() < item)) {
            return;
        }
        // If item < temp, temp = left node
        else if (item < child->data) {
            child = child->left;
        }
        // If item > temp, temp = right node
        else {
            child = child->right;
        }
    }
    // Declare new node to be inserted
    BSTNode<Base> *newNode = new BSTNode<Base>(item);

    // If the root is null then assign root to item
    if (!root) {
        this->root = newNode;
    }
    // Insert new node at location left
    else if (item < par->getData()) {
        par->left = newNode;
    }
    // Insert new node at location right
    else {
        par->right = newNode;
    }
}

/**
 * remove
 *
 * This function searches and removes a node from the BST.
 *
 * Parameters:
 *      item: item to be removed
 *
 * Return value: None.
 */
template<class Base>
void BST<Base>::remove(const Base &item) {
    BSTNode<Base> *toRemove = this->root;

    if (!toRemove) {
        return;
    }

    BSTNode<Base> *parent = NULL;

    while (toRemove) {
        // If item is found
        if (!(toRemove->getData() < item) && !(item < toRemove->getData())) {
            break;
        }
        // Move Parent
        parent = toRemove;
        // If item is less than toRemove, search left
        if (item < toRemove->getData()) {
            toRemove = toRemove->left;
        }
        // If item is greater than toRemove, search right
        else if (toRemove->getData() < item) {
            toRemove = toRemove->right;
        }
        // If item is not found
        else {
            return;
        }
        if(!toRemove){
            return;
        }
    }

    // Remove leaf node
    if (toRemove->left == NULL && toRemove->right == NULL) {
        if (root == toRemove) {
            root = NULL;
        }
        else if (parent->left == toRemove) {
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
        if (root == toRemove) {
            root = grandChild;
        }
        else if (parent->left == toRemove) {
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

        if (root == toRemove) {
            root = leftMost;
        }
        else if (parent->left == toRemove) {
            parent->left = leftMost;
        }
        else {
            parent->right = leftMost;
        }

        toRemove->left = toRemove->right = NULL;

        delete toRemove;
    }
}

/**
 * encrypt
 *
 * This function encrypts a cleartext message
 *
 * Parameters:
 *      item: encrypts item passed in based on the node's location in BST.
 *
 * Return value:
 *      string: string containing encrypted node locations.
 */
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

/**
 * decrypt
 *
 * This function decrypts a BST with encrypted string passed in.
 *
 * Parameters:
 *      path: string representing encrypted path in BST.
 *
 * Return value:
 *      Base: corresponding key to encrypted data.
 */
template<class Base>
const Base *EncryptionTree<Base>::decrypt(const string &path) const {
    const BSTNode<Base> *cur = this->root;

    for (int i = 0; i < path.size(); i++) {
        if (path.at(i) == 'r') {
            cur = this->root;
        } else if (path.at(i) == '0') {
            cur = cur->getLeft();
        } else if (path.at(i) == '1') {
            cur = cur->getRight();
        } else {
            cur = NULL;
            break;
        }
        if (cur == NULL) {
            return NULL;
        }
    }
    return &(cur->getData());
}


#endif

