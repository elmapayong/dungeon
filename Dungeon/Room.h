#ifndef ROOM_H
#define ROOM_H

#include <iostream>

struct Coordinates{
	int x;
	int y;
};


class Room
{
public:
	Coordinates coord;
	bool left = false, right = false;
	bool top = false, bottom = false;
	//Room() { std::cout << "\nnew instance\n"; }
	//~Room() { std::cout << "\ndeleted Room\n"; }
};

#endif