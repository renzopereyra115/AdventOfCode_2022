//Advent of Code Day 2: Part 1
//Renzo Pereyra

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	//Rock Paper Scissors based on a Strategy Guide
	//Import Strategy Guide
	//Define Opponent's Choices (Rock/Paper/Scissors)
	//Define User's Choices (Rock/Paper/Scissors)
	//Define Point System
	//Sum each side's scores to decide winner

	ifstream in("game_input.txt");
	ofstream out("file.txt");
	string line;
	char hand[line.size()+1]; //1st column is opponent, 2nd column is null, 3rd column is player

	//scores per hand
	int rock = 1; //opponent='a', player='x'
	int paper = 2; //opponent='b', player='y'
	int scissors = 3; //opponent='c', player='z'

	int roundDraw = 0;
	int roundLoss = 3;
	int roundWin = 6;

	//scorekeeping
	int opponent = 0;
	int user = 0;

	if(in.is_open())
	{
		while (!in.eof())
		{
			getline(in, line); //reads a new line

			if (line.length() == 0)
			{
				//skip and close file
				out << "SKIPPED!" << endl;
				in.close();
			}
			else
			{
				//begin game
				strcpy(hand, line.c_str());
				for (int i=0; i<line.length(); i++)
				{	
					out << "Array " << i << ": " << hand[i] << endl;
				}

				//once array is loaded, begin calculating points + assigning winner
				//Opponent goes first, then user, then calculate winner + points
				switch(hand[0])
				{
					case 'A': //Opponent Rock
					{ 
						opponent += rock;
						out << "This is enemy case A" << endl;
						switch(hand[2])
						{
							case 'X': //User Rock
							{
								user += rock;
								user += roundDraw; //equals zero, but here for convenience
								out << "This is user case X" << endl;
								break;
							}
							case 'Y': //User Paper
							{
								user += paper;
								user += roundWin;
								opponent += roundLoss;
								out << "This is user case Y" << endl;
								break;
							}
							case 'Z': //User Scissors
							{
								user += scissors;
								user += roundLoss;
								opponent += roundWin;
								out << "This is user case Z" << endl;
								break;
							}
							default: 
							{
								out << "USER CASE ERROR" << endl;
								break;
							}
						}
						break;
					}
					case 'B': //Opponent Paper
					{
						opponent += paper;
						out << "This is enemy case B" << endl;
						switch(hand[2])
						{
							case 'X': //User Rock
							{
								user += rock;
								user += roundLoss;
								opponent += roundWin;
								out << "This is user case X" << endl;
								break;
							}
							case 'Y': //User Paper
							{
								user += paper; 
								user += roundDraw; //equals zero, but here for convenience
								out << "This is user case Y" << endl;
								break;
							}
							case 'Z': //User Scissors
							{
								user += scissors;
								user += roundWin;
								opponent += roundLoss;
								out << "This is user case Z" << endl;
								break;
							}
							default: 
							{
								out << "USER CASE ERROR" << endl;
								break;
							}
						}
						break;
					}
					case 'C': //Opponent Scissors
					{
						opponent += scissors;
						out << "This is enemy case C" << endl;
						switch(hand[2])
						{
							case 'X': //User Rock
							{
								user += rock;
								user += roundWin;
								opponent += roundLoss;
								out << "This is user case X" << endl;
								break;
							}
							case 'Y': //User Paper
							{
								user += paper;
								user += roundLoss;
								opponent += roundWin;
								out << "This is user case Y" << endl;
								break;
							}
							case 'Z': //User Scissors
							{
								user += scissors;
								user += roundDraw; //equals zero, but here for convenience
								out << "This is user case Z" << endl;
								break;
							}
							default: 
							{
								out << "USER CASE ERROR" << endl;
								break;
							}
						}
						break;
					}
					default: 
					{
						out << "ENEMY CASE ERROR" << endl;
					}
				}	
			}
		}
		//determine winner
		out << "Total User Points: " << user << endl;
		out << "Total Opponent Points: " << opponent << endl; 
		
		if (user > opponent)
		{
			out << "A winner is YOU!" << endl;
		}
		else if (opponent > user) 
		{
			out << "Your opponent won!" << endl;
		}
		else if (user == opponent)
		{
			out << "IT'S A DRAW!!!" << endl;
		}
	}
	return 0;
}