// Testing.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Disassembler.h"

int disassemblerTest() {
	const char* tetrisPath = "C:\\Users\\Justyn Duthler\\Desktop\\Game-Boy-Emulator\\Roms\\Tetris.gb";
	if (gbDisassembler(tetrisPath)) {
		return 0;
	}
	else {
		return 1;
	}
}
int main()
{
	int testsPassed = 0;
	int totalTests = 0;
	/*---------- disassembler testing ---------- */
	std::cout << "----Disassembler.cpp Testing----\n";
	totalTests += 1;
	if (disassemblerTest() == 0) {
		std::cout << "Pass\n\n";
		testsPassed += 1;
	}
	else {
		std::cout << "Failed\n\n";
	}

	std::cout << testsPassed << "/" << totalTests << " tests passed\n";
	return 0;
}