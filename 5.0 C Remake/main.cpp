#include <iostream>
#include <cmath>

// Used for run speed calculations of each wheel
#define FRONT_LEFT_WHEEL 60
#define BACK_WHEEL 180
#define FRONT_RIGHT_WHEEL 300

#define MAX_SPEED 100 // this is the highest speed that calc variables will accept, the limit that MAX_SPEED can be set to is 1200, which means you are just setting raw speed
#define RUN_SPEED 50 // (MAX_SPEED) will most likely be used when out of testing
#define SPEED_CONST (1200/MAX_SPEED)
#define PI 3.1416

// I don't know if header files are accepted, so i will do all class definitions in the main implemenation file for now

class Program {
public:
	void Run(int8_t calcSpeed, int16_t heading, int8_t calcTurn); // calcSpeed and calcTurn are 0-100, they will be processed into raw speed

private:

};

void Program::Run(int8_t calcSpeed, int16_t heading, int8_t calcTurn) {
	int16_t rawSpeed = calcSpeed * SPEED_CONST;


	int16_t θ1 = BACK_WHEEL - heading;
	float M1 = std::round(rawSpeed * std::sin(θ1 * (PI/180))); //using round so there is limited drift due to pi being an approximation

	std::cout << "Back wheel speed: " << M1;
}

int main() { //Entry Point
	Program* program = new Program;

	program->Run(100, 0, 0);

	return 0;
}