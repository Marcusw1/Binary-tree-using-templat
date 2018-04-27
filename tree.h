/*************************************  
* Marcus Wong
* 911536579
* Marcusw1@mail.sfsu.edu
* xcode 6.2
*************************************/

#ifndef __TREE_H__
#define __TREE_H__


#include <iostream>
#include <string>
#include "node.h"

using namespace std;

template <typename T>
class Tree {

  private:
   Node<T> *root;

   bool if_contains ( Node <T>* , T );
  
   void remove_root();
   void search_and_remove ( Node <T>*, T );

   bool check_fullness( Node<T>* );
   int get_height( Node <T>* );

    
  //traversal helpers
   void preordertraversal( Node <T>* ); 
   void inordertraversal ( Node <T>* );
   void postordertraversal( Node <T>* );

  public:
  	Tree();
   ~Tree();

   void insert( T );
   bool contains( T );
   void remove( T );
   bool isFull();
   int height();

   //traversal
   void preorder();
   void inorder();
   void postorder();
};

template <typename T>
Tree<T>::Tree() {
  root = NULL;
}



template <typename T>
Tree<T>::~Tree() {
  if ( root != NULL ) {
    delete root;
  }
}


template <typename T>
void Tree<T>::insert( T value ) {
	
  Node<T> *temp, *parent;

  //case 1 , if empty
  if ( root == NULL ){
    
    root = new  Node <T>();
    root->data = value;

  return;
  }//..end case 1
  

  //case 2, if not empty
  //traverse tree, find place for new node
  else{

    temp = root;

      while ( temp != NULL ){
        if( value < temp->data ){
           parent = temp;
           temp = temp->left;
        } else {
          parent = temp;
          temp = temp->right;
        }
      }

  //inserting new node and value
   Node<T> *newNode = new Node <T>();
   newNode->data = value;
   newNode->left = NULL;
   newNode->right = NULL;
   
   if( value <= parent->data ) {
     parent->left = newNode;
   } else {
    parent->right = newNode;
   }
  }//..end case 2

return;
}//..end insert




//contain functions
template <typename T>
bool Tree<T>::contains( T value ) {
  bool containsValue;
  containsValue = if_contains( root, value );
  return containsValue;
}

template <typename T>
bool Tree<T>::if_contains( Node<T>* tree, T value ) {
  
  //if empty
  if ( root == NULL ) {
    return false;
  }
  //if not empty
  else {

    if ( value == tree->data ) 
      return true;
    if ( value < tree->data )
      return if_contains ( tree->left, value );
    if ( value > tree->data )
      return if_contains ( tree->right, value );
  }
  return false;
}
//..end contain



//remove functions
template <typename T>
void Tree<T>::remove( T value ) {
   
   if ( root == NULL ) 
    return;
   
   if ( root->data == value )
    remove_root();

   else 
    search_and_remove ( root, value );
}

template <typename T>
void Tree<T>::remove_root() {

 Node<T>* target = root;
 //T key = root->data;
 //T newRootKey;

 //case 1: root has no chidren
  if ( root->left == NULL && root->right == NULL ) {
    root = NULL;
    delete target;
    return;
  }

 //case 2: root has one child
  if ( root->left != NULL && root->right == NULL ) {

    root = root->left;
    target->left = NULL;
    delete target;
    return;
  }

   if ( root->left == NULL && root->right != NULL ) {

    root = root->right;
    target->right = NULL;
    delete target;
    return;
  }

 //case 3: root has two childrens

  if ( root->left != NULL && root->right != NULL ) {
    
  }


}

template <typename T>
void Tree<T>::search_and_remove( Node<T> *tree, T value ) {
 
  return;
 }

//..end remove



//isFull functions
template <typename T>
bool Tree<T>::isFull() {

	return check_fullness(root);
}

template <typename T>
bool Tree<T>::check_fullness( Node<T> *tree ) {
 
   if ( tree == NULL ) 
    return true;
  if ( tree->left == NULL && tree->right == NULL )
    return true;
  if ( (tree->left) && (tree->right) )
    return ( check_fullness(tree->left) && check_fullness(tree->right) );
  return false;
}
//..end isFull



//height functions 
template <typename T>
int Tree<T>::get_height( Node<T> *tree ) {

if (tree == NULL)
    {
        return 0;
    }

    int left = get_height(tree->left);
    int right = get_height(tree->right); 

    if (left > right)
        return 1 + left;
    else
        return 1 + right;
}

template <typename T>
int Tree<T>::height() {

  int height;
  height = get_height(root);
  return height;
}
//..end height



//---------- traversal functions -----------//

//preorder functions
template <typename T>
void Tree<T>::preorder() {	
  preordertraversal( root );
  cout << endl;
}
template <typename T>
void Tree<T>::preordertraversal( Node <T>* tree ) {

    if (!tree) return;
 cout << tree->data << " ";
  preordertraversal(tree->left);
  preordertraversal(tree->right);
}
//..end preorder




//inorder functions
template <typename T>
void Tree<T>::inorder() {
  inordertraversal( root );
  cout << endl;
}

template <typename T>
void Tree<T>::inordertraversal( Node <T>* tree ) {

    if (!tree) return;
  inordertraversal(tree->left);
  cout << tree->data << " ";
  inordertraversal(tree->right);
}
//..end inorder




//postorder functions
template <typename T>
void Tree<T>::postorder() {
  postordertraversal( root );
  cout << endl;
}

template <typename T>
void Tree<T>::postordertraversal( Node <T>* tree) {
    if (!tree) return;
  postordertraversal(tree->left);
  postordertraversal(tree->right);
  cout << tree->data << " ";
}
//..end postorder

#endif