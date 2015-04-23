#ifndef STATS_H
#define STATS_H

#include <string>

#define NUM_CLASSES		6

struct ClassStats {
	std::string Name;
	int Vit,
		Int,
		End,
		Str,
		Dex,
		Mag,
		Fth,
		Lck;
} attr[NUM_CLASSES];

void setupClasses()
{
	attr[0].Name = "Warrior";
	attr[0].Vit = 14;
	attr[0].Int = 9;
	attr[0].End = 12;
	attr[0].Str = 12;
	attr[0].Lck = 10;
	attr[0].Dex = 11;
	attr[0].Fth = 10;

	attr[1].Name = "Knight";
	attr[1].Vit = 10;
	attr[1].Int = 11;
	attr[1].End = 11;
	attr[1].Str = 14;
	attr[1].Dex = 10;
	attr[1].Fth = 10;
	attr[1].Lck = 11;

	attr[2].Name = "Royalty";
	attr[2].Vit = 8;
	attr[2].Int = 12;
	attr[2].End = 8;
	attr[2].Str = 9;
	attr[2].Dex = 12;
	attr[2].Fth = 12;
	attr[2].Lck = 7;

	attr[3].Name = "Mage";
	attr[3].Vit = 9;
	attr[3].Int = 15;
	attr[3].End = 10;
	attr[3].Str = 9;
	attr[3].Dex = 11;
	attr[3].Fth = 6;
	attr[3].Lck = 11;

	attr[4].Name = "Thief";
	attr[4].Vit = 10;
	attr[4].Int = 13;
	attr[4].End = 10;
	attr[4].Str = 9;
	attr[4].Dex = 14;
	attr[4].Fth = 9;
	attr[4].Lck = 15;

	attr[5].Name = "Hunter";
	attr[5].Vit = 12;
	attr[5].Int = 10;
	attr[5].End = 13;
	attr[5].Str = 11;
	attr[5].Dex = 12;
	attr[5].Fth = 8;
	attr[5].Lck = 12;
}


#endif