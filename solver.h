#define solver_h
#pragma once

class solver {

public:
	static void solve(int width, int height) {

		int count = 0, biggest = 0, x, y;
		int m = 18;
		bool endGame = false;
		int click;

		std::vector<int> bombs;
		std::vector<int> toClick;
		//these are used in the bombs sorting vector
		int k = 0, z, zz;

		int GameBoxes[480];
		int adj[480];
		int aBomb[480];
		//	int bombs[99];
		//this is needlessly complicated, but I think it might come in handy later so I'll keep it

		int xi = rand() % (width);
		int	yi = rand() % (height);

		xi = 15;
		yi = 6;

		window::initGuess(width, height, xi, yi);

		HWND hwnd = FindWindow(TEXT("Minesweeper"), NULL);
		HDC hdc_ = GetWindowDC(hwnd);
		//	HDC hdc_ = GetDC(GetDesktopWindow());


		HDC hdcScreen = GetDC(NULL);
		HDC hdc = CreateCompatibleDC(hdc_);
		HBITMAP hbmp = CreateCompatibleBitmap(hdc_, 600, 350);
		SelectObject(hdc, hbmp);

		//Print to memory hdc
		PrintWindow(hwnd, hdc, PW_CLIENTONLY);

		//copy to clipboard
		OpenClipboard(NULL);
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, hbmp);
		CloseClipboard();




		for (int i = 0; i < 480; i++) {
			GameBoxes[i] = 0;
			aBomb[i] = 0;
			//there's edge cases and corner cases for 
			if ((i == 0) || (i == 479) || (i == 29) || (i == 450)) {
				adj[i] = 3;
			}
			else if (i < 30) {
				adj[i] = 5;
			}
			else if (i > 450) {
				adj[i] = 5;
			}
			else if ((i % 30) == 0) {
				adj[i] = 5;
			}
			else if (((i - 29) % 30) == 0) {
				adj[i] = 5;
			}
			else {
				adj[i] = 8;
			}
		}

		//while (!endGame) {
		while (count < 35) {
			//click random square to start
			count++;
			click = 0;

			hwnd = FindWindow(TEXT("Minesweeper"), NULL);
			hdc_ = GetWindowDC(hwnd);
			//	HDC hdc_ = GetDC(GetDesktopWindow());


			hdcScreen = GetDC(NULL);
			hdc = CreateCompatibleDC(hdc_);
			hbmp = CreateCompatibleBitmap(hdc_, 600, 350);
			SelectObject(hdc, hbmp);

			//Print to memory hdc
			PrintWindow(hwnd, hdc, PW_CLIENTONLY);

			//copy to clipboard
			OpenClipboard(NULL);
			EmptyClipboard();
			SetClipboardData(CF_BITMAP, hbmp);
			CloseClipboard();
			//parse game board into GB[n]
			//parse the game board into adj[n]

			for (int i = 0; i < 480; i++) {



				//this is a test to see if doing this fixes the fucking annoying negative adjacent issue
				if ((i == 0) || (i == 479) || (i == 29) || (i == 450)) {
					adj[i] = 3;
				}
				else if (i < 30) {
					adj[i] = 5;
				}
				else if (i > 450) {
					adj[i] = 5;
				}
				else if ((i % 30) == 0) {
					adj[i] = 5;
				}
				else if (((i - 29) % 30) == 0) {
					adj[i] = 5;
				}
				else {
					adj[i] = 8;
				}






				//parse to gameboxes array
				if (GameBoxes[i] == 0) {


					GameBoxes[i] = scan::checkColours(i, hdc, GameBoxes[i]);
				}
				//std::cout << "i: " << i << " GB: " << GameBoxes[i] << std::endl;

				//if gameboard[n] is number, and is equal to the adj
				//check the bomb list
				//set the uncheck adj squares to bombs if it isn't found and add to bomb list
				//go back to the start of the lists and start checking again

				//	if ((GameBoxes[i] > 0) && (GameBoxes[i] < 9)) {

				//	if (GameBoxes[i] == adj[i]) {

				//we want to keep a track of how many bombs we've found so that we get them all
				//int count = GameBoxes[i];

			}

			//end of scan

			for (int i = 0; i < 480; i++) {

#include "checkAdj.h";

#include "bombfinder.h";

			}

			for (int i = 0; i < 480; i++) {
				//	#include "clicker.h";

				if (i == 364) {
					std::cout << "we're at the end\n";
					std::cout << "GB: " << GameBoxes[i] << std::endl;
					std::cout << "adj: " << adj[i] << std::endl;
					std::cout << "aBomb: " << aBomb[i] << std::endl;

					std::cout << "i - 31: " << GameBoxes[i - 31] << std::endl;
					std::cout << "i - 30: " << GameBoxes[i - 30] << std::endl;
					std::cout << "i - 29: " << GameBoxes[i - 29] << std::endl;
					std::cout << "i - 1: " << GameBoxes[i - 1] << std::endl;
					std::cout << "i + 1: " << GameBoxes[i + 1] << std::endl;
					std::cout << "i + 29: " << GameBoxes[i + 29] << std::endl;
					std::cout << "i + 30: " << GameBoxes[i + 30] << std::endl;
					std::cout << "i + 31: " << GameBoxes[i + 31] << std::endl;
				}

				if ((GameBoxes[i] != 0) && (GameBoxes[i] != 10) && (GameBoxes[i] == aBomb[i]) && (adj[i] > aBomb[i])) {
					
					if (i == 0) {
					
						if (GameBoxes[i + 1] == 0) {
							std::cout << "I would click on " << (i + 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 1] << std::endl;

							y = (i + 1) / 30;
							x = (i + 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i + 30] == 0) {
							//std::cout << "I would click on " << (i + 30) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 30] << std::endl;

							y = (i + 30) / 30;
							x = (i + 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i + 31] == 0) {

							//std::cout << "I would click on " << (i - 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 31] << std::endl;

							y = (i - 31) / 30;
							x = (i - 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}
					if (i == 29) {
						if (GameBoxes[i - 1] == 0) {
							//std::cout << "I would click on " << (i - 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 1] << std::endl;

							y = (i - 1) / 30;
							x = (i - 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i + 30] == 0) {
							//std::cout << "I would click on " << (i + 30) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 30] << std::endl;

							y = (i + 30) / 30;
							x = (i + 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i + 31] == 0) {
							//std::cout << "I would click on " << (i + 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 31] << std::endl;

							y = (i + 31) / 30;
							x = (i + 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}
					
					if (i == 450) {

						if (GameBoxes[i + 1] == 0) {
							//std::cout << "I would click on " << (i + 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 1] << std::endl;

							y = (i + 1) / 30;
							x = (i + 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i - 30] == 0) {
							//std::cout << "I would click on " << (i - 30) << std::endl;

							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 30] << std::endl;

							y = (i - 30) / 30;
							x = (i - 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i - 29] == 0) {
							//std::cout << "I would click on " << (i - 29) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 29] << std::endl;

							y = (i - 29) / 30;
							x = (i - 29) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}

					if (i == 479) {
						if (GameBoxes[i - 30] == 0) {
							//std::cout << "I would click on " << (i - 30) << std::endl;

							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 30] << std::endl;

							y = (i - 30) / 30;
							x = (i - 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i - 31] == 0) {

							//std::cout << "I would click on " << (i - 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 31] << std::endl;

							y = (i - 31) / 30;
							x = (i - 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}

						if (GameBoxes[i - 1] == 0) {
							//std::cout << "I would click on " << (i - 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 1] << std::endl;

							y = (i - 1) / 30;
							x = (i - 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}
					else if ((i != 0) && (i < 29)) {
						if (GameBoxes[i - 1] == 0) {
							//std::cout << "I would click on " << (i - 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 1] << std::endl;

							y = (i - 1) / 30;
							x = (i - 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 31] == 0) {
							//std::cout << "I would click on " << (i + 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 31] << std::endl;

							y = (i + 31) / 30;
							x = (i + 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 30] == 0) {
							//std::cout << "I would click on " << (i + 30) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 30] << std::endl;

							y = (i + 30) / 30;
							x = (i + 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 29] == 0) {
							//std::cout << "I would click on " << (i + 29) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 29] << std::endl;

							y = (i + 29) / 30;
							x = (i + 29) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 1] == 0) {
							//std::cout << "I would click on " << (i + 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 1] << std::endl;

							y = (i + 1) / 30;
							x = (i + 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}

					else if ((i > 450) && (i != 479)) {
						if (GameBoxes[i - 31] == 0) {

							//std::cout << "I would click on " << (i - 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 31] << std::endl;

							y = (i - 31) / 30;
							x = (i - 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 30] == 0) {
							//std::cout << "I would click on " << (i - 30) << std::endl;

							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 30] << std::endl;

							y = (i - 30) / 30;
							x = (i - 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 29] == 0) {
							//std::cout << "I would click on " << (i - 29) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 29] << std::endl;

							y = (i - 29) / 30;
							x = (i - 29) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 1] == 0) {
							//std::cout << "I would click on " << (i - 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 1] << std::endl;

							y = (i - 1) / 30;
							x = (i - 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 1] == 0) {
							std::cout << "I would click on " << (i + 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 1] << std::endl;

							y = (i + 1) / 30;
							x = (i + 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}

					else if ((i > 0) && ((i % 30) == 0) && (i < 450)) {
						if (GameBoxes[i - 30] == 0) {
							//std::cout << "I would click on " << (i - 30) << std::endl;

							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 30] << std::endl;

							y = (i - 30) / 30;
							x = (i - 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 29] == 0) {
							//std::cout << "I would click on " << (i - 29) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 29] << std::endl;

							y = (i - 29) / 30;
							x = (i - 29) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 31] == 0) {
							//std::cout << "I would click on " << (i + 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 31] << std::endl;

							y = (i + 31) / 30;
							x = (i + 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 30] == 0) {
							//std::cout << "I would click on " << (i + 30) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 30] << std::endl;

							y = (i + 30) / 30;
							x = (i + 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 1] == 0) {
							//std::cout << "I would click on " << (i + 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 1] << std::endl;

							y = (i + 1) / 30;
							x = (i + 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}

					else if ((i > 30) && (((i - 29) % 30) == 0) && (i < 450)) {
						if (GameBoxes[i - 31] == 0) {

							//std::cout << "I would click on " << (i - 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 31] << std::endl;

							y = (i - 31) / 30;
							x = (i - 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 30] == 0) {
							//std::cout << "I would click on " << (i - 30) << std::endl;

							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 30] << std::endl;

							y = (i - 30) / 30;
							x = (i - 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 1] == 0) {
							//std::cout << "I would click on " << (i - 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 1] << std::endl;

							y = (i - 1) / 30;
							x = (i - 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 30] == 0) {
							//std::cout << "I would click on " << (i + 30) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 30] << std::endl;

							y = (i + 30) / 30;
							x = (i + 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 29] == 0) {
							//std::cout << "I would click on " << (i + 29) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 29] << std::endl;

							y = (i + 29) / 30;
							x = (i + 29) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}

					else {
						if (GameBoxes[i - 31] == 0) {

							//std::cout << "I would click on " << (i - 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 31] << std::endl;

							y = (i - 31) / 30;
							x = (i - 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 30] == 0) {
							//std::cout << "I would click on " << (i - 30) << std::endl;

							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 30] << std::endl;

							y = (i - 30) / 30;
							x = (i - 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 29] == 0) {
							//std::cout << "I would click on " << (i - 29) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 29] << std::endl;

							y = (i - 29) / 30;
							x = (i - 29) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i - 1] == 0) {
							//std::cout << "I would click on " << (i - 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i - 1] << std::endl;

							y = (i - 1) / 30;
							x = (i - 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 31] == 0) {
							//std::cout << "I would click on " << (i + 31) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 31] << std::endl;

							y = (i + 31) / 30;
							x = (i + 31) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 30] == 0) {
							//std::cout << "I would click on " << (i + 30) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 30] << std::endl;

							y = (i + 30) / 30;
							x = (i + 30) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 29] == 0) {
							//std::cout << "I would click on " << (i + 29) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 29] << std::endl;

							y = (i + 29) / 30;
							x = (i + 29) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
						if (GameBoxes[i + 1] == 0) {
							//std::cout << "I would click on " << (i + 1) << std::endl;
							std::cout << i << std::endl;
							std::cout << GameBoxes[i + 1] << std::endl;

							y = (i + 1) / 30;
							x = (i + 1) - (y * 30);
							SetCursorPos((1251 + x * m), (477 + y * m));
							window::LeftClick();
							//	i = 580;
							click++;
						}
					}
				}
			}

/*			if ((click == 0) && (count > 2)) {
				xi = rand() % (width);
				yi = rand() % (height);

				while (GameBoxes[xi + yi * 30] == 10) {
					xi = rand() % (width);
					yi = rand() % (height);
				}

				if (GameBoxes[xi + yi * 30] != 10) {
					window::initGuess(width, height, xi, yi);
					click++;
				}
			}
			*/
			std::cout << "count: " << count << std::endl;
		}
	

				//if gameboard[n] is a number and adj[n] contains a bomb
				//in n found bombs in adj == gameboard number then look for unchecked square
				//if found an unchecked square then click
		
				}

			}

		}



		//release
		DeleteDC(hdc);
		DeleteObject(hbmp);
		ReleaseDC(NULL, hdc);
	}

	public:
		static void clicker(int z, int i, int GameBoxes[], std::vector<int> toClick) {
		
			int zz;
			int y = 0;
			int x = 0;
			int m = 18;


			zz = z - 31;

			clicker2(zz, i, GameBoxes, z, toClick);

			zz = z - 30;

			clicker2(zz, i, GameBoxes, z, toClick);

			zz = z - 29;

			clicker2(zz, i, GameBoxes, z, toClick);

			zz = z - 1;

			clicker2(zz, i, GameBoxes, z, toClick);

			zz = z + 1;

			clicker2(zz, i, GameBoxes, z, toClick);

			zz = z + 29;

			clicker2(zz, i, GameBoxes, z, toClick);

			zz = z + 30;

			clicker2(zz, i, GameBoxes, z, toClick);

			zz = z + 31;

			clicker2(zz, i, GameBoxes, z, toClick);
		}

public:
	static void clicker2(int zz, int i, int GameBoxes[], int z, std::vector<int> toClick) {
		if (GameBoxes[zz] == 10) {
			std::cout << "I was going to click " << zz << " but this is a 10\n";
		}
		//if I make it so that it can only click once per cycle
		else {
			//instead of just clicking here I should add them to a vector and do it at the end
			//if (finalCheck(zz, GameBoxes)) {
				std::cout << "Clicking " << zz << "\n";
				int m = 18;
				int y = zz / 30;
				int x = zz - (y * 30);
				std::cout << "GameBoxes[" << i << "]: " << GameBoxes[i] << "\n";
				std::cout << "GameBoxes[" << z << "]: " << GameBoxes[z] << "\n";
				SetCursorPos((1251 + x * m), (477 + y * m));
				std::cout << "x cus: " << (1251 + x * m) << "\n";
				std::cout << "y cus: " << (477 + y * m) << "\n";
				window::LeftClick();
				toClick.push_back(zz);
			//}
		}
	}
	/*
	static bool finalCheck(int zz, int GameBoxes[]) {
		bool green = false;
		int i;

		i = zz - 31;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		i = zz - 30;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		i = zz - 29;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		i = zz - 1;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		i = zz + 31;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		i = zz + 30;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		i = zz + 29;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		i = zz + 1;

		if ((GameBoxes[i] == aBomb[i]) && (adj[i] != aBomb[i]) && (aBomb != 0) && (GameBoxes[i] != 0)) {
			green = true;
		}

		return green;
		}*/

};