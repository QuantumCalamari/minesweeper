#define WINDOW_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <strsafe.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>

//square dimensions:	(540) 1209 - 1749, (288) 747 - 459
//each box is 18x18.  I imagine a thread running through each with a point in the middle
//they're treated as a continuous array

class window {

public:
	static void LeftClick()
	{
		INPUT    Input = { 0 };
		// left down 
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		::SendInput(1, &Input, sizeof(INPUT));

		// left up
		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		::SendInput(1, &Input, sizeof(INPUT));
	}

public: static void initGuess(int width, int height, int x, int y) {

	

	double m = 18;
	/*
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "x: " << 1047 + x * m << std::endl;
	std::cout << "y: " << 456 + y * m << std::endl;
	*/
	//SetCursorPos(1415, 521);
	SetCursorPos((1251 + x * m), (477 + y * m));

	LeftClick();
}

public:
	static void nextMove(int x, int y) {
		double m = 18;
		SetCursorPos((1251 + x * m), (477 + y * m));
		LeftClick();
	}

};