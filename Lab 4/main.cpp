#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class LegoSet
{
public:
	int _number = 0;
	string _theme;
	string _name;
	int _minifigs = 0;
	int _pieces = 0;
	double _price = 0;
};

vector<LegoSet> lego1;
vector<LegoSet> lego2;
vector<LegoSet> lego3;

void ReadCSV(ifstream& file, vector<LegoSet>& legosets)
{
	while (file.eof() == false)
	{
		string buffer;

		LegoSet legoset;

		getline(file, buffer, ',');
		legoset._number = stoi(buffer);

		getline(file, buffer, ',');
		legoset._theme = buffer;

		getline(file, buffer, ',');
		legoset._name = buffer;

		getline(file, buffer, ',');
		legoset._minifigs = stoi(buffer);

		getline(file, buffer, ',');
		legoset._pieces = stoi(buffer);

		getline(file, buffer);
		legoset._price = stod(buffer);

		legosets.push_back(legoset);
	}
}

int ReadCSV(const char* filename)
{
	ifstream file(filename);

	string buffer;
	getline(file, buffer);
	if (file.is_open() == false)
	{
		cerr << "File is not open";
		return -1;
	}

	ReadCSV(file, lego1);

	return 0;
}

LegoSet FindMostExpensive(const vector<LegoSet>& legosets)
{
	LegoSet maxPrice;
	maxPrice._price = 0;
	for (const LegoSet& legoset : legosets)
	{
		if (legoset._price > maxPrice._price)
			maxPrice = legoset;
	}

	return maxPrice;
}

LegoSet FindLargestPiece(const vector<LegoSet>& legosets)
{
	LegoSet maxPieces;
	maxPieces._pieces = 0;
	for (const LegoSet& legoset : legosets)
	{
		if (legoset._pieces > maxPieces._pieces)
			maxPieces = legoset;
	}

	return maxPieces;
}

int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/

	if (option == 1)
		ReadCSV("lego1.csv");
	else if (option == 2)
		ReadCSV("lego2.csv");
	else if (option == 3)
		ReadCSV("lego3.csv");
	else
	{
		cout << "No data";
	}

	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	std::cin >> choice;
	std::cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/

	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	if (choice == 1)
	{
		LegoSet max = FindMostExpensive(lego1);

		cout << "Total number of sets: " << lego1.size() << endl;
		cout << "The most expensive set is:" << endl;
		cout << "Name: " << max._name << endl;
		cout << "Number: " << max._number << endl;
		cout << "Theme: " << max._theme << endl;
		cout << "Price: $" << max._price << endl;
		cout << "Minifigures: " << max._minifigs << endl;
		cout << "Piece count: " << max._pieces << endl;
	}

	else if (choice == 2)
	{
		LegoSet max = FindLargestPiece(lego1);

		std::cout << "Total number of sets: " << lego1.size() << endl;
		std::cout << "The set with the highest parts count:" << endl;
		std::cout << "Name: " << max._name << endl;
		std::cout << "Number: " << max._number << endl;
		std::cout << "Theme: " << max._theme << endl;
		std::cout << "Price: $" << max._price << endl;
		std::cout << "Minifigures: " << max._minifigs << endl;
		std::cout << "Piece count: " << max._pieces << endl;
	}

	else if (choice == 3)
	{
		string input;
		cin >> input;


		

			

	}

	else if (choice == 4)
	{

	}

	else if (choice == 5)
	{

	}

	else if (choice == 6)
	{

	}

	else if (choice == 7)
	{

	}

	else if (choice == 8)
	{

	}

	return 0;
}
