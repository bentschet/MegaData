//
//  FileController.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/29/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef FileController_h
#define FileController_h

#include "DoublyLinkedList.hpp"
#include "FoodItem.hpp"
#include "../Controller/CrimeData.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileController
{
private:
    DoubleList<FoodItem> foodItemList;
public:
    DoubleList<FoodItem readFoodItemDataFromFileAsList(string filename);
    void writeFoodItemDataStatistics(DoubleList<FoodItem> source, string filename);
};

#endif /* FileController_h */
