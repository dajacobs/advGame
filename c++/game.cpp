#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	//Vars
	double win;
	double loss;
	double average = win/loss;
	int position = -1;
	string direction;
	string ogre[552];
	string trease[552];
	string move[] = {"forward.", "left.", "right."};
	int node[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	string location[] = {"Trail", "Cliff", "Fork", "Mountaintop", "Maze 0", "Maze 1", "Maze 2", "Maze 3", "Maze 4", "Labyrinth 0", "Labyrinth 1", "Labyrinth 2", "Labyrinth 3", "Labyrinth 4", "Labyrinth 5", "Labyrinth 6", "Labyrinth 7", "Labyrinth 8", "Labyrinth 9", "Labyrinth 10", "Labyrinth 11", "Labyrinth 12", "Labyrinth 13", "Labyrinth 14", "Labyrinth 15"};
	string description[] = {"You are on a path, with ravines on both sides.", "You are in a pleasant valley, with a trail ahead.", "You are teetering on the edge of a cliff.", "You are at a fork in the path.", "You are in a maze of twisty trails, all alike.", "You are on the mountaintop.", "You are lost in a winding corridor."};
	//Gets
	string locate()
	{
		return location;
	}
	string report(int loc)
	{
		if(loc == -1) 
		{
			return description[1];
		} 
		else if(loc == 0) 
		{
			return description[0];
		}
		else if(loc == 1) 
		{
			return description[2];
		}
		else if(loc == 2) 
		{
			return description[3];
		}
		else if(loc == 3) 
		{
			return description[5];
		}
		else if(loc == 4) 
		{
			return description[4];
		}
		else if(loc == 5) 
		{
			return description[6];
		}
		else
		{
			cout << "You are lost without hope.";
		}
	}
	//Move function
	void move(string direction)
	{
		//Valley
		if(direction == move[0] && locate() == -1)
		{
			++location;
			report(0); //Path
		}
		//Trail
		else if(direction == move[0] && locate() == 0)
		{
			location += 2;
			report(3); //Fork
		}
		else if((direction == move[1] || direction == move[2]) && location() == 0)
		{
			report(2); //Cliff Edge
			cout << "You fall off and die.\n";
			cout << "Thanks for plaing.\n";
			report(location);
		}
	}
	//Read configuration file
	void readConf(string file)
	{
		vector <vector <string>> data;
		ifstream infile(file);
		while(infile)
		{
			string s;
			if(!getline(infile, s)) { break; }
			istringstream ss(s);
			vector <string> record;
			while(ss)
			{
				string s;
				if(!getline(ss, s, ',')) { break; }
				record.push_back(s);
			}
			data.push_back(record);
		}
		for(int i = 0; i <= sizeof(ogre); ++i) 
		{
			while(!data.empty())
			{
				ogre[i] += data.front();
				treasure[i] += data.pop();
			}
		}
	}
	if(!infile.eof())
	{
		cerr << "File read error.\n";
	}
}