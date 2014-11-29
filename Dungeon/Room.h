#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Room
{
public:
	int x, y;
	bool left = false, right = false;
	bool top = false, bottom = false;
	Room() { std::cout << "\nnew instance\n"; }
	~Room() { std::cout << "\ndeleted Room\n"; }
};

#endif