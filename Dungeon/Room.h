#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const int TOTAL_TILE_SPRITES = 4;
const int HEIGHT = 12;
const int WIDTH = 16;
//const int dungeonWidth = 10;
//const int dungeonHeight = 5;

struct Coordinates{
	int x;
	int y;
};


class Room
{
public:
	Room() { };
	Room(int, int);
	Coordinates coord;
	bool left = false, right = false;
	bool top = false, bottom = false;
	string filename;
	string FillNumber(int);
	//Room() { std::cout << "\nnew instance\n"; }
	~Room() { remove(filename.c_str()); }
};

#endif