//
//  CircularList.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/1/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : DoublyLinkedList<Type>
{
private:
    //dont have to redefine private data members
public:
    CircularList();
    ~CircularList();
    
    void add(Type data);
    Type remove(int index);
    //Other methods as needed
    
};

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{
    //deal with circle list here
    
}

template <class Type>
void CircularList<Type> :: add(Type data)
{
    
}



#endif /* CircularList_h */
