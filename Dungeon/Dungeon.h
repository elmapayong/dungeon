#include "Room.h"

const int dungeonWidth = 20;
const int dungeonHeight = 5;
const int maxRooms = 12;
const float CHANCE_OF_OPEN_DOOR = 0.9;

//struct room {
//	//room() : left(false), right(false), top(false), bottom(false){} //C++11 fix
//	int x, y;
//	bool left = false, right = false;
//	bool top = false, bottom = false;
//};


class Dungeon
{
public:
	Dungeon();
	Room* generateRoom(int, int);
	Room* map[dungeonHeight][dungeonWidth];
	void printMap();

private:
	int totalRooms = 0;
};