#include "Header.hpp"
#include <iostream>

#ifndef GAIN
#define GAIN 1
#endif
#ifndef INTEGRAL
#define INTEGRAL 1
#endif
#ifndef DERIVATIVE
#define DERIVATIVE 1
#endif

#define TARGET_RIGHT 40
#define TARGET_LEFT 40


void Controller::FollowLine() 
{
	GetDirection();
	//Drive using GetDirection() and RAW_RUN_SPEED
}

int Controller::GetDirection()
{
	/// FAKE VALUES
	int rightValue = 40;
	int leftValue = 40;
	///

	//Read left and right sensor
	int leftCurrentError = TARGET_LEFT - leftValue;
	int rightCurrentError = TARGET_RIGHT - rightValue;

	lkp = GAIN * leftCurrentError;
	rkp = GAIN * rightCurrentError;

	lki += (INTEGRAL * leftCurrentError);
	rki += (INTEGRAL * rightCurrentError);

	
}
