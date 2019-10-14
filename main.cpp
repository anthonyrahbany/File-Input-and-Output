#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// ==================  CHARACTER CLASS  ======================

class Character
{
private:

	int number;
	string theme;
	string nameOfSet;
	int numOfParts;
	int pieces;
	double price;

public:

	Character(int _number, string _theme, string _nameOfSet, int _numOfParts, int _pieces, double _price) {

		number = _number;
		theme = _theme;
		nameOfSet = _nameOfSet;
		numOfParts = _numOfParts;
		price = _price;
		pieces = _pieces;
	}
	int GetNumber()
	{
		return number;
	}
	string GetTheme()
	{
		return theme;
	}
	string GetNameOfSet()
	{
		return nameOfSet;
	}
	int GetNumOfParts() {
		return numOfParts;
	}
	int GetPieces()
	{
		return pieces;
	}
	double GetPrice()
	{
		return price;
	}

};

//======================  FUNCTIONS DECLARATIONS ==========================

void CharactersFromFile(string path, vector<Character>& characters);

void MostExpensiveSet(vector<Character>& characters);
void LargestPieceCount(vector<Character>& characters);
void SetNameSearch(vector<Character>& characters);
void SearchThemes(vector<Character>& characters);
void PartCountInformation(vector<Character>& characters);
void PriceInformation(vector<Character>& characters);
void MiniFigureInformation(vector<Character>& characters);
void BoughtOneOfEverything(vector<Character>& characters);




//=============================  MAIN  ========================================

unsigned int totalNumber = 0;
int main()
{
	vector<Character> characters;


	cout << fixed << setprecision(2);
	//cout << "Which file(s) to open?\n";
	//cout << "1. lego1.csv" << endl;
	//cout << "2. lego2.csv" << endl;
	//cout << "3. lego3.csv" << endl;
	//cout << "4. All 3 files" << endl;
	int option;
	cin >> option;



	//=================  LOAD FILES FROM DATA ==================

	if (option == 1)
	{
		ifstream firstFile;
		CharactersFromFile("lego1.csv", characters);
		firstFile.open("lego1.csv");
	}
	else if (option == 2)
	{
		ifstream secondFile;
		CharactersFromFile("lego2.csv", characters);
		secondFile.open("lego2.csv");
	}
	else if (option == 3)
	{
		ifstream thirdFile;
		CharactersFromFile("lego3.csv", characters);
		thirdFile.open("lego3.csv");
	}
	else if (option == 4)
	{
		ifstream allFiles;
		CharactersFromFile("lego1.csv", characters);
		CharactersFromFile("lego2.csv", characters);
		CharactersFromFile("lego3.csv", characters);
		allFiles.open("lego1.csv");
		allFiles.open("lego2.csv");
		allFiles.open("lego3.csv");
	}


	//===================  CHOOSE A FUNCTION  =======================

		//cout << "1. Most Expensive set" << endl;
		//cout << "2. Largest piece count" << endl;
		//cout << "3. Search for set name containing..." << endl;
		//cout << "4. Search themes..." << endl;
		//cout << "5. Part count information" << endl;
		//cout << "6. Price information" << endl;
		//cout << "7. Minifigure information" << endl;
		//cout << "8. If you bought one of everything..." << endl;
		//cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	if (choice == 1) {
		MostExpensiveSet(characters);
	}
	else if (choice == 2) {
		LargestPieceCount(characters);
	}
	else if (choice == 3) {
		SetNameSearch(characters);
	}
	else if (choice == 4) {
		SearchThemes(characters);
	}
	else if (choice == 5) {
		PartCountInformation(characters);
	}
	else if (choice == 6) {
		PriceInformation(characters);
	}
	else if (choice == 7) {
		MiniFigureInformation(characters);
	}
	else if (choice == 8) {
		BoughtOneOfEverything(characters);
	}
	//else if (choice == 0) {
	//	exit;
	//}

	/*======= Print out how many sets were loaded =======*/
	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	return 0;
}





//==================================  FUNCTIONS  ==============================================



void CharactersFromFile(string path, vector<Character>& characters)
{

	ifstream inFile(path);
	if (inFile.is_open())
	{
		//Read the Heading line from file
		string lineFromFile;
		getline(inFile, lineFromFile);


		int number;
		string theme;
		string nameOfSet;
		int numOfParts;
		int pieces;
		double price;


		//Parsing through the elements.

		while (getline(inFile, lineFromFile))
		{
			istringstream stream(lineFromFile);

			//First Element
			string tempNumber;
			getline(stream, tempNumber, ',');
			number = stoi(tempNumber);

			//Second Element
			getline(stream, theme, ',');

			//Third Element
			getline(stream, nameOfSet, ',');

			//Fourth Element
			string tempNumOfParts;
			getline(stream, tempNumOfParts, ',');
			numOfParts = stoi(tempNumOfParts);

			//Fifth Element
			string tempPieces;
			getline(stream, tempPieces, ',');
			pieces = stoi(tempPieces);

			//Sixth Element
			string tempPrice;
			getline(stream, tempPrice);
			price = stod(tempPrice);

			Character storeInVector(number, theme, nameOfSet, numOfParts, pieces, price);
			characters.push_back(storeInVector);

			totalNumber++;
		}
	}
}





//==================================  MOST EXPENSIVE SET  =============================================

void MostExpensiveSet(vector<Character>& characters)
{
	int number = 0;
	string theme;
	string nameOfSet;
	int numOfParts = 0;
	int pieces = 0;

	double max = characters[0].GetPrice();
	unsigned int i = 0;

	for (i = 0; i < characters.size(); i++)
	{
		if (characters[i].GetPrice() > max)
		{
			max = characters[i].GetPrice();

			number = characters[i].GetNumber();
			theme = characters[i].GetTheme();
			nameOfSet = characters[i].GetNameOfSet();
			numOfParts = characters[i].GetNumOfParts();
			pieces = characters[i].GetPieces();

		}
	}

	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;
	cout << "The most expensive set is:" << endl;
	cout << "Name: " << nameOfSet << endl;
	cout << "Number: " << number << endl;
	cout << "Theme: " << theme << endl;
	cout << "Price: $" << max << endl;
	cout << "Minifigures: " << numOfParts << endl;
	cout << "Piece count: " << pieces << endl;


}




//======================  LARGEST PIECE COUNT  ===========================
void LargestPieceCount(vector<Character>& characters)
{
	int number = 0;
	string theme;
	string nameOfSet;
	int numOfParts = 0;
	double price = 0.0;

	int max = characters[0].GetPieces();
	unsigned int i = 0;

	for (i = 0; i < characters.size(); i++)
	{
		if (characters[i].GetPieces() > max)
		{
			max = characters[i].GetPieces();

			price = characters[i].GetPrice();
			number = characters[i].GetNumber();
			theme = characters[i].GetTheme();
			nameOfSet = characters[i].GetNameOfSet();
			numOfParts = characters[i].GetNumOfParts();

		}
	}

	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;

	cout << "The set with the highest parts count:" << endl;
	cout << "Name: " << nameOfSet << endl;
	cout << "Number: " << number << endl;
	cout << "Theme: " << theme << endl;
	cout << "Price: $" << price << endl;
	cout << "Minifigures: " << numOfParts << endl;
	cout << "Piece count: " << max << endl;
}




//=====================  SET NAME SEARCH  ==========================

void SetNameSearch(vector<Character>& characters)
{
	//Get a string as input from the user. Then search all sets and their names to see if they contain the search term.

	string nameSearch;
	getline(cin, nameSearch);
	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;

	string name;
	int number = 0;
	string nameOfSet;
	double price = 0.0;

	bool check = true;



	unsigned int i = 0;
	for (i = 0; i < characters.size(); i++)
	{
		size_t found = characters[i].GetNameOfSet().find(nameSearch);

		if (found != string::npos)
		{
			if (check == true) {
				cout << "Sets matching \"" << nameSearch << "\":" << endl;
			}

			check = false;

			price = characters[i].GetPrice();
			number = characters[i].GetNumber();
			nameOfSet = characters[i].GetNameOfSet();

			cout << number << " " << nameOfSet << " $" << price << endl;
		}
	}
	if (check == true)
	{
		cout << "No sets found matching that search term" << endl;
	}
}



//===========================  SET THEME SEARCH  ========================================

void SearchThemes(vector<Character>& characters)
{
	// Same thing as above function, but for themes

	string nameSearch;
	getline(cin, nameSearch);
	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;


	int number = 0;
	string nameOfSet;
	string theme;
	double price = 0.0;

	bool check = true;


	unsigned int i = 0;
	for (i = 0; i < characters.size(); i++)
	{
		size_t found = characters[i].GetTheme().find(nameSearch);

		if (found != string::npos)
		{
			if (check == true)
			{
				cout << "Sets matching \"" << nameSearch << "\":" << endl;
			}
			check = false;
			
			number = characters[i].GetNumber();
			price = characters[i].GetPrice();
			nameOfSet = characters[i].GetNameOfSet();

			cout << number << " " << nameOfSet << " $" << price << endl;
		}

	}
	if (check == true)
	{
		cout << "No sets found matching that search term" << endl;
	}
}



//=========================  PART COUNT INFORMATION  ==============================

void PartCountInformation(vector<Character>& characters)
{
	// Show the average parts for all the loaded sets

	int numOfParts = 0;
	int average = 0;

	unsigned int i = 0;
	for (i = 0; i < characters.size(); i++)
	{
		numOfParts += characters[i].GetPieces();

	}

	average = numOfParts / totalNumber;

	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;
	cout << "Average part count for " << totalNumber << " sets: " << average << endl;

}



//============================  PRICE INFORMATION  =================================

void PriceInformation(vector<Character>& characters)
{
	// Show the average, minimum and maximum prices.


	//========== AVERAGE ===========

	double price = 0.0;
	double average = 0;

	unsigned int i = 0;
	for (i = 0; i < characters.size(); i++)
	{
		price += characters[i].GetPrice();
	}
	average = price / totalNumber;

	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;
	cout << "Average price for " << totalNumber << " sets: $" << average << endl;
	cout << endl;




	// ===== MIN / MAX VARIABLE INSTANTIATION ===========

	int number = 0;
	string theme;
	string nameOfSet;
	int numOfParts = 0;
	int pieces = 0;


	//========== MINIMUM ===========

	double min = characters[0].GetPrice();

	for (i = 0; i < characters.size(); i++)
	{
		if (characters[i].GetPrice() < min)
		{
			min = characters[i].GetPrice();

			number = characters[i].GetNumber();
			theme = characters[i].GetTheme();
			nameOfSet = characters[i].GetNameOfSet();
			numOfParts = characters[i].GetNumOfParts();
			pieces = characters[i].GetPieces();

		}
	}

	cout << "Least expensive set:" << endl;
	cout << "Name: " << nameOfSet << endl;
	cout << "Number: " << number << endl;
	cout << "Theme: " << theme << endl;
	cout << "Price: $" << min << endl;
	cout << "Minifigures: " << numOfParts << endl;
	cout << "Piece count: " << pieces << endl;
	cout << endl;



	//========== Maximum ===========

	double max = characters[0].GetPrice();

	for (i = 0; i < characters.size(); i++)
	{
		if (characters[i].GetPrice() > max)
		{
			max = characters[i].GetPrice();

			number = characters[i].GetNumber();
			theme = characters[i].GetTheme();
			nameOfSet = characters[i].GetNameOfSet();
			numOfParts = characters[i].GetNumOfParts();
			pieces = characters[i].GetPieces();

		}
	}

	cout << "Most expensive set:" << endl;
	cout << "Name: " << nameOfSet << endl;
	cout << "Number: " << number << endl;
	cout << "Theme: " << theme << endl;
	cout << "Price: $" << max << endl;
	cout << "Minifigures: " << numOfParts << endl;
	cout << "Piece count: " << pieces << endl;
}



//============MiniFigure Information (i.e. Number of Parts Info)
void MiniFigureInformation(vector<Character>& characters)
{
	//Show the average number of minifigures and the set information for the set with the most minifigures

	unsigned int i = 0;

	//======= Average ========


	int numOfParts = 0;
	int average = 0;

	for (i = 0; i < characters.size(); i++)
	{
		numOfParts += characters[i].GetNumOfParts();
	}
	average = numOfParts / totalNumber;

	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;
	cout << "Average number of minifigures: " << average << endl;
	cout << endl;


	//======= Max Minifigures =========

	int number = 0;
	string theme;
	string nameOfSet;
	int pieces = 0;
	double price = 0.0;

	int max = characters[0].GetNumOfParts();

	for (i = 0; i < characters.size(); i++)
	{
		if (characters[i].GetNumOfParts() > max)
		{
			max = characters[i].GetNumOfParts();

			price = characters[i].GetPrice();
			number = characters[i].GetNumber();
			theme = characters[i].GetTheme();
			nameOfSet = characters[i].GetNameOfSet();
			pieces = characters[i].GetPieces();
		}
	}


	cout << "Set with the most minifigures: " << endl;
	cout << "Name: " << nameOfSet << endl;
	cout << "Number: " << number << endl;
	cout << "Theme: " << theme << endl;
	cout << "Price: $" << price << endl;
	cout << "Minifigures: " << max << endl;
	cout << "Piece count: " << pieces << endl;
}


//============= Bought One Of Everything =================

void BoughtOneOfEverything(vector<Character>& characters)
{
	double price = 0.0;
	int pieces = 0;
	int numOfParts = 0;

	unsigned int i = 0;

	for (i = 0; i < characters.size(); i++)
	{
		price += characters[i].GetPrice();
		pieces += characters[i].GetPieces();
		numOfParts += characters[i].GetNumOfParts();
	}

	cout << "Total number of sets: " << totalNumber << endl;
	cout << endl;

	cout << "If you bought one of everything..." << endl;
	cout << "It would cost: $" << price << endl;
	cout << "You would have " << pieces << " pieces in your collection" << endl;
	cout << "You would have an army of " << numOfParts << " minifigures!" << endl;

}


