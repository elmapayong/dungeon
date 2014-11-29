#include "Dungeon.h"


enum Corner { UPPER_LEFT, UPPER_RIGHT, LOWER_LEFT, LOWER_RIGHT };


//void Dungeon::printMap()
//{
//	for (int row = 0; row < dungeonHeight; row++){
//		for (int col = 0; col < dungeonWidth; col++){
//			cout << (map[row][col] ? "1" : "0");
//		}
//		cout << "\n";
//	}
//
//	for (int row = 0; row < dungeonHeight; row++){
//		for (int col = 0; col < dungeonWidth; col++){
//			for (int col2 = 0; col2 < 2; col2++){
//				
//			}
//		}
//	}
//}



///* Creates room at coordinates.  Returns pointer to room or NULL if out of bounds */
//Room* Dungeon::generateRoom(int x, int y)
//{
//	//room out of bounds
//	if (x < 0 || x > dungeonHeight || y < 0 || y > dungeonWidth){
//		return NULL;
//	}
//
//	//a random generator w/ a % chance of returning true
//	random_device rd;
//	mt19937 eng(rd());
//	tr1::bernoulli_distribution randOpen(CHANCE_OF_OPEN_DOOR);	//% chance of true
//
//	Room *temp = new Room;
//	temp->x = x;
//	temp->y = y;
//	map[x][y] = temp;
//	cout << x << "   " << y << endl;		//****DELETE THIS
//
//	
//
//
//
//
//	//~~~ check adjacent rooms on the map and randomly open doors: ~~~//
//	//left
//	if ((y - 1) >= 0){
//		if (map[x][y - 1] == NULL && totalRooms <= maxRooms){
//			temp->left = randOpen(eng);
//			//door opened, make a new room on the left
//			if (temp->left){
//				totalRooms++;
//				generateRoom(x, y - 1);
//			}
//		}
//		else{
//			//already a room on the left
//			temp->left = true;
//		}
//	}
//
//	//right
//	if ((y + 1) < dungeonWidth){
//		if (map[x][y + 1] == NULL && totalRooms <= maxRooms){
//			temp->right = randOpen(eng);
//			//door opened, make a new room on the right
//			if (temp->right){
//				totalRooms++;
//				generateRoom(x, y + 1);
//			}
//		}
//		else{
//			//already a room on the right
//			temp->right = true;		
//		}
//		
//	}
//
//	//top
//	if ((x - 1) >= 0){
//		if (map[x - 1][y] == NULL && totalRooms <= maxRooms){
//			temp->top = randOpen(eng);
//			//door opened, make a new room on the top
//			if (temp->top){
//				totalRooms++;
//				generateRoom(x - 1, y);
//			}
//		}
//		else{
//			//already a room on top
//			temp->top = true;
//		}
//	}
//	
//	//bottom
//	if ((x + 1) < dungeonHeight && totalRooms <= maxRooms){
//		if (map[x + 1][y] == NULL){
//			temp->bottom = randOpen(eng);
//			//door opened, make a new room on the bottom
//			if (temp->bottom){
//				totalRooms++;
//				generateRoom(x + 1, y);
//			}
//		}
//		else{
//			//already a room on the bottom
//			temp->bottom = true;
//		}
//	}
//	
//
//
//	return temp;
//}





Dungeon::Dungeon()
{

	//map = make_unique <Room[]>(dungeonHeight*dungeonWidth);	//allocates whole array :/

	int totalRooms = 0;
	int x, y, index;
	//Room *temp = new Room;
	//unique_ptr<Room> temp(new Room);
	srand(time(0));

	//make the first room in random place
	x = rand() % dungeonHeight;
	y = rand() % dungeonWidth;
	index = (x * dungeonWidth) + y;		//converts coordinates for 1D array
	map[index] = make_unique<Room>();
	map[index]->x = x;
	map[index]->y = y;
	//temp = generateRoom(temp->x, temp->y);
	//map.get([index] = temp;

	//cout << map.get()[index]->x << "  " << map.get()[index]->y << endl;
	cout << map[index]->x << "  " << map[index]->y << endl << endl;



	////print dungeon array of rooms
	//for (int row = 0; row < dungeonHeight; row++){
	//	for (int col = 0; col < dungeonWidth; col++){
	//		cout << (map[row][col] ? "1" : "0");
	//	}
	//	cout << "\n"; 
	//}

	//while (totalRooms < maxRooms){

	//int blah = 1;
	//uptr = make_unique<int*[]>(dungeonHeight*dungeonWidth);
	////uptr = {NULL};

	for (int row = 0; row < (dungeonHeight*dungeonWidth); row++){
		cout << (map[row] == NULL ? "0" : "1");
		if (row != 0 && (row + 1) % dungeonWidth == 0) cout << "\n";
	}

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





