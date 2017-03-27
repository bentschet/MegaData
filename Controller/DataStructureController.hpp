//
//  DataStructureController.hpp
//  MegaData
//
//  Created by Tschetter, Benjamin on 2/8/17.
//  Copyright © 2017 Tschetter, Benjamin. All rights reserved.
//

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Node.hpp"
#include "../Model/Array.hpp"
#include "../MegaData/DoubleList.hpp"
#include "../MegaData/CircularList.hpp"
#include <string>


using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    void testNodes();
    void testAdvancedFeatures();
    void testListIntro();
    void testNodeType();
    void testArrayTemplate();
    void testDestructor();
    void testDoubleLists();
    void testListTiming();
public:
    DataStructureController();
    void start();
    
};

void DataStructureController :: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for (int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow = averageSlow/1000.00;
    averageFast = averageFast/1000.00;
    totalTimer.stopTimer();
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds." << endl;
    cout << "The average speed for the getFromIndexFast method was: " << averageFast << " microseconds." << endl;
}

#endif /* DataStructureController_hpp */
