#pragma once
#define MAX_SET_SPEED 100 // max run speed
#define RUN_SPEED 100 // current run speed
#define RAW_MAX_SPEED 1300 // Max speed of motors
#define RAW_RUN_SPEED (RUN_SPEED * (RAW_MAX_SPEED / MAX_SET_SPEED)) // actual motor speed

class Controller {
public:
	void FollowLine();
	Controller() {} // a reference should be passed to the constructor with the wheels and sensors
	~Controller() {}


private:
	int lkp, lki, lkd, rkp, rki, rkp;

	int GetDirection();
};
