#include "Dungeon.h"


enum Corner { UPPER_LEFT, UPPER_RIGHT, LOWER_LEFT, LOWER_RIGHT };

//returns x position from given index of 2D array
int Dungeon::findX(int index){
	return index / dungeonWidth;
}

//returns x position from given index of 2D array
int Dungeon::findY(int index){
	return index % dungeonWidth; 
}

/* Allocates a room at the given index and sets its coordinates */
void Dungeon::initRoomFromIndex(int index){
	map[index] = make_unique<Room>();

	//set (x,y) coordinates from 1D array
	map[index]->coord.x = findX(index);
	map[index]->coord.y = findY(index);
}



/* Creates room at coordinates.  Returns pointer to room or NULL if out of bounds */
void Dungeon::generateRoom(int index)
{
	//room out of bounds
	if (index >= (dungeonHeight*dungeonWidth))
		return;

	int x, y;
	initRoomFromIndex(index);
	x = findX(index);
	y = findY(index);


	//random engine for shuffling doors
	random_device rd;
	mt19937 randomize(rd());

	//shuffle case switches which control which doors to open first
	vector<int> shuffle_doors = { 1, 2, 3, 4 };	
	shuffle(shuffle_doors.begin(), shuffle_doors.end(), randomize);

	//a random generator w/ a % chance of returning true
	tr1::bernoulli_distribution randOpen(CHANCE_OF_OPEN_DOOR);	//% chance of true

	//go through each door and randomly try to open each
	for (int i = 0; i < 4; i++){
		switch (shuffle_doors[i]){
			//left
			case 1:
				if ((y - 1) >= 0){
					if (map[x][y - 1] == NULL && totalRooms <= maxRooms){
						temp->left = randOpen(eng);
						//door opened, make a new room on the left
						if (temp->left){
							totalRooms++;
							generateRoom(x, y - 1);
						}
					}
					else{
						//already a room on the left
						temp->left = true;
					}
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}

	//~~~ check adjacent rooms on the map and randomly open doors: ~~~//
	//left
	if ((y - 1) >= 0){
		if (map[x][y - 1] == NULL && totalRooms <= maxRooms){
			temp->left = randOpen(eng);
			//door opened, make a new room on the left
			if (temp->left){
				totalRooms++;
				generateRoom(x, y - 1);
			}
		}
		else{
			//already a room on the left
			temp->left = true;
		}
	}

	//right
	if ((y + 1) < dungeonWidth){
		if (map[x][y + 1] == NULL && totalRooms <= maxRooms){
			temp->right = randOpen(eng);
			//door opened, make a new room on the right
			if (temp->right){
				totalRooms++;
				generateRoom(x, y + 1);
			}
		}
		else{
			//already a room on the right
			temp->right = true;		
		}
		
	}

	//top
	if ((x - 1) >= 0){
		if (map[x - 1][y] == NULL && totalRooms <= maxRooms){
			temp->top = randOpen(eng);
			//door opened, make a new room on the top
			if (temp->top){
				totalRooms++;
				generateRoom(x - 1, y);
			}
		}
		else{
			//already a room on top
			temp->top = true;
		}
	}
	
	//bottom
	if ((x + 1) < dungeonHeight && totalRooms <= maxRooms){
		if (map[x + 1][y] == NULL){
			temp->bottom = randOpen(eng);
			//door opened, make a new room on the bottom
			if (temp->bottom){
				totalRooms++;
				generateRoom(x + 1, y);
			}
		}
		else{
			//already a room on the bottom
			temp->bottom = true;
		}
	}
	

}





Dungeon::Dungeon()
{

	int totalRooms = 0, index;
	
	//srand(time(0));

	////make the first room in random place
	//index = rand() % (dungeonHeight*dungeonWidth);
	//generateRoom(index);
	////initRoomFromIndex(index);

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, (dungeonHeight*dungeonWidth) - 1);

	//make room at a random place in the map
	index = dist(mt);		//DELETE and stick in generateRoom later
	generateRoom(index);


	//cout << map.get()[index]->x << "  " << map.get()[index]->y << endl;
	cout << map[index]->coord.x << "  " << map[index]->coord.y << endl << endl;


	//prints map
	for (int row = 0; row < (dungeonHeight*dungeonWidth); row++){
		cout << (map[row] == NULL ? "0" : "1");
		if (row != 0 && (row + 1) % dungeonWidth == 0) cout << "\n";
	}













	////print dungeon array of rooms
	//for (int row = 0; row < dungeonHeight; row++){
	//	for (int col = 0; col < dungeonWidth; col++){
	//		cout << (map[row][col] ? "1" : "0");
	//	}
	//	cout << "\n"; 
	//}

	//while (totalRooms < maxRooms){

	//int blah = 1;
	//unique_ptr<int*[]> uptr = make_unique<int*[]>(dungeonHeight*dungeonWidth);
	//uptr = {NULL};



	//cout << endl << endl;
	//cout << uptr.get()[50] << "  " << &blah;

	//for (int row = 0; row < dungeonHeight; row++){
	//	for (int col = 0; col < dungeonWidth; col++){
	//		cout << (uptr[row][col] == 0 ? "1" : "0");
	//	}
	//	cout << "\n";
	//}

	//}
}





