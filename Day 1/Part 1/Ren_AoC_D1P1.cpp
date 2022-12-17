//Advent of Code Day 1: Part 1
//Renzo Pereyra

#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

int main() 
{
	//print all values in file
	//sum all calories carried by each elf
	//biggest value is reserved, reset sum for every new elf
	//each space is considered a different elf
	//return the most # of calories from a list

	fstream newFile;
	string value; //value output from file
	int num = 0; //"value" in int format
	int sum = 0; //sum of each elf's total calories
	int largest = 0; //largest elf calorie count
	int elfCounter = 0; //counts the number of elves in list
	int elfWithLargestCal = 0; //elf with largest calorie count

	newFile.open("elf_input.txt");
	if(newFile.is_open())
	{
		while(!newFile.eof())
		{
			getline(newFile, value); //gets a line from file
			if (value.length() == 0)
			{
				cout << "SKIPPED" << endl;
				sum = 0; //resets the sum to zero for the next elf
				elfCounter++; //considered the end for that elf
			}
			else 
			{
				num = stoi(value); //assigns value to int number
				sum += num;

				if (sum >= largest)
				{
					largest = sum; //assigns highest value to "largest"
					elfWithLargestCal = elfCounter; //largest value's elf #
				}
			}
			cout << "Elf with the most Calories: " << "Elf #" << elfWithLargestCal << endl;
			cout << "Largest Calorie Count: " << largest << " Calories" << endl;
			cout << endl;
		}
		newFile.close();
	}
	return 0;
}