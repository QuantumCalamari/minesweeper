if (GameBoxes[i] == adj[i]) {

	//top left corner
	if (i == 0) {
		//check for bombs
		if (GameBoxes[1] == 0) {
			aBomb[0]++;
			aBomb[3]++;
			aBomb[30]++;
			aBomb[31]++;
			aBomb[32]++;
			GameBoxes[1] = 10;
			bombs.push_back(1);
			count++;
		}
		if (GameBoxes[30] == 0) {
			aBomb[0]++;
			aBomb[60]++;
			aBomb[1]++;
			aBomb[31]++;
			aBomb[61]++;
			bombs.push_back(30);
			GameBoxes[30] = 10;
			count++;
		}
		if (GameBoxes[31] == 0) {
			aBomb[0]++;
			aBomb[1]++;
			aBomb[2]++;
			aBomb[30]++;
			aBomb[31]++;
			aBomb[60]++;
			aBomb[61]++;
			aBomb[62]++;
			bombs.push_back(31);
			GameBoxes[31] = 10;
			count++;
		}
	}

	//top right corner
	else if (i == 29) {
		if (GameBoxes[28] == 0) {
			aBomb[27]++;
			aBomb[29]++;
			aBomb[57]++;
			aBomb[58]++;
			aBomb[59]++;
			bombs.push_back(28);
			GameBoxes[28] = 10;
			count++;
		}
		if (GameBoxes[58] == 0) {
			aBomb[27]++;
			aBomb[28]++;
			aBomb[29]++;
			aBomb[57]++;
			aBomb[58]++;
			aBomb[87]++;
			aBomb[88]++;
			aBomb[89]++;
			bombs.push_back(58);
			GameBoxes[58] = 10;
			count++;
		}
		if (GameBoxes[59] == 0) {
			aBomb[29]++;
			aBomb[89]++;
			aBomb[58]++;
			aBomb[28]++;
			aBomb[88]++;
			bombs.push_back(59);
			GameBoxes[59] = 10;
			count++;
		}
	}

	//bottom left corner
	else if (i == 450) {
		if (GameBoxes[451] == 0) {
			aBomb[450]++;
			aBomb[452]++;
			aBomb[420]++;
			aBomb[421]++;
			aBomb[422]++;
			bombs.push_back(451);
			GameBoxes[451] = 10;
			count++;
		}
		if (GameBoxes[421] == 0) {
			aBomb[390]++;
			aBomb[391]++;
			aBomb[392]++;
			aBomb[420]++;
			aBomb[422]++;
			aBomb[450]++;
			aBomb[451]++;
			aBomb[452]++;
			bombs.push_back(421);
			GameBoxes[421] = 10;
			count++;
		}
		if (GameBoxes[420] == 0) {
			aBomb[450]++;
			aBomb[390]++;
			aBomb[391]++;
			aBomb[421]++;
			aBomb[451]++;
			bombs.push_back(420);
			GameBoxes[420] = 10;
			count++;
		}
	}

	//bottom right corner
	else if (i == 479) {
		if (GameBoxes[449] == 0) {
			aBomb[419]++;
			aBomb[479]++;
			aBomb[418]++;
			aBomb[448]++;
			aBomb[478]++;
			bombs.push_back(449);
			GameBoxes[449] = 10;
			count++;
		}
		if (GameBoxes[448] == 0) {
			aBomb[390]++;
			aBomb[391]++;
			aBomb[392]++;
			aBomb[420]++;
			aBomb[422]++;
			aBomb[450]++;
			aBomb[451]++;
			aBomb[452]++;
			bombs.push_back(448);
			GameBoxes[448] = 10;
			count++;
		}
		if (GameBoxes[478] == 0) {
			aBomb[447]++;
			aBomb[448]++;
			aBomb[449]++;
			aBomb[477]++;
			aBomb[479]++;
			bombs.push_back(478);
			GameBoxes[478] = 10;
			count++;
		}
	}

	//top edge
	else if ((i > 0) && (i < 29)) {

		if (GameBoxes[i - 1] == 0) {

			if ((i - 1) == 15) {
				std::cout << "fifteen\n";
			}

			aBomb[i - 2]++;
			aBomb[i]++;
			aBomb[i + 28]++;
			aBomb[i + 29]++;
			aBomb[i + 30]++;
			bombs.push_back(i - 1);
			GameBoxes[i - 1] = 10;
			count++;
		}
		if (GameBoxes[i + 1] == 0) {
			
			if ((i + 1) == 15) {
				std::cout << "fifteen\n";
			}

			aBomb[i]++;
			aBomb[i + 2]++;
			aBomb[i + 30]++;
			aBomb[i + 31]++;
			aBomb[i + 32]++;
			bombs.push_back(i + 1);
			GameBoxes[i + 1] = 10;
			count++;
		}
		if (GameBoxes[i + 29] == 0) {

			if ((i + 29) == 15) {
				std::cout << "fifteen\n";
			}

			aBomb[i - 2]++;
			aBomb[i - 1]++;
			aBomb[i]++;
			aBomb[i + 28]++;
			aBomb[i + 30]++;
			aBomb[i + 58]++;
			aBomb[i + 59]++;
			aBomb[i + 60]++;
			bombs.push_back(i + 29);
			GameBoxes[i + 29] = 10;
			count++;
		}
		if (GameBoxes[i + 30] == 0) {

			if ((i + 30) == 15) {
				std::cout << "fifteen\n";
			}

			aBomb[i - 1]++;
			aBomb[i]++;
			aBomb[i + 1]++;
			aBomb[i + 29]++;
			aBomb[i + 31]++;
			aBomb[i + 59]++;
			aBomb[i + 60]++;
			aBomb[i + 61]++;
			bombs.push_back(i + 30);
			GameBoxes[i + 30] = 10;
			count++;
		}
		if (GameBoxes[i + 31] == 0) {

			if ((i + 31) == 15) {
				std::cout << "fifteen\n";
			}

			aBomb[i]++;
			aBomb[i + 1]++;
			aBomb[i + 2]++;
			aBomb[i + 30]++;
			aBomb[i + 32]++;
			aBomb[i + 60]++;
			aBomb[i + 61]++;
			aBomb[i + 62]++;
			bombs.push_back(i + 31);
			GameBoxes[i + 31] = 10;
			count++;
		}
	}

	//bottom edge
	else if ((i > 450) && (i < 479)) {
		if (GameBoxes[i - 1] == 0) {
			aBomb[i - 2]++;
			aBomb[i]++;
			aBomb[i - 28]++;
			aBomb[i - 29]++;
			aBomb[i - 30]++;
			bombs.push_back(i - 1);
			GameBoxes[i - 1] = 10;
			count++;
		}
		if (GameBoxes[i + 1] == 0) {
			aBomb[i]++;
			aBomb[i + 2]++;
			aBomb[i - 30]++;
			aBomb[i - 31]++;
			aBomb[i - 32]++;
			bombs.push_back(i + 1);
			GameBoxes[i + 1] = 10;
			count++;
		}
		if (GameBoxes[i - 29] == 0) {
			aBomb[i]++;
			aBomb[i + 1]++;
			aBomb[i + 2]++;
			aBomb[i - 28]++;
			aBomb[i - 30]++;
			aBomb[i - 58]++;
			aBomb[i - 59]++;
			aBomb[i - 60]++;
			bombs.push_back(i - 29);
			GameBoxes[i - 29] = 10;
			count++;
		}
		if (GameBoxes[i - 30] == 0) {
			aBomb[i - 1]++;
			aBomb[i]++;
			aBomb[i + 1]++;
			aBomb[i - 29]++;
			aBomb[i - 31]++;
			aBomb[i - 59]++;
			aBomb[i - 60]++;
			aBomb[i - 61]++;
			bombs.push_back(i - 30);
			GameBoxes[i - 30] = 10;
			count++;
		}
		if (GameBoxes[i - 31] == 0) {
			aBomb[i - 2]++;
			aBomb[i - 1]++;
			aBomb[i]++;
			aBomb[i - 32]++;
			aBomb[i - 30]++;
			aBomb[i - 60]++;
			aBomb[i - 61]++;
			aBomb[i - 62]++;
			bombs.push_back(i);
			GameBoxes[i - 31] = 10;
			count++;
		}
	}

	//left edge
	else if ((i > 0) && ((i % 30) == 0) && (i < 450)) {
		if (GameBoxes[i - 30] == 0) {
			aBomb[i - 60]++;
			aBomb[i]++;
			aBomb[i - 59]++;
			aBomb[i - 29]++;
			aBomb[i + 1]++;
			bombs.push_back(i - 30);
			GameBoxes[i - 30] = 10;
			count++;
		}
		if (GameBoxes[i + 30] == 0) {
			aBomb[i + 60]++;
			aBomb[i]++;
			aBomb[i + 61]++;
			aBomb[i + 31]++;
			aBomb[i + 1]++;
			bombs.push_back(i + 30);
			GameBoxes[i + 30] = 10;
			count++;
		}
		if (GameBoxes[i + 1] == 0) {
			aBomb[i - 30]++;
			aBomb[i - 29]++;
			aBomb[i - 28]++;
			aBomb[i]++;
			aBomb[i + 2]++;
			aBomb[i + 30]++;
			aBomb[i + 29]++;
			aBomb[i + 28]++;
			bombs.push_back(i + 1);
			GameBoxes[i + 1] = 10;
			count++;
		}
		if (GameBoxes[i - 29] == 0) {
			aBomb[i - 60]++;
			aBomb[i - 59]++;
			aBomb[i - 58]++;
			aBomb[i - 30]++;
			aBomb[i  - 28]++;
			aBomb[i]++;
			aBomb[i + 1]++;
			aBomb[i + 2]++;
			bombs.push_back(i - 29);
			GameBoxes[i - 29] = 10;
			count++;
		}
		if (GameBoxes[i + 31] == 0) {
			aBomb[i]++;
			aBomb[i + 1]++;
			aBomb[i + 2]++;
			aBomb[i + 30]++;
			aBomb[i + 32]++;
			aBomb[i + 60]++;
			aBomb[i + 59]++;
			aBomb[i + 58]++;
			bombs.push_back(i + 31);
			GameBoxes[i + 31] = 10;
			count++;
		}
	}

	//right edge
	else if ((i > 30) && (((i - 29) % 30) == 0) && (i < 450)) {
		if (GameBoxes[i - 30] == 0) {
			aBomb[i - 60]++;
			aBomb[i]++;
			aBomb[i - 61]++;
			aBomb[i - 31]++;
			aBomb[i - 1]++;
			bombs.push_back(i - 30);
			GameBoxes[i - 30] = 10;
			count++;
		}
		if (GameBoxes[i + 30] == 0) {
			aBomb[i + 60]++;
			aBomb[i]++;
			aBomb[i + 59]++;
			aBomb[i + 29]++;
			aBomb[i - 1]++;
			bombs.push_back(i + 30);
			GameBoxes[i + 30] = 10;
			count++;
		}
		if (GameBoxes[i - 1] == 0) {
			aBomb[i - 2]++;
			aBomb[i]++;
			aBomb[i - 32]++;
			aBomb[i - 31]++;
			aBomb[i - 30]++;
			aBomb[i + 28]++;
			aBomb[i + 29]++;
			aBomb[i + 30]++;
			bombs.push_back(i - 1);
			GameBoxes[i - 1] = 10;
			count++;
		}
		if (GameBoxes[i + 29] == 0) {
			aBomb[i - 2]++;
			aBomb[i - 1]++;
			aBomb[i]++;
			aBomb[i + 30]++;
			aBomb[i + 28]++;
			aBomb[i + 60]++;
			aBomb[i + 59]++;
			aBomb[i + 58]++;
			bombs.push_back(i + 29);
			GameBoxes[i + 29] = 10;
			count++;
		}
		if (GameBoxes[i - 31] == 0) {
			aBomb[i - 62]++;
			aBomb[i  - 61]++;
			aBomb[i - 60]++;
			aBomb[i - 32]++;
			aBomb[i - 30]++;
			aBomb[i - 2]++;
			aBomb[i - 1]++;
			aBomb[i]++;
			bombs.push_back(i - 31);
			GameBoxes[i - 31] = 10;
			count++;
		}
	}

	//all central cases
	else {

		{
			if (GameBoxes[i - 31] == 0) {
				if ((i - 31) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i - 62]++;
				aBomb[i - 61]++;
				aBomb[i - 60]++;
				aBomb[i - 32]++;
				aBomb[i - 30]++;
				aBomb[i - 2]++;
				aBomb[i - 1]++;
				aBomb[i]++;
				bombs.push_back(i - 31);
				GameBoxes[i - 31] = 10;
				count++;
			}
			if (GameBoxes[i - 30] == 0) {
				if ((i - 30) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i - 61]++;
				aBomb[i - 60]++;
				aBomb[i - 59]++;
				aBomb[i - 31]++;
				aBomb[i - 29]++;
				aBomb[i - 1]++;
				aBomb[i]++;
				aBomb[i + 1]++;
				bombs.push_back(i - 30);
				GameBoxes[i - 30] = 10;
				count++;
			}
			if (GameBoxes[i - 29] == 0) {
				if ((i - 29) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i - 60]++;
				aBomb[i - 59]++;
				aBomb[i - 58]++;
				aBomb[i - 30]++;
				aBomb[i - 28]++;
				aBomb[i]++;
				aBomb[i+ 1]++;
				aBomb[i + 2]++;
				bombs.push_back(i - 29);
				GameBoxes[i - 29] = 10;
				count++;
			}
			if (GameBoxes[i - 1] == 0) {
				if ((i - 1) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i - 32]++;
				aBomb[i - 31]++;
				aBomb[i - 30]++;
				aBomb[i - 2]++;
				aBomb[i]++;
				aBomb[i + 30]++;
				aBomb[i + 31]++;
				aBomb[i + 32]++;
				bombs.push_back(i - 1);
				GameBoxes[i - 1] = 10;
				count++;
			}
			if (GameBoxes[i + 1] == 0) {
				if ((i + 1) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i - 30]++;
				aBomb[i - 29]++;
				aBomb[i - 28]++;
				aBomb[i]++;
				aBomb[i + 2]++;
				aBomb[i + 28]++;
				aBomb[i + 29]++;
				aBomb[i + 30]++;
				bombs.push_back(i + 1);
				GameBoxes[i + 1] = 10;
				count++;
			}
			if (GameBoxes[i + 31] == 0) {
				if ((i + 31) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i]++;
				aBomb[i + 1]++;
				aBomb[i + 2]++;
				aBomb[i + 30]++;
				aBomb[i + 32]++;
				aBomb[i + 60]++;
				aBomb[i + 61]++;
				aBomb[i + 62]++;
				bombs.push_back(i + 31);
				GameBoxes[i + 31] = 10;
				count++;
			}
			if (GameBoxes[i + 30] == 0) {
				if ((i + 30) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i - 1]++;
				aBomb[i]++;
				aBomb[i + 1]++;
				aBomb[i + 29]++;
				aBomb[i + 31]++;
				aBomb[i + 59]++;
				aBomb[i + 60]++;
				aBomb[i + 61]++;
				bombs.push_back(i + 30);
				GameBoxes[i + 30] = 10;
				count++;
			}
			if (GameBoxes[i + 29] == 0) {
				if ((i + 29) == 333) {
					std::cout << "333: " << i << std::endl;
				}
				aBomb[i - 2]++;
				aBomb[i - 1]++;
				aBomb[i]++;
				aBomb[i + 28]++;
				aBomb[i + 30]++;
				aBomb[i + 58]++;
				aBomb[i + 59]++;
				aBomb[i + 60]++;
				bombs.push_back(i + 29);
				GameBoxes[i + 29] = 10;
				count++;
			}

		}