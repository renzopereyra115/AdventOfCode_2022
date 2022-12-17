//Advent of Code Day 1: Part 2
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

	ifstream newFile("elf_input.txt");
	ofstream out("file2.txt");
	string value; 			   //value output from file
	int num = 0; 			   //"value" in int format
	int sum = 0; 			   //sum of each elf's total calories
	int largest = 0; 		   //largest elf calorie count
	int largest2 = 0; 		   //2nd largest elf calorie count
	int largest3 = 0; 		   //3rd largest elf calorie count
	int elfCounter = 0; 	   //counts the number of elves in list
	int elfWithLargestCal = 0; //elf # with largest Calories
	int elfLargestTwo = 0;     //elf # with 2nd largest Calories
	int elfLargestThree = 0;   //elf # with 3rd largest Calories

	//newFile.open("elf_input.txt");
	if(newFile.is_open())
	{
		while(!newFile.eof())
		{
			getline(newFile, value); //gets a line from file
			if (value.length() == 0)
			{
				elfCounter++; //considered the end for that elf
				out << "Elf #" << elfCounter << " Total Calories: " << sum << endl;
				if ((sum >= largest3) && (sum <= largest2) && (sum <= largest))
				{
					largest3 = sum;
					elfLargestThree = elfCounter;
				}
				else if ((sum >= largest2) && (sum <= largest))
				{
					largest3 = largest2;
					largest2 = sum;
					elfLargestTwo = elfCounter;
				}
				else if (sum >= largest)
				{
					largest3 = largest2;
					largest2 = largest;
					largest = sum; //assigns highest value to "largest"
					elfWithLargestCal = elfCounter; //largest value's elf #
				}
				sum = 0; //resets the sum to zero for the next elf
				out << "Largest 1: " << largest << endl;
				out << "Largest 2: " << largest2 << endl;
				out << "Largest 3: " << largest3 << endl;
			}
			else
			{
				num = stoi(value); //assigns value to int number
				sum += num;
			}
		}
		out << endl;
		out << "TOP 3 Elves Carrying the Most Calories:" << endl;
		out << "1. " << "Elf #" << elfWithLargestCal << " - " << largest << " Calories" << endl;
		out << "2. " << "Elf #" << elfLargestTwo << " - " << largest2 << " Calories" << endl; 
		out << "3. " << "Elf #" << elfLargestThree << " - " << largest3 << " Calories" << endl;
		out << endl;
		out << "Sum of Top 3 Elves' Calories: " << largest + largest2 + largest3 << " Calories" << endl;
		out << endl;
		newFile.close();
	}
	return 0;
}