/*
 *  SpinningWheel.h
 *  110clab2
 *
 *  Created by lucas on 10/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef SPINNING_WHEEL
#define SPINNING_WHEEL

class SpinningWheel 
{ 
	private:
		int wheel[20];
		int currentIndex;
		
	public:
		int spin();
		SpinningWheel(); //constructor that initializes wheel components
		int getIndex();
		int getValueAt(int);
		void display();
};


#endif
