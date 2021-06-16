#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

///struct to save strings to search words
struct FileSearch {
	string line = "";//getting line and initializing with searching word later
	string* p_line;//pointer to later pointing to line
	string search = "";//input searching word
	int numElement = 0;//number of elements which are found
};

int main() {

	FileSearch file_search;//defining struct to use

	string openFile;//opening file name

	string quit = "";//quit system
	bool b_quit = false;//boolean to check quit system

	cout << "Please enter file name to open: (Poem.txt for example)" << endl;
	cin >> openFile ;//taking open file name 
	ifstream inFile(openFile);//opening it
	ofstream outFile("anaylsis.txt");//openenig outfile to write

	size_t pos = 0;//position 

	if (inFile && outFile)//checking both files
	{
		cout << " File is open size: ";
		cout << sizeof(inFile) << endl;//showing file size

		do {
			pos = 0;//initializing to 0
			file_search.numElement = 0;//initializing to 0
			cout << "Press 'q' to quit: ";
			cin >> quit;//taking quit input
			if (quit == "q") {//checking it
				b_quit = true;//if true quit
				break;
			}
			else {//else continue
				cout << "Enter the word to search: ";
				cin >> file_search.search;//user input to search the word
				while (inFile.good()) {//while opening file is good
					if (pos != string::npos) {//and pos is not equal to npos
						pos = file_search.line.find(file_search.search);//initialize pos with line.find(search)
						file_search.p_line = &file_search.line;//pointing to line
						while (getline(inFile, *file_search.p_line, ' '))//getting line from text
						{
							if (file_search.line.find(file_search.search, 0) != string::npos) {//checking line
								if (*file_search.p_line != "#" && *file_search.p_line != " ")//if it is not starting with # or white space
								{
									file_search.numElement++;//add to number of elements
									cout << "found: " << *file_search.p_line << " times: " << file_search.numElement << endl;//display it
								}
								outFile <<"Word found: "<< *file_search.p_line <<" times: " << file_search.numElement<< endl;//write to out file
							}
						}
					}
				}


			}
			inFile.clear();//clear inner file
			inFile.seekg(0);//go to the beginning
		} while (!b_quit);//programm runs until b_quit becomes true
	}
	
	else//else files are not found
	{
		cout << "Unable to open file.";//display it
		return 1;//break the programm
	
	}

	inFile.close();//close infile
	inFile.clear();//and clear it
	return 0;//return and exit
}
