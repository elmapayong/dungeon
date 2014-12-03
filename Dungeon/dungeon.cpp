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



/* Creates room at the given index.  Opens room's doors if there are rooms already next to it,
   randomly tries to open doors if not and creates new rooms through those randomly opened doors. 
   Recursive.  */
void Dungeon::generateRoom(int index)
{
	cout << "total rooms: " << totalRooms << endl;
	//room out of bounds
	if (index >= (dungeonHeight*dungeonWidth))
		return;

	int x, y;
	initRoomFromIndex(index);
	x = findX(index);
	y = findY(index);
	cout << "( " << x << ", " << y << " )" << endl;

	//random engine for shuffling doors
	random_device rd;
	mt19937 randomize(rd());

	//shuffle case switches which control which doors to open first
	vector<int> shuffled_doors = { 1, 2, 3, 4 };	
	shuffle(shuffled_doors.begin(), shuffled_doors.end(), randomize);

	//a random generator w/ a % chance of returning true
	tr1::bernoulli_distribution randOpen(CHANCE_OF_OPEN_DOOR);	//% chance of true


	//go through each door and randomly try to open each
	for (int i = 0; i < 4; i++){
		switch (shuffled_doors[i]){
			//left
			case 1:
				if ((index % dungeonWidth) != 0){
					if (map[index - 1] == NULL && totalRooms < maxRooms){
							map[index]->left = randOpen(randomize);
							//door opened, make a new room on the left
							if (map[index]->left){
								totalRooms++;
								cout << "left: " << map[index]->left << " from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
								generateRoom(index - 1);
								cout << "done from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
							}
					}
				}
				break;

			//right
			case 2:
				if ((index + 1) < (dungeonHeight*dungeonWidth) && ((index + 1) % dungeonWidth) != 0){
					if (map[index + 1] == NULL && totalRooms < maxRooms){
							map[index]->right = randOpen(randomize);
							//door opened, make a new room on the right
							if (map[index]->right){
								totalRooms++;
								cout << "right: " << map[index]->right << " from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
								generateRoom(index + 1);
								cout << "done from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
							}
					}
				}
				break;

			//top
			case 3:
				if ((index - dungeonWidth) >= 0){
					if (map[index - dungeonWidth] == NULL && totalRooms < maxRooms){
							map[index]->top = randOpen(randomize);
							//door opened, make a new room on the top
							if (map[index]->top){
								totalRooms++;
								cout << "up: " << map[index]->top << " from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
								generateRoom(index - dungeonWidth);
								cout << "done from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
							}
					}
				}
				break;

			//bottom
			case 4:
				if ((index + dungeonWidth) < (dungeonHeight*dungeonWidth)){
					if (map[index + dungeonWidth] == NULL && totalRooms < maxRooms){
							map[index]->bottom = randOpen(randomize);
							//door opened, make a new room on the bottom
							if (map[index]->bottom){
								totalRooms++;
								cout << "down: " << map[index]->bottom << " from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
								generateRoom(index + dungeonWidth);
								cout << "done from:" << "( " << findX(index) << ", " << findY(index) << " )" << endl << endl;
							}
					}
				}
				break;
		}
	}

}





Dungeon::Dungeon()
{

	int index;
	

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, (dungeonHeight*dungeonWidth) - 1);

	//make first room at a random place in the map
	++totalRooms;
	index = dist(mt);		//DELETE and stick in generateRoom later
	generateRoom(index);

	//DELETE
	//cout << map.get()[index]->x << "  " << map.get()[index]->y << endl;
	cout << map[index]->coord.x << "  " << map[index]->coord.y << endl << endl;


	//opens doors leading to adjacent rooms
	for (int i = 0; i < (dungeonHeight*dungeonWidth); i++){
		if (map[i] != NULL){
			if ((i % dungeonWidth) != 0 && map[i - 1] != NULL)
				map[i]->left = true;
			//right
			if (((i + 1) < (dungeonHeight*dungeonWidth) && ((i + 1) % dungeonWidth) != 0) && map[i + 1] != NULL)
				map[i]->right = true;
			//top
			if ((i - dungeonWidth) >= 0 && map[i - dungeonWidth] != NULL)
				map[i]->top = true;
			//bottom
			if ((i + dungeonWidth) < (dungeonHeight*dungeonWidth) && map[i + dungeonWidth] != NULL)
				map[i]->bottom = true;
		}
	}

	////open doors with adjacent rooms - redundant for some doors but if an adjacent
	////room was created after, the door is not opened.
	////left
	//if ((index % dungeonWidth) != 0 && map[index - 1] != NULL)
	//	map[index]->left = true;
	////right
	//if (((index + 1) < (dungeonHeight*dungeonWidth) && ((index + 1) % dungeonWidth) != 0) && map[index + 1] != NULL)
	//	map[index]->right = true;
	////top
	//if ((index - dungeonWidth) >= 0 && map[index - dungeonWidth] != NULL)
	//	map[index]->top = true;
	////bottom
	//if ((index + dungeonWidth) < (dungeonHeight*dungeonWidth) && map[index + dungeonWidth] != NULL)
	//	map[index]->bottom = true;



	//prints map
	for (int row = 0; row < (dungeonHeight*dungeonWidth); row++){
		cout << (map[row] == NULL ? "0" : "1");
		if (row != 0 && (row + 1) % dungeonWidth == 0) cout << "\n";
	}

	cout << endl;

	//prints map
	for (int i = 0; i < dungeonHeight; i++){
		for (int level = 0; level < 3; level++){
			switch (level){
			case 0:
				for (int j = 0; j < dungeonWidth; j++){
					if (map[(i*dungeonWidth) + j] != NULL){
						cout << " ";
						cout << (map[(i*dungeonWidth) + j]->top ? "o" : "-");
						cout << " ";
					}
					else{
						cout << " - ";
					}
				}
				cout << endl;
				break;
			case 1:
				for (int j = 0; j < dungeonWidth; j++){
					if (map[(i*dungeonWidth)+j] != NULL){
						cout << (map[(i*dungeonWidth) + j]->left ? "o" : "|");
						cout << " " << (map[(i*dungeonWidth) + j]->right ? "o" : "|");
					}
					else{
						cout << "| |";
					}
				}
				cout << endl;
				break;
			case 2:
				for (int j = 0; j < dungeonWidth; j++){
					if (map[(i*dungeonWidth) + j] != NULL){
						cout << " ";
						cout << (map[(i*dungeonWidth) + j]->bottom ? "o" : "-");
						cout << " ";
					}
					else{
						cout << " - ";
					}
				}
				cout << endl;
				break;
				cout << endl;
			}

		}
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





