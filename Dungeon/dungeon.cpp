#include "Dungeon.h"
#include <algorithm>	//for fill()
#include <iostream>
#include <cstdlib>		//rand()
#include <ctime>		//to seed srand()
#include <memory>		//smart pointers
#include <random>		//random #s
using namespace std;

const int dungeonWidth = 10;
const int dungeonHeight = 5;
const int maxRooms = 10;

struct room {
	//room() : upperLeft(false), upperRight(false), lowerLeft(false), lowerRight(false){} //C++11 fix
	int x, y;
	bool upperLeft = false, upperRight = false;
	bool lowerLeft = false, lowerRight = false;
};

enum Corner {UPPER_LEFT, UPPER_RIGHT, LOWER_LEFT, LOWER_RIGHT};


//Dungeon::Dungeon()
int main()
{
	bool map[dungeonHeight][dungeonWidth];
	fill(map[0], map[0]+(dungeonWidth*dungeonHeight), false);	//init to all uncreated
	int totalRooms = 0;
	unique_ptr<room> temp(new room);

	srand(time(0));


	//pick a random corner to begin in
	switch ((rand() % 4)){
	case UPPER_LEFT:
		temp->x = 0;
		temp->y = 0;
		break;
	case UPPER_RIGHT:
		temp->x = 0;
		temp->y = dungeonWidth - 1;
		break;
	case LOWER_LEFT:
		temp->x = dungeonHeight - 1;
		temp->y = 0;
		break;
	case LOWER_RIGHT:
		temp->x = dungeonHeight - 1; 
		temp->y = dungeonWidth - 1;
		break;
	}

	map[temp->x][temp->y] = true;


	//print dungeon array of rooms
	for (int row = 0; row < dungeonHeight; row++){
		for (int col = 0; col < dungeonWidth; col++){
			cout << map[row][col];
		}
		cout << "\n"; 
	}

	//while (totalRooms < maxRooms){



	//}

	delete temp;
	system("pause");
}


//room* Dungeon::generateRoom()
unique_ptr<room> generateRoom(int x, int y)
{
	random_device rd;
	mt19937 eng(rd());
	tr1::bernoulli_distribution randOpen(0.40);
	//randOpen(eng);

	unique_ptr<room> temp(new room);
	temp->x = x;
	temp->y = y;

	//RANDOMLY DETERMINE OPEN DOORS

	return temp;
}


/*
<random>
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(0, 99);
dist(mt) //to use
*/