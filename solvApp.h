#define solvApp_h
#pragma once

class solvApp {

public:
	static int iHandler(int i) {
		int n;
		//corners
		if ((i == 0) || (i == 29) || (i == 450) || (i == 479)) {
			n = 3;
		}
		//edges
		else if (((i > 0) && (i < 29)) || ((i > 450) && (i < 479)) || ((i > 0) && ((i % 30) == 0) && (i < 450)) || ((i > 30) && (((i - 29) % 30) == 0) && (i < 450))) {
			n = 5;
		}
		else {
			n = 8;
		}
		return n;
	}
public:
	static int adjVect() {

	}
};