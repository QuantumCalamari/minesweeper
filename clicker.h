if (GameBoxes[i] == 10) {
	std::cout << "this is a bomb square: " << i << std::endl;

	//top left
	if (i == 0) {
		aBomb[1]++;
		aBomb[30]++;
		aBomb[31]++;
	}

	//top right
	if (i == 29) {
		aBomb[28]++;
		aBomb[58]++;
		aBomb[58]++;
	}

	//bottom left
	if (i == 450) {
		aBomb[451]++;
		aBomb[420]++;
		aBomb[421]++;
	}

	//bottom right
	if (i == 479) {
		aBomb[478]++;
		aBomb[449]++;
		aBomb[448]++;
	}

	//top edge
	else if ((i > 0) && (i < 29)) {
		aBomb[i - 1]++;
		aBomb[i + 1]++;
		aBomb[i + 29]++;
		aBomb[i + 30]++;
		aBomb[i + 31]++;
	}

	//bottom edge
	else if ((i > 450) && (i < 479)) {
		aBomb[i - 1]++;
		aBomb[i + 1]++;
		aBomb[i - 29]++;
		aBomb[i - 30]++;
		aBomb[i - 31]++;
	}

	//left edge
	else if ((i > 0) && ((i % 30) == 0) && (i < 450)) {
		aBomb[i + 1]++;
		aBomb[i - 30]++;
		aBomb[i - 29]++;
		aBomb[i + 30]++;
		aBomb[i + 31]++;
	}
	//right edge
	else if ((i > 30) && (((i - 29) % 30) == 0) && (i < 450)) {
		aBomb[i - 1]++;
		aBomb[i + 30]++;
		aBomb[i + 29]++;
		aBomb[i - 30]++;
		aBomb[i - 31]++;
	}
	//central cases
	if (((i > 29) && (i < 450)) && (((i - 29) % 30) != 0) && ((i % 30) != 0)) {
		//	if (i == 58) {
		aBomb[i + 1]++;
		aBomb[i - 30]++;
		aBomb[i - 29]++;
		aBomb[i + 30]++;
		aBomb[i + 31]++;
		aBomb[i - 1]++;
		aBomb[i + 29]++;
		aBomb[i - 31]++;
	}
}
//if we reach the end of the gb == adj test we have to make a guess
//test the guess to make sure it isn't on the bomb list, if it is guess again

//if (GameBoxes[i] == 10) {
if (GameBoxes[i] == aBomb[i]) {
	//top left corner
	if (i == 0) {
		if (GameBoxes[1] > 0 && GameBoxes[1] < 9) {
			if (aBomb[1] == GameBoxes[1]) {
				if (GameBoxes[0] == 0) {
					std::cout << "I would click 0\n";
				}
				if (GameBoxes[2] == 0) {
					std::cout << "I would click 2\n";
				}
				if (GameBoxes[30] == 0) {
					std::cout << "I would click 30\n";
				}
				if (GameBoxes[31] == 0) {
					std::cout << "I would click 31\n";
				}
				if (GameBoxes[32] == 0) {
					std::cout << "I would click 32\n";
				}
			}

			if (aBomb[30] == GameBoxes[30]) {
				if (GameBoxes[0] == 0) {
					std::cout << "I would click 0\n";
				}
				if (GameBoxes[1] == 0) {
					std::cout << "I would click 30\n";
				}
				if (GameBoxes[31] == 0) {
					std::cout << "I would click 31\n";
				}
				if (GameBoxes[61] == 0) {
					std::cout << "I would click 2\n";
				}
				if (GameBoxes[62] == 0) {
					std::cout << "I would click 32\n";
				}
			}

			if (aBomb[31] == GameBoxes[31]) {
				if (GameBoxes[0] == 0) {
					std::cout << "I would click 0\n";
				}
				if (GameBoxes[1] == 0) {
					std::cout << "I would click 1\n";
				}
				if (GameBoxes[2] == 0) {
					std::cout << "I would click 2\n";
				}
				if (GameBoxes[30] == 0) {
					std::cout << "I would click 30\n";
				}
				if (GameBoxes[32] == 0) {
					std::cout << "I would click 32\n";
				}
				if (GameBoxes[50] == 0) {
					std::cout << "I would click 50\n";
				}
				if (GameBoxes[51] == 0) {
					std::cout << "I would click 51\n";
				}
				if (GameBoxes[52] == 0) {
					std::cout << "I would click 52\n";
				}
			}
		}

	}

	if (i == 162) {
		std::cout << "here's the 162 info - GB: " << GameBoxes[162] << "\n adj: " << adj[162] << "\n aBomb: " << aBomb[162] << "\n";
	}

	//central cases
		if ((i > 29) && (i < 450) && (((i - 29) % 30) != 0) && ((i % 30) != 0)) {
			std::cout << "central case " << i << "\n" << std::endl;

			z = i - 31;

			if (i == 162) {
				std::cout << "here's the 162 info - GB: " << GameBoxes[162] << "\n adj: " << adj[162] << "\n aBomb: " << aBomb[162] << "\n";
			}


			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				//I need to check to see if it's a bomb or not
				
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}

			z = i - 30;

			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}

			z = i - 29;

			

			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}

			z = i - 1;

			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}

			z = i + 1;

			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}

			z = i + 29;

			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}

			z = i + 30;

			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}

			z = i + 31;

			if ((GameBoxes[z] > 0) && (GameBoxes[z] < 9)) {
				if (aBomb[z] == GameBoxes[z]) {
					std::cout << "aBomb: " << aBomb[z] << std::endl;
					std::cout << "GB: " << GameBoxes[z] << std::endl;
					std::cout << "adj: " << adj[z] << std::endl;
					clicker(z, i, GameBoxes, toClick);
				}
			}
		}

