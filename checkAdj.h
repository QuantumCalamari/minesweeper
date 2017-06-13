if ((GameBoxes[i] != 0) && (GameBoxes[i] != 10)) {
	//if (GameBoxes[i] != adj[i]) {
	//set adj
	//top left



	//adj[i] = 8;

	if (i == 0) {

		if (GameBoxes[1] != 0) {
			adj[i]--;
		}
		if (GameBoxes[30] != 0) {
			adj[i]--;
		}
		if (GameBoxes[31] != 0) {
			adj[i]--;
		}
	}

	//top right corner
	else if (i == 29) {
		if (GameBoxes[28] != 0) {
			adj[i]--;
		}
		if (GameBoxes[58] != 0) {
			adj[i]--;
		}
		if (GameBoxes[59] != 0) {
			adj[i]--;
		}
	}

	//bottom left corner
	else if (i == 450) {
		if (GameBoxes[451] != 0) {
			adj[i]--;
		}
		if (GameBoxes[421] != 0) {
			adj[i]--;
		}
		if (GameBoxes[420] != 0) {
			adj[i]--;
		}
	}

	//bottom right corner
	else if (i == 479) {
		if (GameBoxes[449] != 0) {
			adj[i]--;
		}
		if (GameBoxes[448] != 0) {
			adj[i]--;
		}
		if (GameBoxes[478] != 0) {
			adj[i]--;
		}
	}

	//top edge
	else if ((i != 0) && (i < 29)) {

		if (GameBoxes[i - 1] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 1] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 29] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 30] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 31] != 0) {
			adj[i]--;
		}
	}

	//bottom edge
	else if ((i > 450) && (i != 479)) {

		if (GameBoxes[i - 1] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 1] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i - 29] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i - 30] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i - 31] != 0) {
			adj[i]--;
		}
	}

	//left edge
	else if ((i > 0) && ((i % 30) == 0) && (i < 450)) {
		if (GameBoxes[i - 30] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 30] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 1] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i - 29] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 31] != 0) {
			adj[i]--;
		}
	}

	//right edge
	else if ((i > 30) && (((i - 29) % 30) == 0) && (i < 450)) {
		if (GameBoxes[i - 30] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 30] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i - 1] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i + 29] != 0) {
			adj[i]--;
		}
		if (GameBoxes[i - 31] != 0) {
			adj[i]--;
		}
	}

	//all central cases
	else {

			if ((GameBoxes[i - 31] != 0) && (GameBoxes[i - 31] != 10))  {
				adj[i]--;
			}

			if ((GameBoxes[i - 30] != 0) && (GameBoxes[i - 30] != 10)) {
				adj[i]--;
			}

			if ((GameBoxes[i - 29] != 0) && (GameBoxes[i - 29] != 10)) {
				adj[i]--;
			}

			if ((GameBoxes[i - 1] != 0) && (GameBoxes[i - 1] != 10)) {
				adj[i]--;
			}

			if ((GameBoxes[i + 1] != 0) && (GameBoxes[i + 1] != 10)) {
				adj[i]--;
			}

			if ((GameBoxes[i + 31] != 0) && (GameBoxes[i + 31] != 10)) {
				adj[i]--;
			}

			if ((GameBoxes[i + 30] != 0) && (GameBoxes[i + 30] != 10)) {
				adj[i]--;
			}

			if ((GameBoxes[i + 29] != 0) && (GameBoxes[i + 29] != 10)) {
				adj[i]--;
			}

			if (i == 364) {
				std::cout << "we're at least in the correct place\n";
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

		//	}
		
	}

	if (adj[i] < GameBoxes[i]) {
		std::cout << "check out square " << i << std::endl;
	}