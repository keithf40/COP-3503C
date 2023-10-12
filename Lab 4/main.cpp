#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

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
	{

	}

	else if (option == 2)
	{

	}

	else if (option == 3)
	{

	}

	else
	{

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
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/
	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	if (choice == 1)
	{

	}

	else if (choice == 2)
	{

	}

	else if (choice == 3)
	{

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
	
	else 
	{

	}

	return 0;
}
