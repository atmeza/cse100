/*
 * Filename: main.cpp
 * Author: Alex Meza
 * Userid: cs100vbj
 * Description: Driver of program
 * Date: August 4, 2016
 */

#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<string>

/**
 *  IMPORTANT!! YOU MUST USE THE FOLLOWING LINES OF CODE FOR PROMPTS AND OUTPUTS:
 *
 *  To output size of tree: 
 *  cout << "Size of tree: " << size << "\n";
 *
 *  To output height of tree: 
 *  cout << "Height of tree: " << height << "\n";
 *
 *  To prompt the user to enter a name: 
 *  cout << "Enter actor/actress name: " << "\n";
 *
 *  To tell the user that actor/actress name was found: 
 *  cout << name << " found!" << "\n";
 *
 *  To tell the user that actor/actress name was NOT found: 
 *  cout << name << " NOT found" << "\n";
 *
 *  To prompt the user to try again: 
 *  cout << "Search again? (y/n)" << "\n";
 *
 *
 *
 *  Use cin to process user input.
 *
 *
 *
 *  You MUST output size, then height, then prompt the user to search, as above.
 *
 *
 *
 *  You MUST have the prompt for entering the name appear if and only if 
 *  the user input for trying again is "y" followed by the return key
 *
 *  You MUST have the program exit (exiting the prompt loop) if and only if
 *  the user input for trying again is "n" followed by the return key
 *
 *  You should handle other inputs for the retry prompt, 
 *  but we will not be testing them.
 *
 *  Note that size, height, and name are local variables in main that you 
 *  should update accordingly. Also note that actor/actress names will be 
 *  in all caps, last name followed by first name 
 *  (except in odd cases, eg. "50 CENT" and "ICE-T")
*/

using namespace std;

int main(int argc, char* argv[])
{
	//Size of tree should be stored in local variable size.
	//Height of tree should be stored in local variable height.
	//Input name will be stored in a string name
	unsigned int size = 0;
	unsigned int height = 0;
	std::string name = "";

	//Check for Arguments
	if(argc != 2){
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./main <input filename>.\n";
		return -1;
	}

	//Open file 
	ifstream in;
	in.open(argv[1], ios::binary);

	//Check if input file was actually opened
	if(!in.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
		return -1;
	}

	//Check for empty file
	in.seekg(0, ios_base::end); 
	unsigned int len = in.tellg();
	if(len==0) 
	{
		cout << "The file is empty. \n";
		return -1;
	}

	//Resets the stream to beginning of file
	in.seekg(0, ios_base::beg); 



	//
	/*
	 ********************************************
	 * main function implementation goes below  *
	 ********************************************
	 */
	
    string line;//for reading in from in file
   BST<string> bst;//holds strings

	if(in.is_open())//if its topen
	{
        while(getline(in,line)){//get each line from file
        
            bst.insert(line); //insert string into bst

        }
		in.close();
	}
	//get height and size of bst
    size = bst.size();
    height = bst.height();

    //output size and height of bst
    cout << "Size of tree: " << size << "\n";
 
    cout << "Height of tree: " << height << "\n";
 
    
    while(true){//while user wants to add names

       //  To prompt the user to enter a name: 
       cout << "Enter actor/actress name: " << "\n";
        
       getline(cin,name);
       
       if(bst.end()!=bst.find(name)){//if was able to find name

            //  To tell the user that actor/actress name was found: 
            cout << name << " found!" << "\n";
       }
       else{
            //  To tell the user that actor/actress name was NOT found: 
            cout << name << " NOT found" << "\n";
       }
       // To prompt the user to try again: 
       cout << "Search again? (y/n)" << "\n";
       
       getline(cin, name);

       if(name=="n"){//if no longer wanting to search

            break;
       }
       name="";

    }
 
	return 0;
}
