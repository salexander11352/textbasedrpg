#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib> // For system() prototype with gcc
#include "helpers.h"
#include "stats.h"

#ifdef _WIN32
std::string SAVEPATH;
SHGetSpecialFolderPathA(NULL, SAVEPATH, CSIDL_APPDATA,FALSE );
SAVEPATH += "Grogg\\";
#else
std::string SAVEPATH = "/tmp/";
#endif
// Later this should correlate to char name:
std::string SAVEFILE = SAVEPATH + "player.dat";

// Warrior = 1
// Knight = 2
// Royalty = 3
// Mage = 4
// Thief = 5
// Hunter = 6

std::string playerName;
int playerClass;

void saveFile() {
	std::ofstream save;
	save.open (SAVEFILE.c_str());
	if (save.is_open()) {
		save << playerName << "\n" << playerClass;
	save.close ();
	} else {
		std::cout << "ERROR: could not open the file requested.";
	}
}

void loadFile(){
	std::ifstream save;
	save.open (SAVEFILE.c_str());
	if (save.is_open()) {
	while ( !save.eof() )
	{
		std::getline (save,playerName,'\n');
		save >> playerClass;
		std::cout << "Player Name: " 
				  << playerName 
				  << "\nPlayer Class: " 
				  << attr[playerClass].Name 
				  << std::endl;
		sys_pause();

	}
	save.close ();
	} else {
		std::cout << "ERROR: could not open the file requested.";
	}
}

void charCreator() {

	char    choice;

	std::cout << "  What do you call yourself, adventurer?" << std::endl
			  << std::endl
			  << "  >>> ";
	std::cin.ignore(); 
	std::getline (std::cin, playerName);
	int num = 0;
	do{
	sys_clear();
	std::cout << "  What type of character do you wish to be." << std::endl;
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
			playerClass = 0;
			std::cout << std::endl << playerName 
					  << " ,You have choosen the warrior class."
					  << std::endl;
			num = 1;
			sys_pause();
			break;
		}
		case 'k':
		case '2': {
			playerClass = 1;
			std::cout << std::endl << playerName 
		  			  << " ,You have choosen the knight class."
					  << std::endl;
			num = 1;
			sys_pause();
			break;
		}
		case 'r':
		case '3': {
			playerClass = 2;
			std::cout << std::endl << playerName 
					  << " ,You have choosen the royalty class."
					  << std::endl;
			num = 1;
			sys_pause();
			break;
		}
		case 'm':
		case '4': {
			playerClass = 3;
			std::cout << std::endl << playerName 
					  << " ,You have choosen the mage class."
					  << std::endl;
			num = 1;
			sys_pause();
			break;
		}
		case 't':
		case '5': {
			playerClass = 4;
			std::cout << std::endl << playerName 
					  << " ,You have choosen the thief class."
					  << std::endl;
			num = 1;
			sys_pause();
			break;
		}
		case 'h':
		case '6': {
			playerClass = 5;
			std::cout << std::endl << playerName 
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

#define MENU_START		'1'
#define MENU_LOAD		'2'
#define MENU_EXIT		'3'

void mainMenu(){
	char choice;
	int num = 0;
	do{
		sys_clear();
		std::cout << "\n\n\t      Adventures of Grogg?"
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
			case MENU_START:
				charCreator();
				num =1;
				break;
			case MENU_LOAD:
				loadFile();
				num =1;
				break;
			case MENU_EXIT:
				exit(0);
				num =1;
				break;
		}
	}while(num != 1);
}

int main() {
	setupClasses();
	mainMenu();
	return(0);
}
