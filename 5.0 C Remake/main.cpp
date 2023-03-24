#include <iostream>
#include <cmath>
#include <thread>

// Used for run speed calculations of each wheel
#define FRONT_LEFT_WHEEL 60
#define BACK_WHEEL 180
#define FRONT_RIGHT_WHEEL 300

//The reason for the different speeds, is to allow the speed to be changed once for testing, instead of changing every instance of speed
#define MAX_SPEED 100 // this is the highest speed that calc variables will accept, the limit that MAX_SPEED can be set to is 1200, which means you are just setting raw speed
#define RUN_SPEED 50 // (MAX_SPEED) will most likely be used when out of testing
#define SPEED_CONST (1200/MAX_SPEED)
#define PI 3.1416
#define RAD_CONST (PI/180)

// I don't know if header files are accepted, so i will do all class definitions in the main implemenation file for now

class Program {
public:
	void Run(int8_t calcSpeed, int16_t heading, int8_t calcTurn); // calcSpeed and calcTurn are 0-100, they will be processed into raw speed
	bool running = false;

private:
	//Faster Access
	int16_t θ1;
	float M1;

	int16_t θ2;
	float M2;

	int16_t θ3;
	float M3;
};

void Program::Run(int8_t calcSpeed, int16_t heading, int8_t calcTurn) {
	int16_t rawSpeed = calcSpeed * SPEED_CONST; //In final production this can be removed, as all calls to Run() should pass MAX_SPEED, with MAX_SPEED set to 1200


	θ1 = BACK_WHEEL - heading;
	M1 = std::round(rawSpeed * std::sin(θ1 * RAD_CONST)); //using round so there is limited drift due to pi being an approximation
	M1 += calcTurn * SPEED_CONST; //Add rotation, input is 0 - 100

	θ2 = FRONT_RIGHT_WHEEL - heading;
	M2 = std::round(rawSpeed * std::sin(θ2 * RAD_CONST));
	M2 += calcTurn * SPEED_CONST;

	θ3 = FRONT_LEFT_WHEEL - heading;
	M3 = std::round(rawSpeed * std::sin(θ3 * RAD_CONST));
	M3 += calcTurn * SPEED_CONST;
}

int main() { //Entry Point
	Program* program = new Program;

	program->Run(RUN_SPEED, 120, 0);

	return 0;
}