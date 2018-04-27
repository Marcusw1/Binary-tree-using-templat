/*************************************  
* Marcus Wong
* 911536579
* Marcusw1@mail.sfsu.edu
* xcode 6.2
*************************************/


#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  public:
    Node();
    Node( T );
    ~Node();


    T data;
    Node<T> *left;
    Node<T> *right;
};

// Implement this
template <typename T>
Node<T>::Node() {
  left = NULL;
  right = NULL;
}

template <typename T>
Node<T>::Node( T value ) {

	data = value;
	left = NULL;
	right = NULL;
}

template <typename T>
Node<T>::~Node() {

}

#endif