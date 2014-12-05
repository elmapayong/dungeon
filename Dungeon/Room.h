#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const int TOTAL_TILE_SPRITES = 4;

struct Coordinates{
	int x;
	int y;
};


class Room
{
public:
	Room(int, int);
	Coordinates coord;
	bool left = false, right = false;
	bool top = false, bottom = false;
	string FillNumber(int);
	//Room() { std::cout << "\nnew instance\n"; }
	//~Room() { std::cout << "\ndeleted Room\n"; }
};

#endif