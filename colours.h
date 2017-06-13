class colours {

public:
	static int findRed(long p) {
		int iR = (p)& 0xff;
		return iR;
	}

public:
	static int findBlue(long p) {
		int iB = (p >> 16) & 0xff;
		return iB;
	}

public:
	static int findGreen(long p) {
		int iG = (p >> 8) & 0xff;
		return iG;
	}

};