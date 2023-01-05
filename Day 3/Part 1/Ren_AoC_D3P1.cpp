//Advent of Code Day 3: Part 1
//Renzo Pereyra

#include<iostream>
#include<fstream>
#include<vector>
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
	int counter = 0; //# of chars in the string
	int lineCount = 0; //# of lines in the file, reserved past certain point
	int stringCount = 0; //# of lines in file, serves as array initializer
	string arr1;
	string arr2;
	
	if (in.is_open())
	{
		string textString; //holds values from text

		//prints + counts every line
		while (!in.eof())
		{
			getline(in,textString);
			if (textString.length() == 0)
			{
				//print nothing
			}
			else 
			{
				out << textString << endl;
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
				stringCount++;
				//counts the amount of characters in the string
				counter = textString.length();
				out << "Total # in String #" << stringCount << ": " << counter << endl;

				int halfStringCount = (counter / 2); //divides string's counter by half
				out << "Divided By Half: " << halfStringCount << endl;
					
				//assign arr1 w/ 1st half, arr2 w/ 2nd half of string
				char arr1[counter]; //initialize 1st array to compare
				char arr2[counter]; //initialize 2nd array to compare

				out << "CURRENT STRING NUMBER: " << stringCount << endl;

				for (int i=0; i<counter; i++)
				{
					if (i < halfStringCount)
					{
						arr1[i] = textString[i];
						out << "#" << (i+1) << " Arr1: " << arr1[i] << endl;
					}
					else if (i >= halfStringCount)
					{
						arr2[(i-halfStringCount)] = textString[i]; //starts arr2's element at 0
						out << "#" << (i+1) << " Arr2: " << arr2[(i-halfStringCount)] << endl;
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