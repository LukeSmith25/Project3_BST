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

/* Place your implementation of the BSTNode, BST, and EncryptionTree classes
 * here.
 *
 * Your driver should #include this file, which (as you can see above) will also
 * #include the professor file.
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

template<class Base>
void BSTNode<Base>::printPreorder(ostream &os, string indent) const {
    if (this) {
        os << indent << getData() << endl;
        indent += "  ";
        getLeft()->printPreorder(os, indent);
        getRight()->printPreorder(os, indent);
    } else {
        os << indent << "NULL" << endl;
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

    // If the root is null then assign root to item
    if (!root) {
        root = node;
        return;
    }
    // Create a previous and temporary node for iteration
    BSTNode<Base> *par = NULL;
    BSTNode<Base> *cur = root;

    // While temp is not null iterate through tree
    while (cur) {
        // If item < temp, temp = left node
        if (item < cur->data) {
            par = cur;
            cur = cur->left;
        }
        // If item > temp, temp = right node
        else if (cur->data < item) {
            par = cur;
            cur = cur->right;
        }
    }

    // Insert new node at location left or right
    if (!par->left) {
        par->left = node;
    } else {
        par->right = node;
    }
}

template<class Base>
void BST<Base>::remove(const Base &item) {
    BSTNode<Base> par = NULL;
    BSTNode<Base> cur = this->root;
    // IF KEY < VALUE && VALUE < KEY
    while (cur != NULL) {
        if (cur->data == item) {

            // Delete Leaf Node
            if (cur->getLeft() == NULL && cur->getRight() == NULL) {
                if (par == NULL) {
                    root = NULL;
                    delete cur;
                } else if (par->getLeft() == cur) {
                    par->left = NULL;
                    delete cur;
                } else {
                    par->right = NULL;
                    delete cur;
                }
            }

            // Delete node with only left child
            else if (cur->getRight() == NULL) {
                if (par == NULL) {
                    root = cur.getLeft();
                    delete cur;
                } else if (par->getLeft() == cur) {
                    par->left = cur.getLeft();
                    delete cur;
                } else {
                    par->right = cur.getRight();
                    delete cur;
                }
            }

            // Delete node with only right child
            else if (cur.getLeft() == NULL) {
                if (par == NULL) {
                    root = cur.getRight();
                    delete cur;
                } else if (par.getLeft() == cur) {
                    par->left = cur.getRight();
                    delete cur;
                } else {
                    par->right = cur.getLeft();
                    delete cur;
                }
            }

            // Remove node with two children
            else {
                BSTNode<Base> suc = cur;
                while (suc.getLeft() != NULL) {
                    suc = suc.getLeft();
                }
            }

        }
    }
}

template<class Base>
string EncryptionTree<Base>::encrypt(const Base &item) const {
    return std::string();
}

template<class Base>
const Base *EncryptionTree<Base>::decrypt(const string &path) const {
    return nullptr;
}


#endif

