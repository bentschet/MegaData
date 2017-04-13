//
//  BinarySearchTree.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 4/13/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.hpp"
//#include "BinarySearchTreeNode.hpp"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreenode<Type> * root);
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * getRoot();
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal;
    
    void printToFile;
    void demoTraversalSteps(BinarySearchTreeNode<Type> * node);
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
}

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
    {
        this->root = nullptr;
    }
    
template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
    {
        BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
        BinarySearchTreeNode<Type> * previous = nullptr;
        BinarySearchTreeNode<Type> * current = root;
        
        if(current == nullptr)
        {
            root = insertMe;
        }
        else
        {
            while(current != nullptr)
            {
                previous = current;
                if(itemToInsert < current->getNodeData())
                {
                    current = current->getLeftchild();
                }
                else if(itemToInsert > current->getNodeData())
                {
                    current = current->getRightChild();
                }
                else
                {
                    cerr << "Item exists already - Exiting" << endl;
                    delete insertMe;
                    return;
                }
            }
            
            if (previous->getNodeData() > itemToInsert)
            {
                previous->setLeftChild(insertMe);
            }
            else
            {
                previous->setRightChild(insertMe);
            }
            insertMe->setRootPointer(previous);
        }
    }



#endif /* BinarySearchTree_h */
