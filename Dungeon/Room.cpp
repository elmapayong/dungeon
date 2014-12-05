#include "Room.h"

string Room::FillNumber(int num){
	stringstream fill;
	fill << setfill('0') << std::setw(2) << num;
	return fill.str();
}

Room::Room(int x, int y){
	coord.x = x;
	coord.y = y;

	int wallLimit = (((2 * (HEIGHT - 2)) + (2 * WIDTH)) / 4);

	filename = "map.map";
	stringstream subfilename;
	subfilename << coord.x << coord.y;
	filename.insert(3, subfilename.str());
	cout << filename << endl;

	ofstream file(filename);
	for (int i = 0; i < HEIGHT; ++i)
	{
		int toLimit = 0;
		for (int j = 0; j < WIDTH; ++j)
		{
			if ((i == (HEIGHT / 2) && (j == 0 || j == (WIDTH - 1))) || (j == (WIDTH / 2) && (i == 0 || i == (HEIGHT - 1))))
			{
				file << FillNumber(1) << " ";
			}
			else if (i == 0 || i == (HEIGHT - 1) || j == 0 || j == (WIDTH - 1) && (i != (HEIGHT / 2) || j != (WIDTH / 2)))
			{
				file << FillNumber(0) << " ";
			}
			else
			{
				int num = rand() % TOTAL_TILE_SPRITES;
				if (num == 0 && toLimit != wallLimit)
				{
					file << FillNumber(num) << " ";
					++toLimit;
				}
				else if (num == 0 && toLimit == wallLimit)
				{
					num = (rand() % (TOTAL_TILE_SPRITES - 1)) + 1;
					file << FillNumber(num) << " ";
				}
				else
				{
					file << FillNumber(num) << " ";
				}
			}
		}
		file << "\n";
	}
	file.close();

	string line;
	ifstream file2(filename);
	if (file2.is_open())
	{
		while (getline(file2, line))
		{
			cout << line << '\n';
		}
		file2.close();
	}
}