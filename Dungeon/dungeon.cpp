#include "Dungeon.h"
#include <iostream>
#include <cstdlib>		//rand()
#include <ctime>		//to seed srand()
#include <memory>		//smart pointers
#include <random>		//random generators
using namespace std;

enum Corner { UPPER_LEFT, UPPER_RIGHT, LOWER_LEFT, LOWER_RIGHT };


/* Creates room at coordinates.  Returns pointer or NULL if out of bounds */
room* Dungeon::generateRoom(int x, int y)
{
	//room out of bounds
	if (x < 0 || x > dungeonHeight || y < 0 || y > dungeonWidth){
		return NULL;
	}

	//a random generator w/ a % chance of returning true
	random_device rd;
	mt19937 eng(rd());
	tr1::bernoulli_distribution randOpen(0.40);	//40% chance of true

	room *temp = new room;
	temp->x = x;
	temp->y = y;

	//check adjacent rooms on the map and randomly open doors:
	if ((y - 1) >= 0 && map[x][y - 1] == NULL){	//left
		temp->left = randOpen(eng);
	}

	if ((y + 1) < dungeonWidth && map[x][y + 1] == NULL){	//right
		temp->right = randOpen(eng);
	}

	if ((x - 1) >= 0 && map[x - 1][y] == NULL){ //top
		temp->top = randOpen(eng);
	}
	
	if ((x + 1) < dungeonHeight && map[x + 1][y] == NULL){	//bottom
		temp->bottom = randOpen(eng);
	}
	
	return temp;
}





Dungeon::Dungeon() : map{}
{
	//unique_ptr<unique_ptr<room>[][]> map(new unique_ptr<room>[dungeonHeight][dungeonWidth]);
	int totalRooms = 0;
	room *temp = new room;
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


	temp = generateRoom(temp->x, temp->y);
	map[temp->x][temp->y] = temp;

	cout << "UL:" << map[temp->x][temp->y]->left << "  UR:" << map[temp->x][temp->y]->right << endl;
	cout << "LL:" << map[temp->x][temp->y]->top << "  LR:" << map[temp->x][temp->y]->bottom << endl;


	//print dungeon array of rooms
	for (int row = 0; row < dungeonHeight; row++){
		for (int col = 0; col < dungeonWidth; col++){
			cout << (map[row][col] ? "1" : "0");
		}
		cout << "\n"; 
	}

	//while (totalRooms < maxRooms){



	//}

	system("pause");
}





