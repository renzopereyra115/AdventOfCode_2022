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
	int counter2 = 0;
	int lineCount = 0; //# of lines in the file
	string arr1;
	string arr2;
	string itemArr;
	char tempChar;
	
	if (in.is_open())
	{
		while(!in.eof())
		{
			string textString; //holds values from text
			getline(in, textString);
			if (textString.length() == 0) //close file when line is empty
			{
				out << "SKIPPED!" << endl;
				in.close();
			}
			else
			{
				//counts the amount of characters in the string
				counter = textString.length();
				out << "Total # in String: " << counter << endl;
				
				int halfStringCount = (counter / 2); //divides string's counter by half
				out << "Divided By Half: " << halfStringCount << endl;

				//assign arr1 w/ 1st half, arr2 w/ 2nd half of string
				string arr1[counter]; //initialize 1st array to compare
				string arr2[counter]; //initialize 2nd array to compare
				for (int i=0; i<counter; i++)
				{
					tempChar = textString[i];

					if (i < halfStringCount)
					{
						arr1[i] = tempChar;
						out << "#" << (i+1) << " Arr1: " << arr1[i] << endl;
					}
					else if (i >= halfStringCount)
					{
						arr2[(i-halfStringCount)] = tempChar; //starts arr2's element at 0
						out << "#" << (i+1) << " Arr2: " << arr2[(i-halfStringCount)] << endl;
					}
				}
				 
				//compare both arrays for matching letters
				string itemArr; 
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
							itemArr[(j+counter2)] = arr1[j];
							out << "ITEM: " << itemArr[(j+counter2)] << endl;
							counter2++;
						}
					}
				}
				out << "DONE!" << endl;
				lineCount++;
			}
		}
		out << "Reached end of file!" << endl;
		out << "Total Line Count: " << lineCount << endl;
		in.close();
	}
	return 0;
}