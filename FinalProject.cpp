// Final Project
// Kaylin Brennan

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include "InstrumentTree.h"

using namespace std;

string printMenu();

int main(int argc, char* argv[])
{
	InstrumentTree *instrumentTree = new InstrumentTree(); // create a binary search tree named instrumentTree
	string input= "";
	string value = "";
	string nextline = "";
	ifstream infile(argv[1]);
    if(infile.is_open())
    {
        while(getline(infile, nextline)) //read in the file
        {
			istringstream line(nextline); //separate different variables by commas
			string name = "";
			string type = "";
			string info = "";
			getline(line, value, ',');
			name = value;
			getline(line, value, ',');
			type = value;
			getline(line, value, ',');
			info = value;
            
            instrumentTree->addInstrumentNode(name, type, info); //call function to build the tree
		}
	}
	while(input != "7") // program will run until user inputs 7
	{
		input = printMenu(); // print the menu
		
		if(input == "1") // list instruments alphabetically 
		{
			instrumentTree->printInstrumentInventory();
		}
		
		if(input == "2") // list intruments by type
		{
			cout << "Enter type of instrument, choose from brass, percussion, woodwind, or other:" << endl;
			string wantedType = "";
			getline(cin, wantedType);
			instrumentTree->findType(wantedType); 
		}
		
		if(input == "3") // add an instrument
		{
			cout << "Enter instrument name:" << endl;
			string name = "";
			getline(cin, name);
			cout << "Enter instrument type, choose from brass, percussion, woodwind, or other:" << endl;
			string type = "";
			getline(cin, type);
			cout << "Enter information about the instrument: " << endl;
			string info = "";
			getline(cin, info);
			instrumentTree->addInstrumentNode(name, type, info);
		}
		
		if(input == "4") // Favorites
		{
			// create a menu for the favorites function
			string input2 = "";
			while(input2 != "4")
			{
				cout << "=========Favorites===========" << endl;
				cout << "1. Add to favorites list." << endl;
				cout << "2. Delete from favorites list." << endl;
				cout << "3. Print favorites list." << endl;
				cout << "4. Return to main menu." << endl;
				getline(cin, input2);
				if(input2 == "1")
				{
					cout << "Enter instrument to add:" << endl;
					string name = "";
					getline(cin, name);
					instrumentTree->addFavorite(name);
				}
				else if(input2 == "2")
				{
					cout << "Enter instrument to delete:" << endl;
					string name = "";
					getline(cin, name);
					instrumentTree->deleteFavorite(name);
				}
				else if(input2 == "3")
				{
					instrumentTree->printFavorite();
				}
			}
		}
		
		if(input == "5") // learn about an instrument
		{
			cout << "Enter instrument to learn about:" << endl;
			string name = "";
			getline(cin, name);
			instrumentTree->learnAbtInstrument(name);
		}
		
		if(input == "6") // count total instruments
		{
			int totalInstruments;
			totalInstruments = instrumentTree->countInstrumentList();
			cout << "There are " << totalInstruments << " instruments in the list." << endl;
		}
	} 
	infile.close();
	cout << "Goodbye!" << endl;
}
/*
Function prototype:
string printMenu()

Function Description:
Prints the main menu of the program.
*/
string printMenu()
{
	string input;
	cout << "======Main Menu=====" << endl; 
	cout << "1. Print instruments alphabetically" << endl;
	cout << "2. List instruments by type" << endl;
	cout << "3. Add an instrument" << endl; 
	cout << "4. Favorites" << endl;
	cout << "5. Learn about an instrument" << endl;
	cout << "6. Count number of instrument in list" << endl;
	cout << "7. Quit" << endl;
	getline(cin, input);
	return input;
}
