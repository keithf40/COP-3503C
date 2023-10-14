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

int ReadCSV1(const char* filename)
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

int ReadCSV2(const char* filename)
{
	ifstream file(filename);

	string buffer;
	getline(file, buffer);
	if (file.is_open() == false)
	{
		cerr << "File is not open";
		return -1;
	}

	ReadCSV(file, lego2);

	return 0;
}

int ReadCSV3(const char* filename)
{
	ifstream file(filename);

	string buffer;
	getline(file, buffer);
	if (file.is_open() == false)
	{
		cerr << "File is not open";
		return -1;
	}

	ReadCSV(file, lego3);

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

LegoSet FindLeastExpensive(const vector<LegoSet>& legosets)
{
	LegoSet minPrice;
	minPrice._price = 9999;
	for (const LegoSet& legoset : legosets)
	{
		if (legoset._price < minPrice._price)
			minPrice = legoset;
	}

	return minPrice;
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

LegoSet FindLargestMinifigs(const vector<LegoSet>& legosets)
{
	LegoSet maxMinifigs;
	maxMinifigs._minifigs = 0;
	for (const LegoSet& legoset : legosets)
	{
		if (legoset._minifigs > maxMinifigs._minifigs)
			maxMinifigs = legoset;
	}

	return maxMinifigs;
}

int main()
{
	std::cout << std::fixed << setprecision(2);
	std::cout << "Which file(s) to open?\n";
	std::cout << "1. lego1.csv" << endl;
	std::cout << "2. lego2.csv" << endl;
	std::cout << "3. lego3.csv" << endl;
	std::cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/

	if (option == 1)
		ReadCSV1("lego1.csv");
	else if (option == 2)
		ReadCSV1("lego2.csv");
	else if (option == 3)
		ReadCSV1("lego3.csv");
	else
	{
		ReadCSV1("lego1.csv");
		ReadCSV2("lego2.csv");
		ReadCSV3("lego3.csv");
	}

	std::cout << "1. Most Expensive set" << endl;
	std::cout << "2. Largest piece count" << endl;
	std::cout << "3. Search for set name containing..." << endl;
	std::cout << "4. Search themes..." << endl;
	std::cout << "5. Part count information" << endl;
	std::cout << "6. Price information" << endl;
	std::cout << "7. Minifigure information" << endl;
	std::cout << "8. If you bought one of everything..." << endl;
	std::cout << "0. Exit" << endl;

	int choice;
	std::cin >> choice;
	std::cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/

	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	if (choice == 1)
	{
		LegoSet max = FindMostExpensive(lego1);

		std::cout << "Total number of sets: " << lego1.size() << endl;
		std::cout << "The most expensive set is:" << endl;
		std::cout << "Name: " << max._name << endl;
		std::cout << "Number: " << max._number << endl;
		std::cout << "Theme: " << max._theme << endl;
		std::cout << "Price: $" << max._price << endl;
		std::cout << "Minifigures: " << max._minifigs << endl;
		std::cout << "Piece count: " << max._pieces << endl;
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
		getline(cin, input);

		int count1 = lego1.size();
		int count2 = lego2.size();
		int count3 = lego3.size();

		cout << "Total number of sets: " << (count1 + count2 + count3) << endl << endl;

		bool truth = false;

		for (unsigned int i = 0; i < lego1.size(); i++)
		{
			if (lego1[i]._name.find(input) != string::npos)
			{
				truth = true;
			}
		}

		for (unsigned int i = 0; i < lego2.size(); i++)
		{
			if (lego2[i]._name.find(input) != string::npos)
			{
				truth = true;
			}
		}

		for (unsigned int i = 0; i < lego3.size(); i++)
		{
			if (lego3[i]._name.find(input) != string::npos)
			{
				truth = true;
			}
		}

		if (truth == true)
			cout << "Sets matching \"" << input << "\":" << endl << endl;

		for (unsigned int i = 0; i < lego1.size(); i++)
		{
			if (lego1[i]._name.find(input) != string::npos)
			{
				cout << lego1[i]._number << " " << lego1[i]._name << " $" << lego1[i]._price << endl;
				truth = true;
			}
		}

		if (option == 4)
		{
			for (unsigned int i = 0; i < lego2.size(); i++)
			{
				if (lego2[i]._name.find(input) != string::npos)
				{
					cout << lego2[i]._number << " " << lego2[i]._name << " $" << lego2[i]._price << endl;
					truth = true;
				}
			}
		}

		if (option == 4)
		{
			for (unsigned int i = 0; i < lego3.size(); i++)
			{
				if (lego3[i]._name.find(input) != string::npos)
				{
					cout << lego3[i]._number << " " << lego3[i]._name << " $" << lego3[i]._price << endl;
					truth = true;
				}
			}
		}
		
		if (truth == false)
			cout << "No sets found matching that search term";
	}

	else if (choice == 4)
	{
		string input;
		getline(cin, input);

		int count1 = lego1.size();
		int count2 = lego2.size();
		int count3 = lego3.size();

		cout << "Total number of sets: " << (count1 + count2 + count3) << endl << endl;

		cout << "Sets matching \"" << input << "\":" << endl << endl;

		for (unsigned int i = 0; i < lego1.size(); i++)
		{
			if (lego1[i]._theme == input)
			{
				cout << lego1[i]._number << " " << lego1[i]._name << " $" << lego1[i]._price << endl;
			}
		}

		for (unsigned int i = 0; i < lego2.size(); i++)
		{
			if (lego2[i]._theme == input)
			{
				cout << lego2[i]._number << " " << lego2[i]._name << " $" << lego2[i]._price << endl;
			}
		}

		for (unsigned int i = 0; i < lego3.size(); i++)
		{
			if (lego3[i]._theme == input)
			{
				cout << lego3[i]._number << " " << lego3[i]._name << " $" << lego3[i]._price << endl;
			}
		}
	}

	else if (choice == 5)
	{
		int totalParts = 0;
		for (unsigned int i = 0; i < lego1.size(); i++)
			totalParts = totalParts + lego1[i]._pieces;
		std::cout << "Total number of sets: " << lego1.size() << endl << endl;
		std::cout << "Average part count for " << lego1.size() << " sets: " << totalParts / lego1.size() << endl;
	}

	else if (choice == 6)
	{
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
				
		double totalPrice1 = 0;
		double totalPrice2 = 0;
		double totalPrice3 = 0;

		for (unsigned int i = 0; i < lego1.size(); i++)
			totalPrice1 = totalPrice1 + lego1[i]._price;
		count1 = lego1.size();
		//std::cout << "Total number of sets: " << lego1.size() << endl << endl;

		if (option == 4)
		{
		//totalPrice2 = totalPrice1;
		for (unsigned int i = 0; i < lego2.size(); i++)
			totalPrice2 = totalPrice2 + lego2[i]._price;
		count2 = lego2.size();
		//std::cout << "Total number of sets: " << lego1.size() << endl << endl;
		}

		if (option == 4)
		{
		//totalPrice3 = totalPrice2;
		for (unsigned int i = 0; i < lego3.size(); i++)
			totalPrice3 = totalPrice3 + lego3[i]._price;
		count3 = lego3.size();
		//std::cout << "Total number of sets: " << lego1.size() << endl << endl;
		}
				
		std::cout << "Total number of sets: " << (count1 + count2 + count3) << endl << endl;

		std::cout << "Average price for " << (count1 + count2 + count3) << " sets: $" << ((totalPrice1 + totalPrice2 + totalPrice3) / (count1 + count2 + count3)) << endl << endl;

		LegoSet min = FindLeastExpensive(lego1);
		LegoSet min2 = FindLeastExpensive(lego2);
		LegoSet min3 = FindLeastExpensive(lego3);
		
		if (min2._price < min._price)
		{
			min._number = min2._number;
			min._theme = min2._theme;
			min._name = min2._name;
			min._minifigs = min2._minifigs;
			min._pieces = min2._pieces;
			min._price = min2._price;
		}
		
		if (min3._price < min._price)
		{
			min._number = min3._number;
			min._theme = min3._theme;
			min._name = min3._name;
			min._minifigs = min3._minifigs;
			min._pieces = min3._pieces;
			min._price = min3._price;
		}
	
		LegoSet max = FindMostExpensive(lego1);
		LegoSet max2 = FindMostExpensive(lego2);
		LegoSet max3 = FindMostExpensive(lego3);

		if (max2._price > max._price)
		{
			max._number = max2._number;
			max._theme = max2._theme;
			max._name = max2._name;
			max._minifigs = max2._minifigs;
			max._pieces = max2._pieces;
			max._price = max2._price;
		}

		if (max3._price > max._price)
		{
			max._number = max3._number;
			max._theme = max3._theme;
			max._name = max3._name;
			max._minifigs = max3._minifigs;
			max._pieces = max3._pieces;
			max._price = max3._price;
		}
		
		//LegoSet min = FindLeastExpensive(lego1);
		std::cout << "Least expensive set:" << endl;
		std::cout << "Name: " << min._name << endl;
		std::cout << "Number: " << min._number << endl;
		std::cout << "Theme: " << min._theme << endl;
		std::cout << "Price: $" << min._price << endl;
		std::cout << "Minifigures: " << min._minifigs << endl;
		std::cout << "Piece count : " << min._pieces << endl;

		//LegoSet max = FindMostExpensive(lego1);
		std::cout << "Most expensive set:" << endl;
		std::cout << "Name: " << max._name << endl;
		std::cout << "Number: " << max._number << endl;
		std::cout << "Theme: " << max._theme << endl;
		std::cout << "Price: $" << max._price << endl;
		std::cout << "Minifigures: " << max._minifigs << endl;
		std::cout << "Piece count : " << max._pieces << endl;
	}

	else if (choice == 7)
	{
		int totalMinifigs1 = 0;
		for (unsigned int i = 0; i < lego1.size(); i++)
			totalMinifigs1 = totalMinifigs1 + lego1[i]._minifigs;
		int count1 = lego1.size();
		//std::cout << "Total number of sets: " << lego1.size() << endl << endl;

		int totalMinifigs2 = 0;
		for (unsigned int i = 0; i < lego2.size(); i++)
			totalMinifigs2 = totalMinifigs2 + lego2[i]._minifigs;
		int count2 = lego2.size();
		//std::cout << "Total number of sets: " << lego1.size() << endl << endl;

		int totalMinifigs3 = 0;
		for (unsigned int i = 0; i < lego3.size(); i++)
			totalMinifigs3 = totalMinifigs3 + lego3[i]._minifigs;
		int count3 = lego3.size();
		//std::cout << "Total number of sets: " << lego1.size() << endl << endl;

		std::cout << "Total number of sets: " << (count1 + count2 + count3) << endl << endl;

		std::cout << "Average number of minifigures: " << ((totalMinifigs1 + totalMinifigs2 + totalMinifigs3) / (count1 + count2 + count3)) << endl << endl;

		LegoSet max = FindLargestMinifigs(lego1);
		std::cout << "Set with the most minifigures:" << endl;
		std::cout << "Name: " << max._name << endl;
		std::cout << "Number: " << max._number << endl;
		std::cout << "Theme: " << max._theme << endl;
		std::cout << "Price: $" << max._price << endl;
		std::cout << "Minifigures: " << max._minifigs << endl;
		std::cout << "Piece count : " << max._pieces << endl;
	}

	else if (choice == 8)
	{
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;

		double totalPrice1 = 0;
		double totalPrice2 = 0;
		double totalPrice3 = 0;

		for (unsigned int i = 0; i < lego1.size(); i++)
			totalPrice1 = totalPrice1 + lego1[i]._price;
		
		int totalMinifigs1 = 0;
		int totalMinifigs2 = 0;
		int totalMinifigs3 = 0;

		for (unsigned int i = 0; i < lego1.size(); i++)
			totalMinifigs1 = totalMinifigs1 + lego1[i]._minifigs;

		int totalPieces1 = 0;
		int totalPieces2 = 0;
		int totalPieces3 = 0;

		for (unsigned int i = 0; i < lego1.size(); i++)
			totalPieces1 = totalPieces1 + lego1[i]._pieces;
		count1 = lego1.size();

		if (option == 4)
		{
			for (unsigned int i = 0; i < lego2.size(); i++)
				totalPrice2 = totalPrice2 + lego2[i]._price;
						
			for (unsigned int i = 0; i < lego2.size(); i++)
				totalMinifigs2 = totalMinifigs2 + lego2[i]._minifigs;
						
			for (unsigned int i = 0; i < lego2.size(); i++)
				totalPieces2 = totalPieces2 + lego2[i]._pieces;
			count2 = lego2.size();
		}

		if (option == 4)
		{
			
			for (unsigned int i = 0; i < lego3.size(); i++)
				totalPrice3 = totalPrice3 + lego3[i]._price;
						
			for (unsigned int i = 0; i < lego3.size(); i++)
				totalMinifigs3 = totalMinifigs3 + lego3[i]._minifigs;
						
			for (unsigned int i = 0; i < lego3.size(); i++)
				totalPieces3 = totalPieces3 + lego3[i]._pieces;
			count3 = lego3.size();
		}

		std::cout << "Total number of sets: " << (count1 + count2 + count3) << endl << endl;

		std::cout << "If you bought one of everything..." << endl;
		std::cout << "It would cost: $" << (totalPrice1 + totalPrice2 + totalPrice3) << endl;
		std::cout << "You would have " << (totalPieces1 + totalPieces2 + totalPieces3) << "pieces in your collection" << endl;
		std::cout << "You would have an army of " << (totalMinifigs1 + totalMinifigs2 + totalMinifigs3) << " minifigures!" << endl;
	}

	return 0;
}
