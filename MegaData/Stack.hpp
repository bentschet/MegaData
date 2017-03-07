//
//  Stack.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/7/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToSTack = new BiDirectionalNode<Type>(addedThing);
    
    if(this->getSize() == 0 || this-> getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(addToStack);
    }
    else
    {
        this->getEnd()->setNextPointer(addToStack);
        addToStack->setPreviousPointer(this->getEnd());
    }
    this->setEnd(addToStack);
    this->setSize(this->getSize() + 1);
}

template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}

template <class Type>
Type Stack<Type> :: remove(int index)
{
    assert(index == this->getSize() - 1 && this->getSize() > 0);
    return pop();
}

template <class Type>
Type Stack<Type> :: pop()
{
    assert(this->getSize() > 0);
    Type remove = this->getEnd()->getNodeData();
    
    BiDirectionalNode<Type> * update = this->getEnd();
    update = update->getPreviousPointer();
    
    if(update != nullptr)
    {
        update->setNextPointer(nullptr);
    }
    
    delete this->getEnd();
    
    this->setEnd(update);
    
    this->setSize(this->getSize() - 1);
    
    return removed;
}

template <class Type>
Type Stack<Type> :: peek()
{
    assert(this->getSize() > 0);
    return this->getEnd()->getNodeData();
    
}

#endif /* Stack_h */
