//
//  DoubleList.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/9/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

#include "../MegaData/DoubleList.hpp"
#include "../MegaData/DoublyLinkedList.hpp"
#include "../Model/BiDirectionalNode.hpp"


template <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
};

template <class Type>
DoubleList<Type> :: DoubleList() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
DoubleList<Type> :: ~DoubleList()
{
    BiDirectionalNode<Type> * deleteStructure = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete deleteStructure;
        deleteStructure = this->getFront();
    }
}

template <class Type>
void DoubleList<Type> :: add(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
    }
    else
    {
        this->getEnd()->setNextPointer(addedNode);
        addedNode->setPreviousPointer(this->getEnd());
    }
    this->setEnd(addedNode);
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    Type derp;
    BiDirectionalNode<Type> * nodeToTakeOut = this->getFront();
    for(int spot = 0; spot < index; spot++)
    {
        nodeToTakeOut = nodeToTakeOut->getNextPointer();
    }
    derp = nodeToTakeOut->getNodeData();
    
    if(this->getSize() > 1)
    {
        BiDirectionalNode<Type> * prev = nodeToTakeOut->getPreviousPointer();
        BiDirectionalNode<Type> * next = nodeToTakeOut->getNextPointer();
    
        prev->setNextPointer(next);
        next->setPreviousPointer(prev);
        
        if(index == 0)
        {
            this->setFront(this->getFront()->getNextPointer());
        }
        else if(index == this->getSize() - 1)
        {
            this->setEnd(this->getEnd()->getPreviousPointer());
        }
    }
    else
    {
        this->setFront(nullptr);
        this->setEnd(nullptr);
    }
    delete nodeToTakeOut;
    
    this->setSize(this->getSize() - 1);
    return derp;
}

template <class Type>
Type DoubleList<Type> :: getFromIndexFast(int index)
{
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() / 2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference->getNextPointer();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this->getSize() - 1; position > index; position--)
        {
            reference = reference->getPreviousPointer();
        }
    }
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}


#endif /* DoubleList_h */
