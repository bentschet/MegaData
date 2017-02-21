//
//  List.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 2/21/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef List_h
#define List_h

#include <assert.h>

using namespace std;

template <class Type>
class List
{
private:
    int size;
    Node<Type> * front;
public:
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    bool contains(Type data);
    int getSize() const;
    Node<Type> * getFront() const;
    
};

#endif /* List_h */
