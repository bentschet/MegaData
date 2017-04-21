//
//  AVLTree.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 4/19/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinarySearchTreeNode<Type> * leftRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type> * parent);
    
    int heightDifference(BinarySearchTreeNode<Type> * parent);
    
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};

//A negative value means that the right is greater than the left.

template <class Type>
int AVLTree<Type> :: heightDifference(BinarySearchTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateHeight(node->getLeftChild());
    int rightHeight = this->calculateHeight(node->getRightChild());
    balance = leftHeight - rightHeight
    return balance;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation (BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    
    parent ->setLeftChild(changedNode->getRightChild());
    
    changedNode->setRightChild(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightRotation (BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(changedNode->getLeftChild());
    
    changedNode->setLeftChild(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation (BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation (BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    
    parent->setLeftChild(RightRotation(changedNode));
    
    return leftRotation(parent);
}
#endif /* AVLTree_h */
