#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//DELETE
const int TOTAL_TILE_SPRITES = 4;
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
	~Room() { remove(filename.c_str()); }

private:
	string FillNumber(int);
	int HEIGHT = 12;
	int WIDTH = 10;
	//int HEIGHT = SCREEN_HEIGHT / TILE_HEIGHT;
	//const int WIDTH = SCREEN_WIDTH / TILE_WIDTH;
};

#endif