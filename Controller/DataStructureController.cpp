//
//  DataStructureController.cpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 2/8/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../model/IntNode.hpp"
using namespace std;

DataStructureController :: DataStructureController()
{
    
}

void DataStructureController :: start()
{
    cout << "Starting the project" << endl;
    cout << "Switching to the array testing" << endl;
    testIntArray();
    cout << "Finished testing" << endl;
    
}

void DataStructureController :: testIntArray()
{
    cout << "Testing the array" << endl;
}
