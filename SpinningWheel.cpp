/*
 *  SpinningWheel.cpp
 *  110clab2
 *
 *  Created by lucas on 10/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "SpinningWheel.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int SpinningWheel::spin()
{
    srand(time(NULL));

    //Random number of positions the wheel moves through (22 - 42)
    int moves = rand()%22+20;

    for (int moved = 0; moved <= moves; moved++)
    {
        if(currentIndex > 19)
        {
            currentIndex = currentIndex%20;
            cout << wheel[currentIndex] << " ";
        }
        else
        {
            cout << wheel[currentIndex] << " ";
        }

        currentIndex++;
    }

    //cout << "\nMoves: " << moves << "\n";

    //currentIndex-1 accounts for the final incrementation of currentIndex in the for loop
    return wheel[currentIndex-1];
}


SpinningWheel::SpinningWheel() //constructor that initializes wheel components
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++) 
	{
		int random = rand() % 20 +1;
		wheel[i] = random * 5;
	}
	currentIndex = 0;
	 
}

int SpinningWheel::getIndex()
{
	return currentIndex;
}

int SpinningWheel::getValueAt(int index)
{
	return wheel[index];
}

void SpinningWheel::display()
{
	for (int i = 0; i < 20; i++) 
	{
		cout << wheel[i] << " ";
	}
	cout << endl;
}

