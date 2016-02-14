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
	//Read command files
	void readComm(string file, int v)
	{
		string line;
		ifstream myfile(file);
		if(myfile.is_open())
		{
			while(getline(myfile,line))
			{
				if(v == 1)
				{
					string commOne[26];
					for(int i = 0; i <= sizeof(commOne); ++i)
					{
						commOne[i] += line;
					}
				}
				else if(v == 2)
				{
					string commTwo[27];
					for(int i = 0; i <= sizeof(commTwo); ++i)
					{
						commTwo[i] += line;
					}
				}
				else if(v == 3)
				{
					string commThree[26];
					for(int i = 0; i <= sizeof(commThree); ++i)
					{
						commThree[i] += line;
					}
				}
				else if(v == 4)
				{
					string commFour[29];
					for(int i = 0; i <= sizeof(commFour); ++i)
					{
						commFour[i] += line;
					}
				}
				else if(v == 5)
				{
					string commFive[27];
					for(int i = 0; i <= sizeof(commFive); ++i)
					{
						commFive[i] += line;
					}
				}
				else if(v == 6)
				{
					string commSix[125];
					for(int i = 0; i <= sizeof(commSix); ++i)
					{
						commSix[i] += line;
					}
				}
			}
			myfile.close();
		}
		else cout << "File read error.\n";
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
		else if((direction == move[1] || direction == move[2]) && locate() == 0)
		{
			report(2); //Cliff Edge
			cout << "You fall off and die.\n";
			cout << "Thanks for plaing.\n";
			report(location);
			go();
		}
		//Fork
		else if(direction == move[0] && locate() = 2)
		{
			location += 7;
			report(6); //Labyrinth
		}
		else if(direction == move[1] && locate() == 2)
		{
			location += 2;
			report(4); //Maze
		}
		else if(direction == move[2] && locate() == 2)
		{
			++location;
			report(5); //Mountaintop
		}
		//Maze 0
		else if(direction == move[2] && locate() == 4)
		{
			location += 3;
			report(4);
		}
		else if(direction == move[1] && locate() == 4)
		{
			++location;
			report(4);
		}
		//Maze 1
		else if(direction == move[1] && locate() == 5)
		{
			--location;
			report(4);
		}
		else if(direction == move[2] && locate() == 5)
		{
			++location;
			report(4);
		}
		//Maze 2
		else if(direction == move[0] && locate() == 6)
		{
			location += 8;
			report(4);
		}
		else if(direction == move[1] && locate() == 6)
		{
			location -= 4;
			report(4);
		}
		else if(direction == move[2] && locate() == 6)
		{
			location -= 2;
			report(4);
		}
		//Maze 3
		else if(direction == move[1] && locate() == 7)
		{
			location -= 3;
			report(4);
		}
		else if(direction == move[2] && locate() == 7)
		{
			report(4);
		}
		//Maze 4
		else if(direction == move[0] && locate() == 8)
		{
			location -= 5;
			report(4);
		}
		else if(direction == move[2] && locate() == 8)
		{
			report(4);
		}
		//Labyrinth 0
		else if(direction == move[1] && locate() == 9)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 9)
		{
			location += 15;
			report(6);
		}
		//Labyrinth 1
		else if(direction == move[1] && locate() == 10)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 10)
		{
			location += 9;
			report(6);
		}
		//Labyrinth 2
		else if(direction == move[1] && locate() == 11)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 11)
		{
			location += 2;
			report(6);
		}
		//Labyrinth 3
		else if(direction == move[2] && locate() == 12)
		{
			++location;
			report(6);
		}
		//Labyrinth 4
		else if(direction == move[1] && locate() == 13)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 13)
		{
			location += 5;
		}
		//Labyrinth 5
		else if(direction == move[1] && locate() == 14)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 14)
		{
			location += 3;
			report(6); 
		}
		//Labyrinth 6
		else if(direction == move[2] && locate() == 15)
		{
			++location;
			report(6); 
		}
		//Labyrinth 7
		else if(direction == move[1] && locate() == 16)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 16)
		{
			location += 5;
			report(6);
		}
		//Labyrinth 8
		else if(direction == move[1] && locate() == 17)
		{
			--location;
			report(6);
		}
		else if(direction == move[2] && locate() == 17)
		{
			location += 2;
			report(6);
		}
		//Labyrinth 9
		else if(direction == move[1] && locate() == 18)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 18)
		{
			--location;
			report(6);
		}
		//Labyrinth 10
		else if(direction == move[1] && locate() == 19)
		{
			--location;
			report(6);
		}
		else if(direction == move[2] && locate() == 19)
		{
			++location;
			report(6);
		}
		//Labyrinth 11
		else if(direction == move[1] && locate() == 20)
		{
			++location;
			report(6); 
		}
		else if(direction == move[2] && locate() == 20)
		{
			--location;
			report(6);
		}
		//Labyrinth 12
		else if(direction == move[1] && locate() == 21)
		{
			--location;
			report(6);
		}
		else if(direction == move[2] && locate() == 21)
		{
			++location;
			report(6);
		}
		//Labyrinth 13
		else if(direction == move[1] && locate() == 22)
		{
			++location;
			report(6);
		}
		//Labyrinth 14
		else if(direction == move[1] && locate() == 23)
		{
			++location;
			report(6);
		}
		else if(direction == move[2] && locate() == 23)
		{
			location -= 3;
			report(6);
		}
		//Labyrinth 15
		else if(direction == move[1] && locate() == 24)
		{
			location -= 22;
			report(6);
		}
		else if(direction == move[2] && locate() == 24)
		{
			location -= 22;
			report(6);
		}
		else
		{
			cout << "That is not a legal move.\n";
		}
	}
	//Main function
	void go()
	{
		readConf("configurations.txt");
		readComm("commands_v1.txt", 1);
		readComm("commands_v2.txt", 2);
		readComm("commands_v3.txt", 3);
		readComm("commands_v4.txt", 4);
		readComm("commands_v5.txt", 5);
		readComm("commands_vR.txt", 6);
		if(locate() == -1)
		{
			cout << "This is an adventure game.\n";
			cout << "Legal moves are left, right, or forward.\n";
			cout << "Legal moves are left, right, or forward.\n";
			cout << "End each move with a period.\n\n";
			report(location+2);
			cout << "\nNext move --";
			run();
		}
		else
		{
			cout << "\nNext move --";
			run();
		}
	}
	return 0;
}