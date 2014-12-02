#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include <memory>		//smart pointers
#include <iostream>
#include <cstdlib>		//rand()
#include <ctime>		//to seed srand()
#include <random>		//random generators
#include <array>
using namespace std;

const int dungeonWidth = 10;
const int dungeonHeight = 5;
const int maxRooms = 12;
const float CHANCE_OF_OPEN_DOOR = 0.9;


class Dungeon
{
public:
	Dungeon();
	void generateRoom(int);
	//Room* map[dungeonHeight][dungeonWidth];
	//unique_ptr<Room[]> map;
	void initRoomFromIndex(int);
	array<unique_ptr<Room>, (dungeonHeight*dungeonWidth)> map;

private:
	int totalRooms = 0;
};


#endif