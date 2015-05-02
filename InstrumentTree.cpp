// Kaylin Brennan

#include <vector>
#include <iostream>
#include "InstrumentTree.h"

using namespace std;

InstrumentTree::InstrumentTree()
{
	root = NULL; //initialize the root
}
InstrumentTree::~InstrumentTree()
{
}
/*
Function prototype:
void InstrumentTree::printInstrumentInventory()

Function Description:
This method calls the printInstrumentInventory function that takes a node. Calls the
private print function using the root of the tree.

Example: 
printInstrumentInventory;

Precondition: The binary search tree has been initialized and created.
Postcondition: The list of instruments is printed.
*/
void InstrumentTree::printInstrumentInventory()
{
	InstrumentNode *node;
	node = root; //create new node that equals temp
	printInstrumentInventory(node); //call the print function that's private
}
/*
Function prototype:
void InstrumentTree::addInstrumentNode(string, string, string)

Function Description:
This method adds instruments to the tree. It checks to see if the user enetered a valid 
instrument type before adding it to the tree. If the user doesn't enter a valid type nothing 
is added to the tree.

Example:
Binary Search Tree instrumentTree
instrumentTree->(Trumpet, brass, The highest voiced brass instrument.);

Precondition: The instrumentTree has already been created.  User enters valid variables.
Postcondition: Movie added to the tree, as long as the correct variables were inputed.
*/
void InstrumentTree::addInstrumentNode(string name, string type, string info)
{
	InstrumentNode *added = new InstrumentNode(name, type, info); //create new node with info read in
	InstrumentNode *temp = NULL;
	InstrumentNode *parent = NULL; //create temp nodes
	// put the name of instruments into different vectors based on the type
	// of instrument it is, this is used later when printing instruments by type
	if(type == "brass") //brass instruments
	{
		brass.push_back(added->name);
	}
	else if(type == "woodwind") //woodwind instruments
	{
		woodwind.push_back(added->name);
	}
	else if(added->type == "percussion") //percussion instruments
	{
		percussion.push_back(added->name);
	}
	else if(added->type == "other") //other instruments
	{
		other.push_back(added->name);
	}
	else // if a valid type wasn't entered exit the function so it's not added to the tree
	{
		cout << "Not a valid type" << endl;
		return;
	}
	if(root == NULL) //if the tree is empty
	{ //make the node read in the root
		added->leftChild = NULL;
		added->rightChild = NULL;
		added->parent = NULL;
		root = added;
	}
	else
	{
		temp = root;
		while(temp != NULL) //searches through the tree 
		{
			parent = temp;  //sets parent node
			if(name <= temp->name) //if title is before temp title
			{
				temp = temp->leftChild; //go down the left branch
			}
			else
			{
				temp = temp->rightChild; //go down the right branch
			}
		}
		added->leftChild = NULL; //set pointers of added node
		added->rightChild = NULL;
		added->parent = parent;
		if(name <= parent->name) //if title is less than the parent title
		{
			parent->leftChild = added; //the node is the left child
		}
		else
		{
			parent->rightChild = added; //the node is the right child
		}
	}
}
/*
Function prototype:
void InstrumentTree::findInstrument(string name)

Function description:
This method creates a temp node that is set equal to the root, it then calls the 
searchInstrumentTree function using the temp node and name of instrument the user 
wants to find to find the correct instrument node. If the node is found the method then prints 
out the information for the instrument.

Example:
instrumentTree->findInstrument(Trumpet);

Precondition: User inputs a string.
Postcondition: Prints the instrument information or lets the user know the instrument was not found.
*/
void InstrumentTree::findInstrument(string name)
{
	InstrumentNode* temp;
	InstrumentNode* foundInstrument = NULL;
	temp = root;
	foundInstrument = searchInstrumentTree(temp, name); //call search instrument function which returns a node
	if(foundInstrument == NULL) //if the node is NULL the instrument was not found
	{
		cout << "Instrument not found." << endl;
	}
	else
	{
		cout << "Instrument Info:" << endl;
		cout << "================" << endl;
		cout << "Name: " << foundInstrument->name << endl;
		cout << "Type: " << foundInstrument->type << endl;
		cout << "Information about instrument: " << foundInstrument->info << endl;
	}
}
/*
Function prototype:
void InstrumentTree::printInstrumentInventory(node)

Function description:
This recursive method prints out the name of all the instruments in the binary search tree.

Example: 
printInstrumentInventory(temp);

Precondition: Must be called by another function and be called with a valid node.
Postcondition: Prints the entire tree.
*/
void InstrumentTree::printInstrumentInventory(InstrumentNode* node)
{
	if(node->leftChild!= NULL)
	{
        printInstrumentInventory(node->leftChild); //searches and prints down the left branch
    }
    cout << node->name << endl;
    if(node->rightChild != NULL)
    {
        printInstrumentInventory(node->rightChild); //seaches and prints down right branch
    }
}
/*
Function prototype:
InstrumentNode* InstrumentTree::searchInstrumentTree(node, string)

Function description:
This method searches the tree for a instrument with the same name the user inputed to search for.

Example:
foundInstrument = searchInstrumentTree(temp, Trumpet)

Precondition: Must be called with a node and a string variable.
Postcondition: Returns the node of the found instrument, if instrument is not found
it return an empty node.
*/
InstrumentNode* InstrumentTree::searchInstrumentTree(InstrumentNode* node, string name)
{
	if(node == NULL) //if tree is empty
	{
		return node;
	}
	else if(node->name == name) //if the movie has been found return the node
	{
		return node;
	}
	else
	{
		if(node->name < name) //if the title is less than the title searching for
		{
			return searchInstrumentTree(node->rightChild, name); //conitnue seach down right branch
		}
		else
		{
			return searchInstrumentTree(node->leftChild, name); //continue search down left branch
		}
	}
}
void InstrumentTree::findType(string wantedType)
{
	printType(wantedType);
}
/*
Function prototype:
void InstrumentTree::printType(string)

Function description:
This method prints out all the instruments of the same type that have been read into the
binary search tree. It checks to see if the wanted type is the same as the vectors the instruments
have been divided into, if it's not it let's the user know the type they entered was not valid.

Example:
printType(brass);

Precondition: Elements have been read into the binary search tree.
Postcondition: If valid, instruments of the same type are printed.
*/
void InstrumentTree::printType(string wantedType)
{
	if(wantedType == "brass") // if the type equals brass print the brass vector
	{
		for(int i=0; i < brass.size(); i++)
		{
			cout << brass[i] << endl;
		}
	}
	else if(wantedType == "woodwind") // if the type equals woodwind print the woodwind vector
	{
		for(int i=0; i < woodwind.size(); i++)
		{
			cout << woodwind[i] << endl;
		}
	}
	else if(wantedType == "percussion") // if the type equals percussion print the percussion vector
	{
		for(int i=0; i < percussion.size(); i++)
		{
			cout << percussion[i] << endl;
		}
	}
	else if(wantedType == "other") // if the type equals other print the other vector
	{
		for(int i=0; i < other.size(); i++)
		{
			cout << other[i] << endl;
		}
	}
	else // if none of the types match do not print any vector
	{
		cout << "Not a valid type." << endl;
	}
}
/*
Function prototype:
void InstrumentTree::addFavorite(string)

Function description:
This method adds an instument to the favorites vector if it is found in the instrumentTree.

Example:
intsrumentTree->addFavorite(Trumpet);

Precondition: Search tree must already be initialized.
Postcondition: If a valid instrument, the instrument is added to the favorites vector.
*/
void InstrumentTree::addFavorite(string name)
{
	InstrumentNode* temp;
	InstrumentNode* foundInstrument = NULL;
	temp = root;
	foundInstrument = searchInstrumentTree(temp, name); //call search instrument function which returns a node
	if(foundInstrument == NULL) // if node is NULL the instrument wasn't found
	{
		cout << "Could not find instrument." << endl;
	}
	else
	{
	//variable to keep track of if the instrument is in the favorites list already
		bool foundInFavorites = false;
		//loop through favorites
		for(int i = 0; i < favorites.size(); i++)
		{
			if(favorites[i] == name)
			{
				cout<<"Instrument already in favorites list."<<endl;
				foundInFavorites = true;
			}
		}
		//add to favorites if the instrument is not already on the list
		if(foundInFavorites == false)
		{
			favorites.push_back(foundInstrument->name); // if found add to the favorites vector
		}	
	
	}
}
/*
Function Prototype: 
void InstrumentTree::deleteFavorite(string);

Function description:
Deletes an instrument from the favorites vector.

Example:
instrumentTree->deleteFavorite(Trumpet)

Precondition: Must have an instrument that can be deleted, if not the function does nothing.
Postcondition: The instrument is deleted from the favorites vector.
*/
void InstrumentTree::deleteFavorite(string name)
{
	for(int i = 0; i < favorites.size(); i++)
	{
		if(favorites[i] == name) // instrument is found, delete from the list
		{
			cout << "Deleteing " << favorites[i] << " from favorites list." << endl;
			favorites.erase(favorites.begin()+i);
			return;
		} 
	}
	cout << "Instrument not found" << endl;
}
/*
Function prototype:
void InstrumentTree::printFavorite()

Function Description:
Prints out all the instruments in the favorites vector.

Example:
instrumentTree->printFavorite();

Precondition: Favorites vector has been initialized.
Postcondition: Favorites printed if there are instruments in the list.
*/
void InstrumentTree::printFavorite()
{
	cout << "Favorites List" << endl;
	cout << "==========" << endl;
	for(int i = 0; i < favorites.size(); i++) // loop through favorites vector and print out all isntruments
	{
		cout << favorites[i] << endl;
	}
}
/*
Function prototype:
void InstrumentTree::learnAbtInstrument(string)

Function description:
Prints information about the desired instrument.

Example:
instrumentTree->learnAbtInstrument(Trumpet);

Preconditions: instrumentTree has been created.
Postconditions: Information about a valid instrument is printed.
*/
void InstrumentTree::learnAbtInstrument(string name)
{
	InstrumentNode* temp;
	InstrumentNode* foundInstrument = NULL;
	temp = root;
	foundInstrument = searchInstrumentTree(temp, name); //call search instrument function which returns a node
	if(foundInstrument == NULL)
	{
		cout << "Could not find instrument." << endl;
	}
	else
	{
		cout << "Instrument Info:" << endl;
		cout << foundInstrument->info << endl;
	}
}
/*
Function prototype:
int InstrumentTree::countInstrumentList()

Function description:
Calls the countInstruments function with the root node of the instrumentTree.

Example:
instrumentTree->countInstrumentList();

Preconditions: instrumentTree has already been created.
Postcondition: Returns the number of nodes in the instrumentTree.
*/
int InstrumentTree::countInstrumentList()
{
	int count = countInstrumentList(root);
	
	return count;
}
/*
Function prototype: 
int InstrumentTree::countInstrumentList(*node)

Function Description:
Recursively calls itself in order to travel down all branches of the instrumentTree. 
For every node it adds one to the counter.

Example:
countInstrumentList(root);

Preconditions: Must be called from another function.
Postcondition: Returns an integer of the total number of nodes in the tree.
*/
int InstrumentTree::countInstrumentList(InstrumentNode *node)
{
	if(node == NULL)
	{
		return 0;
	}
	return countInstrumentList(node->leftChild) + countInstrumentList(node->rightChild) + 1;
}
