//Advent of Code Day 3: Part 1
//Renzo Pereyra

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//read from file
	//compare 1st half with 2nd half of string
	//if letter matches, then assign to array
	//find ASCII value of each array letter
	//add all values to find the total

	ifstream in("rucksack_items.txt");
	ofstream out("file.txt");
	string textString; //holds values from text
	string arr1[];
	string arr2[];
	string arrShared[];
	
	if (in.is_open())
	{
		while(!in.eof())
		{
			getline(in, textString);
			cout << "TEST: " << textString << endl;

		}
		in.close();
	}

	return 0;
}