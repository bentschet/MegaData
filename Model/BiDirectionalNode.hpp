//
//  BiDirectionalNode.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 2/27/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

#include "BiDirectionalNode.hpp"
#include "Node.hpp"

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    BiDirectionalNode<Type> * previous;
    BiDirectionalNode<Type> * next;
    Type nodeData;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, ::BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next);
};

template<class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>()
{
    
}

BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>(data)
{
    
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getNextPointer()
{
    return this->nextPointer;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getPreviousPointer()
{
    return this->previous;
}



#endif /* BiDirectionalNode_h */
