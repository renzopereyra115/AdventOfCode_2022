//Advent of Code Day 3: Part 2
//Renzo Pereyra

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//Part 1 Goals (DONE):
	//read from file
	//compare 1st half with 2nd half of string
	//if letter matches, then assign to array
	//find ASCII value of each array letter
	//add all values to find the total

	//Part 2 Goals: 
	//Elves divided into groups of 3 elves each
	//Badge is the ONLY item type carried by all 3 elves in each group
	//compare group's elf items (every 3 string lines) to find common char
	//assign each elf badge (common char) to an array
	//find ASCII value of each array letter
	//add all values to find the total

	ifstream in("rucksack_items.txt");
	ofstream out("file.txt");
	int counter = 0; //# of chars in the string
	int lineCount = 0; //# of lines in the file, reserved past certain point
	int stringCount = 0; //# of lines in file, serves as array initializer
	
	if (in.is_open())
	{
		string textString; //holds values from text

		//counts every line
		while (!in.eof())
		{
			getline(in,textString);
			if (textString.length() == 0)
			{
				//print nothing
			}
			else 
			{
				lineCount++;
			}
		}
		out << "Total Line Count: " << lineCount << endl;

		//reset "end-of-file" flag
		in.clear();
		//start reading from beginning of file
		in.seekg(0L, ios::beg);

		//initializes array with total lineCount of 300 lines
		char itemArr[lineCount]; 

		while (!in.eof())
		{
			getline(in, textString);
			
			if (textString.length() == 0) //close file when line is empty
			{
				out << "SKIPPED!" << endl;
				in.close();
			}
			else
			{		
				//assign arr1 w/ 1st half, arr2 w/ 2nd half of string
				char arr1[counter]; //initialize 1st array to compare
				char arr2[counter]; //initialize 2nd array to compare
				char arr3[counter]; //initialize 3rd array to compare(NEW)

				out << "CURRENT STRING NUMBER: " << stringCount << endl;

				//print string
				for (int i=0; i<3; i++)
				{
					if (i==0)
					{
						for (int x = 0; x < textString.length(); x++)
						{
							out << "#" << (i+1) << ": " << textString << endl;
							arr1[x] = textString[x];
						}
							
					}
					else if (i==1)
					{
						for (int x = 0; x < textString.length(); x++)
						{
							out << "#" << (i+1) << ": " << stringCount << endl; 
							arr2[x] = textString[x];
						}
					}
					else if (i==2)
					{
						for (int x = 0; x < textString.length(); x++)
						{
							out << "#" << (i+1) << ": " << stringCount << endl;
							arr3[x] = textString[x];
						}
					}
				}
					
				//compare both arrays for matching letters
				for (int j=0; j<halfStringCount; j++)
				{
					out << "J: " << arr1[j] << endl;

					for (int k=0; k<halfStringCount; k++)
					{
						out << "K: " << arr2[k] << endl;

						if (arr1[j] != arr2[k])
						{
							out << "not equal" << endl;
						}
						else
						{
							out << "THEY ARE EQUAL!!!!" << endl;
							out << arr1[j] << endl;
							itemArr[(stringCount-1)] = arr1[j];
							out << "SAVING ITEM: " << itemArr[(stringCount-1)] << endl;
						}
					}
				}
			}
			out << "DONE!" << endl;
		}
	}
	//each letter has a "priority" value, the following adds all unique chars in array
	int val = 0;
	counter = 0;

	out << "Printing all unique rucksack items!" << endl;
	for (int x=0; x < lineCount; x++)
	{
		//print all unique rucksack items
		out << itemArr[x] << endl;
		val = itemArr[x];

		out << "THIS IS VAL: " << val << endl;
		//convert to a-z value (1-26)

		if (val >= 97 && val <= 122) //holds all lowercase ASCII character values
		{
			val = val - 96; //"a" will start at 1, "z" will end at 26 (per puzzle's request)
			out << "THIS IS VAL NUMBER: " << val << endl;
			counter += val;
		}
		else if (val >= 65 && val <= 90) //holds all uppercase ASCII character values
		{
			val = val - 38; //"A" will start at 27, "Z" will end at 52 (per puzzle's request)
			out << "THIS IS VAL NUMBER: " << val << endl;
			counter += val;
		}
		else 
		{
			out << "ERROR! PLEASE FIX!" << endl;
		}
	}
	out << "Total Value of Unique Items: " << counter << endl;
}
out << "Reached end of file!" << endl;
return 0;
}