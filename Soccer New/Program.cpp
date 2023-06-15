#include "Program.h"
#include <cmath>
#include <thread>
#include <Windows.h> //remove in final

#define BACK_WHEEL 180
#define RIGHT_WHEEL 300
#define LEFT_WHEEL 60
#define RAD (3.1416/180)

void Program::Run() 
{
	InitEv3();
	setAllSensorMode(NXT_IR_SEEKER);

	//std::thread turnThread(Program::CalcTurn);

	timer = std::chrono::high_resolution_clock::now();
	while (true) {
		RunMotors(100, CalcHeading(), turn);
		Sleep(500); //remove in final
	}


	FreeEv3();
}

void Program::CalcTurn() 
{
	while (true) 
	{

	}
}

int Program::CalcHeading() 
{
	deltaTime = (int)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();
	zone = readSensor(0); //return 1-9

	//if the zone changes
	if (zone != lastZone) 
	{
		if (deltaTime < 1000) 
		{
			//it's been less than a second since the zone changed
			int span = 1000 - deltaTime;
			timer = std::chrono::high_resolution_clock::now();
			return (headings[zone - 1] * span/100);
		}
		else 
		{
			timer = std::chrono::high_resolution_clock::now();
			return (headings[zone - 1]);
		}
	}
	else
	{
		if (deltaTime > 2000) 
		{
			//add 10 degrees for every second
			if (headings[zone - 1] > 0) {
				return (int)std::round(headings[zone - 1] + (deltaTime / 100));
			}
			else if (headings[zone - 1] < 0) 
			{
				return (int)std::round(headings[zone - 1] - (deltaTime / 100));
			}
			else 
			{
				return headings[zone - 1];
			}
		}
		else
		{
			return headings[zone - 1];
		}
	}
}

void Program::RunMotors(int speed, int heading, int turn) 
{
	std::cout << heading << '\n';
	o1 = (BACK_WHEEL - heading);
	m1 = (float)std::round(speed * std::sin(o1 * RAD));
	m1 += turn;

	o2 = (RIGHT_WHEEL - heading);
	m2 = (float)std::round(speed * std::sin(o2 * RAD));
	m2 += turn;

	o3 = (LEFT_WHEEL - heading);
	m3 = (float)std::round(speed * std::sin(o3 * RAD));
	m3 += turn;

	OnFwdReg(OUT_A, m1);
	OnFwdReg(OUT_B, m2);
	OnFwdReg(OUT_C, m3);
	std::cout << m1 << '\n';
}

