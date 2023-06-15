#include "Program.h"

int main() {
	while (true)
	{
		try
		{
			Program program; // don't use pointer to avoid allocating the class on the heap
			program.Run();
			break;
		}
		catch (...)
		{
			//if an exception is caught, the program will restart
			//this is bad, but is a safety net just in case something goes wrong, so that the robot doesn't just stop
		}
	}

	return 0;
}