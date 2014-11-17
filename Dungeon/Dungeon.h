const int dungeonWidth = 10;
const int dungeonHeight = 5;
const int maxRooms = 10;

struct room {
	//room() : left(false), right(false), top(false), bottom(false){} //C++11 fix
	int x, y;
	bool left = false, right = false;
	bool top = false, bottom = false;
};


class Dungeon
{
public:
	Dungeon();
	room* generateRoom(int, int);
	room* map[dungeonHeight][dungeonWidth];
};