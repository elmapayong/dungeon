#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include <memory>		//smart pointers
#include <iostream>		//cout
#include <cstdlib>		//rand()
#include <ctime>		//to seed srand()
#include <random>		//random device
#include <algorithm>	//mt19937
#include <array>
#include <vector>
using namespace std;

const int dungeonWidth = 10;
const int dungeonHeight = 5;
const int maxRooms = 8;
const float CHANCE_OF_OPEN_DOOR = 0.6;


class Dungeon
{
public:
	Dungeon();
	void generateRoom(int);
	void initRoomFromIndex(int);
	int findX(int);
	int findY(int);
	array<unique_ptr<Room>, (dungeonHeight*dungeonWidth)> map;

private:
	int totalRooms = 0;
};


#endif