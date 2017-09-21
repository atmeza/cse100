#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

public:

    /** Constructor.  Initialize a BSTNode with the given Data item,
     *  no parent, and no children.
     */
    BSTNode(const Data & d) : data(d) {
        left = right = parent = 0;
    }

    BSTNode<Data>* left;
    BSTNode<Data>* right;
    BSTNode<Data>* parent;
    Data const data;   // the const Data in this node.

    /** Return the successor of this BSTNode in a BST, or 0 if none.
     ** PRECONDITION: this BSTNode is a node in a BST.
     ** POSTCONDITION:  the BST is unchanged.
     ** RETURNS: the BSTNode that is the successor of this BSTNode,
     ** or 0 if there is none.
     */ // 
    BSTNode<Data>* successor() {

        if(parent==0&&right==0){

            return 0; // there is no successor if no right or parent
        }

        if(right!=0){//right is the successor so return if it exists
            
            auto temp = right;
            while(temp->left!=0){//while has a left subtree
            
                temp = temp->left;
            }
            return temp;
        }

        auto temp = this;// if suc exists then it is in the "upper" levels

        while(temp->parent->right==temp){// while temp is a right subtree


            if(0==temp->parent->parent){//if there is no parent of the parent 
                return 0; // reached root without finding
            }

            temp = temp->parent; // temp is not the root so check parent
        }

        return temp->parent;//successor found
    }
}; 
/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
    stm << '[';
    stm << std::setw(10) << &n;                 // address of the BSTNode
    stm << "; p:" << std::setw(10) << n.parent; // address of its parent
    stm << "; l:" << std::setw(10) << n.left;   // address of its left child
    stm << "; r:" << std::setw(10) << n.right;  // address of its right child
    stm << "; d:" << n.data;                    // its data field
    stm << ']';
    return stm;
}

#endif // BSTNODE_HPP
