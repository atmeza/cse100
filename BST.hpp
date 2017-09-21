#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */
   virtual ~BST() {
     deleteAll(root);
     root = nullptr;
     isize = 0;
     return;
   }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. ;(should not use ==, >, <=, >=)  For the reasoning
   *  behind this, see the assignment writeup.
   */ // 
  virtual bool insert(const Data& item) {
    // For helpful pseudocode, refer to Paul Kube's
    // 3rd Lecture, 7th slide.
    
    int h;// keep track of height of traversal to compare at end
    if(!root){// if first item being inserted then it is the root

        root = new BSTNode<Data>(item);
        h=1;//increases height of tree by 1
    }
    else{

        auto curr = root;
        
        h= 1; //starts at root so starts at heigh 1

        while(true){
            

            if(item<curr->data){//if item is less than root then belongs in
                                //left subtree
                
                if(!curr->left){
                    
                    curr->left= new BSTNode<Data>(item);//found open place
                    curr->left->parent = curr;                                            //to insert
                    break;
                }
                curr = curr->left;//check left subtree
                h++;// height of this route increases
            }
            else if(curr->data<item){//if belongs in right subtree
                
                if(!curr->right){//if their is an opening on right

                    curr->right = new BSTNode<Data>(item);//put in right
                    curr->right->parent = curr;
                    break;
                }
                curr = curr->right;// if greater belongs in right subtree
                h++;//traversal heigh increases
            }

            else{// else adding a duplicate

                return false;

            }
            

        }

    }
    if(h>iheight){
        
        iheight= h; //height increased due to insertion

    }

    isize++;//if inserted element size of bst increased
    return true;// was able to insert


  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */ // 
  iterator find(const Data& item) const {
    // For helpful pseudocode, refer to Paul Kube's
    // 3rd Lecture, 6th Slide.

    if(!root){

        std::cout<<"test";
        return end(); //empty tree
    }

    auto curr = root;//
    
     while(true){
        
        if(item<curr->data){//if item is less than root then is in
                            //left subtree
            
            if(!curr->left){
                
                return end();
            }
            curr = curr->left;//check left subtree

        }
        else if(curr->data<item){//if current great is in right subtree
            
            if(!curr->right){//if their is an opening on right

                return end();
            }
            curr = curr->right;// if greater is in right subtree
        }

        else{// else found

            return iterator(curr);

        }
        

    }

     
  }


  /** Return the number of items currently in the BST.
   */ // 
  unsigned int size() const {
    return isize;
  }

  /** Return the height of the BST.
   */ // 
  unsigned int height() const {
    return iheight; 
  }


  /** Return true if the BST is empty, else false.
   */ // 
  bool empty() const {
    if(root){
        return false;//if there is a root not empty
    }

    return true;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ // 
  iterator begin() const {

    return iterator(first(root));//return left most nod
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy 
      way to get started.
   */ // 
  void inorder(BSTNode<Data>* n) const {
    /* Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
    */
    if(!n){
        return;//if current node is null
    }

    inorder(n->left);
    std::cout << n->data;
    inorder(n->right);

  }

  /** Find the first element of the BST
   */
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n) {
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */

    if(n == nullptr) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
    n = 0;

  }


 };


#endif //BST_HPP
