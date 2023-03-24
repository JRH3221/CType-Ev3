#include "Benchmark.h"
#include <thread>
#include "main.cpp"
#include <Windows.h>

Benchmark::Benchmark() {
	//std::thread main_thread(SystemOut);
}

void Program::SystemOut(){
	Program* program = new Program;

	while (true) {
		system("cls");
		std::cout << "Back wheel speed: " << program->M1 << '\n' << "Right Wheel Speed: " << program->M2 << '\n' << "Left Wheel Speed: " << program->M3 << std::endl;
		Sleep(1000);
	}
}
