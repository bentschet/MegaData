//
//  FoodItem.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/27/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef FoodItem_h
#define FoodItem_h
#include <string>

using namespace std;

class FoodItem
{
private:
    int calories;
    string foodName;
    double cost;
    bool delicious;
public:
    FoodItem();
    FoodItem(string name);
    
    int getCalories();
    string getFoodName();
    double getCost();
    bool isDelicious();
    
    void setCalories(int calories);
    void setFoodName(string name);
    void setCost(double cost);
    void setDelicious(bool delicious);
    
    bool operator < (FoodItem & otherFood);
    bool operator > (FoodItem & otherFood);
    bool operator == (FoodItem & otherFood);
};

#endif /* FoodItem_h */
