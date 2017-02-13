//
//  DataStructureController.cpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 2/8/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/IntNode.hpp"
using namespace std;

DataStructureController :: DataStructureController()
{
    wordNode = Node<string>("datboi");
    numberNode = Node<int>();
}

void DataStructureController :: testNodes()
{
    cout << "the contents of the Node<string>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}

void DataStructureController :: start()
{
    cout << "Switching to the IntNodeArray testing" << endl;
    testNodes();
    cout << "Finished testing" << endl;
    
}

void DataStructureController :: testIntArray()
{
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 4; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot "<< index << endl;
    }
    
    cout << "Testing input" << endl;
    
    for(int index = 0; index < 3; index++)
    {
        temp.setAtIndex(index, index);
    }
    
    for(int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << "is at spot "<< index << endl;
    }
}
