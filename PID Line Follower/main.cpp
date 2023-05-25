#include <iostream>
#include "Header.hpp"

int main() {
	//Define wheels and sensors here, then pass them to the controller contstructor
	bool running = true;
	Controller* controller = new Controller(); //pass reference to wheels and sensors


	while (running) 
	{
		//Main Loop
		controller->FollowLine();
	}
	
	return 0;
}