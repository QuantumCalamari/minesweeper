class scan {

public:
	static int checkColours(int n, HDC hdc, int i) {
		int r = 0;

	//	std::cout << "i: " << i << std::endl;

		int y = n / 30;
		int x = n - (y * 30);

		

		if (i == 0) {
			r = checkOne(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkTwo(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkThree(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkFour(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkFive(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkSix(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkSeven(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkEight(x, y, hdc);
		}
		if ((i == 0) && (r == 0)) {
			r = checkBlank(x, y, hdc);
		}
	//	checkBlank(x, y, hdc);

		return r;
	}

public:
	static int checkOne(int x, int y, HDC hdc) {

		int r = 0;
		bool b = false, w = false;
		for (int j = -5; j < 5; j++) {
			for (int i = -5; i < 5; i++) {

				//		std::cout << "x: " << (1066 + x * 18 + i) << std::endl;
				//		std::cout << "y: " << (456 + y * 18) << std::endl;


				long pixel = GetPixel(hdc, (41 + x * 18 + i), (39 + y * 18 + j)) & 0xFFFFFF;
				//blue one 73 89 190

				int pB = colours::findBlue(pixel);
				int pR = colours::findRed(pixel);
				int pG = colours::findGreen(pixel);

				/*if ((x == 19) && (y == 2)) {
					std::cout << "x: " << (41 + x * 18 + i) << std::endl;
					std::cout << "y: " << (39 + y * 18) << std::endl;
					std::cout << "pB: " << pB << std::endl;
					std::cout << "pR: " << pR << std::endl;
					std::cout << "pG: " << pG << std::endl;
					}

					if ((x == 20) && (y == 2)) {
					std::cout << "x: " << (41 + x * 18 + i) << std::endl;
					std::cout << "y: " << (39 + y * 18) << std::endl;
					std::cout << "pB: " << pB << std::endl;
					std::cout << "pR: " << pR << std::endl;
					std::cout << "pG: " << pG << std::endl;
					}*/

				if ((pB > 180) && (pR < 105) && (pR > 50) && (pG > 60) && (pG < 105)) {
					//	if (pB > 230) {
					b = true;
				}
				else if ((pB > 160) && (pR > 160)) {
					w = true;
				}

			}
		}

		if (b && w) {
			r = 1;
		}

		return r;
	}

public:
	static int checkTwo(int x, int y, HDC hdc) {

		int r = 0;
		bool b = false, w = false;
		for (int i = -3; i < 3; i++) {

			long pixel = GetPixel(hdc, (39 + x * 18 + i), (45 + y * 18)) & 0xFFFFFF;
			//green two 57 120 41

			int pB = colours::findBlue(pixel);
			int pR = colours::findRed(pixel);
			int pG = colours::findGreen(pixel);



			if ((pB < 40) && (pG > 90) && (pR < 40)) {
				//b = true;
				r = 2;
			}
		}
	/*		else if ((pB > 160) && (pR > 160)) {
				w = true;
			}

		}

		if (b && w) {
			r = 2;
		}*/

		return r;
	}

public:
	static int checkThree(int x, int y, HDC hdc) {
		int r = 0;
		bool b = false, w = false;
		for (int i = -3; i < 3; i++) {

			long pixel = GetPixel(hdc, (39 + x * 18 + i), (39 + y * 18)) & 0xFFFFFF;
			//red three 170 44 49

			int pB = colours::findBlue(pixel);
			int pR = colours::findRed(pixel);
			int pG = colours::findGreen(pixel);

			if ((pB < 60) && (pR > 150) && (pG < 60)) {
				b = true;
			}
			else if ((pB > 160) && (pR > 160)) {
				w = true;
			}
		}

		if (b && w) {
			r = 3;
		}

		return r;
	}

public:
	static int checkFour(int x, int y, HDC hdc) {
		int r = 0;
		bool b = false, w = false;
		for (int j = -5; j < 5; j++) {
			for (int i = -5; i < 5; i++) {

				long pixel = GetPixel(hdc, (39 + x * 18 + i), (39 + y * 18 + j)) & 0xFFFFFF;
				//blue four 17 19 135

				int pB = colours::findBlue(pixel);
				int pR = colours::findRed(pixel);
				int pG = colours::findGreen(pixel);

				/*if ((x == 10) && (y == 2)) {
					std::cout << "x: " << (39 + x * 18 + i) << std::endl;
					std::cout << "y: " << (39 + y * 18) << std::endl;
					std::cout << "pB: " << pB << std::endl;
					std::cout << "pR: " << pR << std::endl;
					std::cout << "pG: " << pG << std::endl;
				}

				if ((x == 12) && (y == 2)) {
					std::cout << "x: " << (39 + x * 18 + i) << std::endl;
					std::cout << "y: " << (39 + y * 18) << std::endl;
					std::cout << "pB: " << pB << std::endl;
					std::cout << "pR: " << pR << std::endl;
					std::cout << "pG: " << pG << std::endl;
				}*/

				if ((pB > 120) && (pR < 40) && (pG < 40)) {
					b = true;
				}
				else if ((pB > 160) && (pR > 160)) {
					w = true;
				}
			}
		}
		if (b && w) {
			r = 4;
		}

		return r;
	}

	public:
		static int checkFive(int x, int y, HDC hdc) {
				int r = 0;
				bool b = false, w = false;
				for (int j = -5; j < 5; j++)
				for (int i = -5; i < 5; i++) {

					long pixel = GetPixel(hdc, (39 + x * 18 + i), (39 + y * 18 + j)) & 0xFFFFFF;
					//red five 134 29 31

					int pB = colours::findBlue(pixel);
					int pR = colours::findRed(pixel);
					int pG = colours::findGreen(pixel);

					if ((pB < 10) && (pR > 120) && (pG < 10)) {
						b = true;
					}
					else if ((pB > 160) && (pR > 160)) {
						w = true;
					}
				}

				if (b && w) {
					r = 5;
				}

				return r;
			}

		public:
			static int checkSix(int x, int y, HDC hdc) {
					int r = 0;
					bool b = false, w = false;
					for (int i = -3; i < 3; i++) {

						long pixel = GetPixel(hdc, (39 + x * 18 + i), (39 + y * 18)) & 0xFFFFFF;
						//cyan six 16 121 123

						int pB = colours::findBlue(pixel);
						int pR = colours::findRed(pixel);
						int pG = colours::findGreen(pixel);

						if ((pB > 110) && (pR < 40) && (pG > 110)) {
							b = true;
						}
						else if ((pB > 160) && (pR > 160)) {
							w = true;
						}
					}

					if (b && w) {
						r = 6;
					}

					return r;
				}

			public:
				static int checkSeven(int x, int y, HDC hdc) {
					int r = 0;
					bool b = false, w = false;
					for (int i = -3; i < 3; i++) {

						long pixel = GetPixel(hdc, (39 + x * 18 + i), (39 + y * 18)) & 0xFFFFFF;
						//red seven 173 7 7 

						int pB = colours::findBlue(pixel);
						int pR = colours::findRed(pixel);
						int pG = colours::findGreen(pixel);

						if ((pB < 40) && (pR > 150) && (pG < 40)) {
							b = true;
						}
						else if ((pB > 160) && (pR > 160)) {
							w = true;
						}
					}

					if (b && w) {
						r = 7;
					}

					return r;
				}

				public:
					static int checkEight(int x, int y, HDC hdc) {
						int r = 0;
						bool b = false, w = false;
						for (int i = -3; i < 3; i++) {

							long pixel = GetPixel(hdc, (39 + x * 18 + i), (39 + y * 18)) & 0xFFFFFF;
							//grey eight 127 127 127

							int pB = colours::findBlue(pixel);
							int pR = colours::findRed(pixel);
							int pG = colours::findGreen(pixel);

							if ((140 > pB > 110) && (140 > pR > 120) && (140 > pG > 110)) {
								b = true;
							}
							else if ((pB > 160) && (pR > 160)) {
								w = true;
							}
						}

						if (b && w) {
							r = 8;
						}

						return r;
					}

					static int checkBlank(int x, int y, HDC hdc) {
						int r = 0;
						bool b = false, w = false;
						for (int i = -3; i < 3; i++) {

							long pixel = GetPixel(hdc, (39 + x * 18 + i), (39 + y * 18)) & 0xFFFFFF;
							//grey eight 127 127 127

							int pB = colours::findBlue(pixel);
							int pR = colours::findRed(pixel);
							int pG = colours::findGreen(pixel);

							if ((pB > 170) && (pR > 170) && (pG > 170)) {
								w = true;
							}
						}

						if (w) {
							
							long pixel = GetPixel(hdc, (39 + x * 18 + 5), (39 + y * 18)) & 0xFFFFFF;
					
							int pB = colours::findBlue(pixel);
							int pR = colours::findRed(pixel);
							int pG = colours::findGreen(pixel);

							if ((pB > 170) && (pR > 160) && (pG > 170)) {
								r = 9;
							}
							
						}
						return r;
					}

	
	
	
	
	
	
	
};