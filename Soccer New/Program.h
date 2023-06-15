#pragma once
#include <chrono>
#include <iostream>

class Program
{
public:
	void Run();

private:
	void RunMotors(int speed, int heading, int turn); //Pass by ref passes 4 bytes, which is same as int. If on x64 then it passes 8 bytes
	int CalcHeading();
	void CalcTurn();

	int headings[9] = {-135,-90,-60,-30,0,30,60,90,135};

	std::chrono::steady_clock::time_point timer;

	int zone;
	int lastZone = 0;
	int deltaTime = 0;

	int turn = 0;

	int o1;
	float m1;

	int o2;
	float m2;

	int o3;
	float m3;



	//api functions
#define OUT_A 1
#define OUT_B 2
#define OUT_C 3
#define OUT_D 4

#define NXT_IR_SEEKER 'n'

	void InitEv3() { };
	void FreeEv3() { };
	void OnFwdReg(int output, int speed) { };
	void setAllSensorMode(char = 'a', char = 'a', char = 'a', char = 'a') { };
	int readSensor(int sensor = 0) { return 5; };
};

