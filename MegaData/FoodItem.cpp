//
//  FoodItem.cpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 3/27/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#include <stdio.h>
#include "FoodItem.hpp"
#include <string>


bool FoodItem :: isDelicious()
{
    return delicious;
}

void FoodItem :: setCalories(int calories)
{
    this->calories = calories;
}

void FoodItem :: setCost(double cost)
{
    this->cost = cost;
}

void FoodItem :: setFoodName(string foodName)
{
    this->foodName = foodName;
}

bool FoodItem :: operator < (FoodItem & otherFood)
{
    if(this->isDelicious() && otherFood.isDelicious())
    {
        if(this->getCalories() > otherFood.getCalories())
        {
            return true;
        }
        return false;
    }
    return false;
}

