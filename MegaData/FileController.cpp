//
//  FileController.cpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/29/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#include <stdio.h>
#include "FileController.hpp"
#include "DoublyLinkedList.hpp"
#include "FoodItem.hpp"
#include <iostream>
#include <string>

using namespace std;

DoubleList<FoodItem> FileController :: readFoodItemDataFromFileAsList(string filename)
{
    DoubleList<FoodItem> dataSource;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            stringstream parseCSV(currentCSVLine);
            
            string title, tempCost, tempCalorie, tempTasty;
            
            double cost;
            int calories;
            bool isDelicious;
            
            getline(parseCSV, title, ',');
            getline(parseCSV, tempCost, ',');
            getline(parseCSV, tempCalorie, ',');
            getline(parseCSV, tempDelicious, ',');
            
            if (rowCount != 0)
            {
                
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return dataSource;
}

void FileController :: writeFoodItemDataStatistics(DoubleList<FoodItem> dataSource, string filename);
{
    ofstream saveFile(filename);
    
    if(saveFile.is_open())
    {
        saveFile << "These are the contents of the list" << endl;
        for(int index = 0; index < dataSource.getSize(); index++)
        {
            saveFile << "Food Title: " << dataSource.getFromIndex(index.getFoodName() << endl;
        }
    }
    else
    {
        cerr << "File unavailable" << endl;
    }
    saveFile.close();
    
}
