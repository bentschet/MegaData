//
//  Queue.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/7/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "DoublyLinkedList.hpp"

template <class Type>
class Queue : public DoublyLinkedList<Type>
{
private:
public:
    Queue();
    ~Queue();
    void add(Type data);
    Type remove(int index);
    void enqueue(Type data);
    Type dequeue();
    Type peek();
}

template <class Type>
Queue<Type> :: Queue() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
Queue<Type> :: ~Queue()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}

template <class Type>
void Queue<Type> :: add(Type value)
{
    enqueue(value);
}

template <class Type>
void Queue<Type> :: enqueue(Type insertedValue)
{
    BiDirectionalNode<Type> * added = new BiDirectionalNode<Type>(insertedValue);
    
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(added);
    }
    else
    {
        this->getEnd()->setNextPointer(added);
        added->setPreviousPointer(this->getEnd());
    }
    this->setEnd(added);
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type Queue<Type> :: remove(int index)
{
    assert(index == 0 && this->getSize() > 0);
    return dequeue();
}

template <class Type>
Type Queue<Type> :: dequeue()
{
    assert(this->getSize() > 0);
    
    Type removedValue = this->getFront()->getNodeData();
    BiDirectionalNode<Type> * removeMe = this->getFront();
    
    if(this->getSize() == 1)
    {
        this->setEnd(nullptr);
        this->setFront(nullptr);
    }
    else
    {
        this->setFront(removeMe->getNextPointer());
    }
    this->setFront()->setPreviousPointer(nullptr);
    
    delete removeMe;
    this->setSize(this->getSize() - 1);
    
    return removedValue;
}

template <class Type>
Type Queue<Type> :: peek()
{
    assert(this->getSize() > 0);
    
    return this->getFront()->getNodeData();
}


#endif /* Queue_h */
