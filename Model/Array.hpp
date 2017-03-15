//
//  Array.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 2/15/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//


#ifndef Array_hpp
#define Array_hpp

#include "../Model/Node.hpp"
#include <assert.h>
#include <iostream>

using namespace std;

template <class Type>
class Array
{
private:
    Node<Type> * front;
    int size;
public:
    Array();
    Array(int size);
    // Destructor
    ~Array<Type>();
    // Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    //Helper Methods
    int getSize();
    Node<Type> * getFront() const;
    
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    
};

template <class Type>
Array<Type> :: Array()
{
    //never used
    //Default constructor only supplied to avoid compilation error lol
}

template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    
    this->size = size;
    this->front = new Node<Type>();
    
    for (int index = 1; index < size; index++)
    {
        Node<Type> * current = new Node<Type>();
        current->setNextPointer(front);
        front = current;
    }
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(data);
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index > 0 && index < size);
    Type value;
    Node<Type>* current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
    
    return value;
}

//The const modifier down there means that the method doesn't do anything to the state of the object.

template <class Type>
Type Array<int> :: getSize() const
{
    return size;
}

template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        //moves to next node in array
        front = front->getNodePointer();
        cout << "Moving to the next node. At: " << count << endl;
        //deletes the front pointer
        delete remove;
        cout << "Deleting the old front pointer." << endl;
        //moves delete to the new front.
        remove = front;
        cout << "Moving to the new front pointer." << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    //builds data structure
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * temp = new Node<Type>();
        temp->setNextPointer(front);
        front = temp;
    }
    //Copies values into new Array.
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
    {
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getNodePointer();
        copyTemp = copyTemp->getNodePointer();
    }
}

template <class Type>
Node<Type> * Array<Type> :: getFront() const
{
    return front;
}

#endif /* Array_h */
