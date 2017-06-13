//#include "stdafx.h"
//#include "user32.dll"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <gdiplus.h>
#include <atlimage.h>
#include <stdio.h>
#include <vector>


#define _stprintf sprintf
#define __T(x) x

#define CetGValue( rgb ) ((BYTE)(((WORD)(rgb)) &gt;&gt; 8))
#define CetBValue( rgb ) ((BYTE)((rgb) &gt;&gt; 16))
#define CetRValue( rgb ) ((BYTE)(rgb))

#include <strsafe.h>

#include "window.h"
#include "colours.h"
#include "scan.h"
#include "solver.h"

COLORREF centerColor;
POINT cent;

//window handler

bool KeyIsPressed(unsigned char k) {
	USHORT status = GetAsyncKeyState(k);
	return (((status & 0x8000) >> 15) == 1) || ((status & 1) == 1);
}

void Save(HWND hWnd)
{
	if (!IsClipboardFormatAvailable(CF_DIB))
		return;
	if (!OpenClipboard(hWnd))
		return;

	HBITMAP hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);

	TCHAR szName[MAX_PATH] = { 0 };
	SYSTEMTIME st = { 0 };
	::GetLocalTime(&st);
	//_stprintf(szName, _T("%02d-%02d-%02d-%03d.bmp"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	sprintf_s(szName, _T("view.bmp"));
	CImage image;
	image.Attach(hBitmap);
	image.Save(szName, Gdiplus::ImageFormatBMP);
	CloseClipboard();
}

void LeftClick()
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

int main(int argc, char* argv[])
{

	int width = 30;
	int height = 16;
	int found = 0;

	int click = 0;
	int clickH = 0, clickW = 0;
	
	//a zero in game array means unclicked
	//a number between 1-8 means clicked
	//a 9 means there's a bomb there
	

	//read out of stuff (created by, purpose, date etc)

	std::cout << "      ____      ____         __       ____       __      _____" << std::endl;
	std::cout << "    /      |  /     |      /   /    /      |   /  /    /   ___/" << std::endl;
	std::cout << "   /   /|  | /  /|  |     /   /    /   /|  |  /  /    /   /_" << std::endl;
	std::cout << "  /   / |  |/  / |  |    /   /    /   / |  | /  /    /    __/" << std::endl;
	std::cout << " /   /  |____ /  |  |   /   /    /   /  |  |/  /    /   /__" << std::endl;
	std::cout << "/__ /            |__|  /__ /    /__ /   |____ /    /______ / \n" << std::endl;
	std::cout << "Minesweeper Solver \n" << std::endl;

	std::cout << "By Scramere\n\n" << std::endl;

	//pause for 5 seconds

	//open minesweeper

	POINT pt;
	RECT wrect;
	HWND GameWindow = 0;
	STARTUPINFO         sInfo;
	PROCESS_INFORMATION pInfo;

	ZeroMemory(&sInfo, sizeof(sInfo));
	sInfo.cb = sizeof(sInfo);
	ZeroMemory(&pInfo, sizeof(pInfo));

	if (CreateProcess("C:\\Program Files\\Microsoft Games\\Minesweeper\\MineSweeper.exe", NULL, NULL, NULL, false, CREATE_NO_WINDOW, NULL, NULL, &sInfo, &pInfo))
	{
		printf("Sleeping 100ms...\n");
		Sleep(100);

		GameWindow = FindWindow(0, "Minesweeper");

		DWORD dwExitCode;
		GetExitCodeProcess(pInfo.hProcess, &dwExitCode);

		CloseHandle(pInfo.hThread);
		CloseHandle(pInfo.hProcess);

	}

	HWND target = GetForegroundWindow();

	//pause for 2 seconds, just to allow the window to open and stuff
	Sleep(2000);	

	//I think this should be contained within the solver
	GetCursorPos(&pt);
	GetClientRect(target, &wrect);
	
	solver::solve(width, height);
	
	//window::initGuess(width, height, xi, yi);
	
	Sleep(1000);

	//create bitmap image of window
	RECT rc;
	HWND hwnd = FindWindow(TEXT("Minesweeper"), NULL);    //the window can't be min
	if (hwnd == NULL)
	{
		std::cout << "it can't find any 'minesweeper' window" << std::endl;
		return 0;
	}
	GetClientRect(hwnd, &rc);

	//create
	HDC hdcScreen = GetDC(NULL);
	HDC hdc = CreateCompatibleDC(hdcScreen);
	HBITMAP hbmp = CreateCompatibleBitmap(hdcScreen, 600, 350);
	SelectObject(hdc, hbmp);

	//Print to memory hdc
	PrintWindow(hwnd, hdc, PW_CLIENTONLY);

	//copy to clipboard
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, hbmp);
	CloseClipboard();

	//release
	DeleteDC(hdc);
	DeleteObject(hbmp);
	ReleaseDC(NULL, hdcScreen);

	std::cout << "success copy to clipboard, please paste it to the 'mspaint'" << std::endl;

	Save(hwnd);

	//D_WORD CF_PNG = RegisterClipboardFormat("PNG");

	std::ifstream myfile;
	myfile.open("C:\\Users\\Jon\\Documents\\Visual Studio 2013\\Projects\\mine\\mine\\view.bmp");

	if (myfile.is_open()) {
		myfile.close();
		std::cout << "function success\n";
	}
	else {
		std::cout << "unable to open file\n";
	}

	//this collects a single pixel from the screen
	HDC hdc_ = GetWindowDC(FindWindow(TEXT("Minesweeper"), NULL));
	//HDC hdc_ = GetDC(GetDesktopWindow());  //I'm not sure if this is right or what exactly it does.

	

	//cent.x = 640;
	//cent.y = 512;
//	for (int y = 0; y < 16; y++) {
	//int y = 5;
	//for (int x = 0; x < 30; x++) {

//		int save = GameBoxes[x][y];

			//std::cout << "x: " << x << std::endl;
			//std::cout << "y: " << y << std::endl;
		//	save = scan::checkOne(x, y, hdc_);
		//	std::cout << "one: " << save << std::endl;
	//		GameBoxes[x][y] = scan::checkColours(x, y, hdc_, GameBoxes[x][y]);
	//		std::cout << "colours: " << GameBoxes[x][y] << std::endl;
			//	scan::checkTwo(9, 5, hdc_);
	//	}
//	}
	bool gameOver = false, end = false;
	int store = 0;
	int c = 0;
	//int row = 0;
	int x = 0, y = 0;
	//parse the data

//std::cout << "game box 1 " << scan::checkColours(1, 0, hdc_, GameBoxes[1]) << std::endl;

	//int iA = (centerColor >> 24) & 0xff;
	
	//std::cout << "Colour =  " << iA << " " << iR << " " << iB << " " << iG << std::endl;

	while (true) {

		if (KeyIsPressed('A')) {
			std::cout << "pressed key" << std::endl;
		//	GetCursorPos(&pt);
			//SetCursorPos(clickW,clickH);
		//	window::initGuess(width, height);
			
			GetClientRect(target, &wrect);
			//	Final argument holds the mouse positions
//			PostMessage(target, WM_LBUTTONDOWN, 0, (pt.x - wrect.left) & ((pt.y - wrect.top) << 16));
//			PostMessage(target, WM_LBUTTONUP, 0, (pt.x - wrect.left) & ((pt.y - wrect.top) << 16));
			LeftClick();
			Sleep(1000);
		}
	}

	system("PAUSE");
	return 0;

}