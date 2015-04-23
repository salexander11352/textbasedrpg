#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib> // For system() prototype with gcc
#include "helpers.h"

#ifdef _WIN32
const std::string SAVEPATH = "C:\\";
#else
const std::string SAVEPATH = "/tmp/";
#endif
// Later this should correlate to char name:
const std::string SAVEFILE = SAVEPATH + "player.dat";

struct stats{
	int Vit,
		Int,
		End,
		Str,
		Dex,
		Mag,
		Faith,
		Luck;
	std::string Name;
}Adder[6];

// Warrior = 1
// Knight = 2
// Royalty = 3
// Mage = 4
// Theif = 5
// Hunter = 6


class start{
public:
	std::string playerName;
	int playerClass;
	void saveFile() {
		std::ofstream save;
		save.open ("C:\\Programming\\characterCreater\\saves\\Player.txt");
		if (save.is_open()) {
			save << game.playerName << "\n" << game.playerClass;
		save.close ();
		} else {
			std::cout << "ERROR: could not open the file requested.";
		}
	}
	void loadFile(){
		std::ifstream save;
				save.open ("C:\\Programming\\characterCreater\\saves\\Player.txt");
				if (save.is_open()) {
				while ( !save.eof() )
				{
					std::getline (save,game.playerName,'\n');
					save >> game.playerClass;
					std::cout << "Player Name: " 
							  << game.playerName 
							  << "\nPlayer Class: " 
							  << Adder[game.playerClass].Name 
							  << std::endl;
					sys_pause();

				}
				save.close ();
				} else {
					std::cout << "ERROR: could not open the file requested.";
				}
	}
	void mainMenu(){
		char choice;
		int num = 0;
		do{
		sys_clear();
		std::cout << "\n" << "\n\t      Adventures of Grogg?"
				  << "\n\tWelcome to the greatest text-based"
				  << "\n\t  adventure you have ever played."
				  << "\n\n";
		std::cout << "   1. Start\n" 
				  << "   2. Load\n"
				  << "   3. Exit\n\n";
	
		std::cout << "  >>> ";
		std::cin  >> choice;
		sys_clear();

		switch(choice) {
			case '1': {
				game.charCreater();
				num =1;
				break;
			}
			case '2': {
				loadFile();
				num =1;
				break;
			}
			case '3': {
				exit(0);
				num =1;
				break;
			}
			default:{
				std::cout << "ERROR that is an incorrect value." << std::endl;
				sys_pause();
				break;
			}
		}
		}while(num != 1);
	}
	void charCreater() {

		char    choice;

		std::cout << "  What do you call yourself, adventurer?" << std::endl
				  << std::endl
				  << "  >>> ";
		std::cin.ignore(); 
		std::getline (std::cin, game.playerName);
		int num = 0;
		do{
		sys_clear();
		std::cout << "  What type of characrter do you wish to be." << std::endl;
		std::cout << "    1. Warrior" << std::endl
				  << "    2. Knight"  << std::endl
				  << "    3. Royalty" << std::endl
				  << "    4. Mage"    << std::endl
				  << "    5. Thief"   << std::endl
				  << "    6. Hunter"  << std::endl
				  << "  >>> ";
		std::cin >> choice;
		sys_clear();
		switch(choice) {
			case 'w':
			case '1': {
				game.playerClass = 0;
				std::cout << std::endl << game.playerName 
						  << " ,You have choosen the warrior class."
						  << std::endl;
				num = 1;
				sys_pause();
				break;
			}
			case 'k':
			case '2': {
				game.playerClass = 1;
				std::cout << std::endl << game.playerName 
			  			  << " ,You have choosen the knight class."
						  << std::endl;
				num = 1;
				sys_pause();
				break;
			}
			case 'r':
			case '3': {
				game.playerClass = 2;
				std::cout << std::endl << game.playerName 
						  << " ,You have choosen the royalty class."
						  << std::endl;
				num = 1;
				sys_pause();
				break;
			}
			case 'm':
			case '4': {
				game.playerClass = 3;
				std::cout << std::endl << game.playerName 
						  << " ,You have choosen the mage class."
						  << std::endl;
				num = 1;
				sys_pause();
				break;
			}
			case 't':
			case '5': {
				game.playerClass = 4;
				std::cout << std::endl << game.playerName 
						  << " ,You have choosen the theif class."
						  << std::endl;
				num = 1;
				sys_pause();
				break;
			}
			case 'h':
			case '6': {
				game.playerClass = 5;
				std::cout << std::endl << game.playerName 
						  << " ,You have choosen the hunter class."
						  << std::endl;
				num = 1;
				sys_pause();
				break;
			}
			default:{
				std::cout << "ERROR that is an incorrect value." << std::endl;
				sys_pause();
				break;
			}
		}
		}while(num != 1);
		saveFile();
	}
	void defStats(){
		Adder[0].Name = "Warrior";
		Adder[0].Vit = 14;
		Adder[0].Int = 9;
		Adder[0].End = 12;
		Adder[0].Str = 12;
		Adder[0].Dex = 11;
		Adder[0].Faith = 10;
		Adder[0].Luck = 10;

		Adder[1].Name = "Knight";
		Adder[1].Vit = 10;
		Adder[1].Int = 11;
		Adder[1].End = 11;
		Adder[1].Str = 14;
		Adder[1].Dex = 10;
		Adder[1].Faith = 10;
		Adder[1].Luck = 11;

		Adder[2].Name = "Royalty";
		Adder[2].Vit = 8;
		Adder[2].Int = 12;
		Adder[2].End = 8;
		Adder[2].Str = 9;
		Adder[2].Dex = 12;
		Adder[2].Faith = 12;
		Adder[2].Luck = 7;

		Adder[3].Name = "Mage";
		Adder[3].Vit = 9;
		Adder[3].Int = 15;
		Adder[3].End = 10;
		Adder[3].Str = 9;
		Adder[3].Dex = 11;
		Adder[3].Faith = 6;
		Adder[3].Luck = 11;

		Adder[4].Name = "Theif";
		Adder[4].Vit = 10;
		Adder[4].Int = 13;
		Adder[4].End = 10;
		Adder[4].Str = 9;
		Adder[4].Dex = 14;
		Adder[4].Faith = 9;
		Adder[4].Luck = 15;

		Adder[5].Name = "Hunter";
		Adder[5].Vit = 12;
		Adder[5].Int = 10;
		Adder[5].End = 13;
		Adder[5].Str = 11;
		Adder[5].Dex = 12;
		Adder[5].Faith = 8;
		Adder[5].Luck = 12;
	}
}game;

int main() {

	game.defStats();
	game.mainMenu();
	// std::cout<<"Pause test:"<<std::endl;
	// sys_pause();
	// std::cout<<"Clear test:"<<std::endl;
	// sys_pause();
	// sys_clear();
	// sys_pause();
	return(0);
}
