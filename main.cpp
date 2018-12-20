#include "DirectedGraph.h"
#include <iostream>

using namespace std;

int main()
{
	DirectedGraph graph("OS_Map.txt");
	// cout << d;
	while (1) {
		int selection;
		string start;
		string end;
		cout << "What do you want to do?" << endl;
		cout << "(1) Check if a path shorter then a given limit exitst" << endl;
		cout << "(2) Get the single shortest Path of a city" << endl;
		cout << "(Else) End the programm" << endl;
		cout << "Please select: ";
		cin >> selection;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (selection < 1 || selection > 2) break;
		cout << "Enter the first City: ";
		cin >> start;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (selection)
		{
		case 1:
			int limit;
			cout << "Enter the second City: ";
			cin >> end;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Max amount of Edges: ";
			cin >> limit;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "----------Ausgabe-----------" << endl << endl;
			graph.BFS(start, end, limit);
			break;
		case 2:
			cout << endl << "----------Ausgabe-----------" << endl << endl;
			graph.singleShortestPath(start);
			break;
		default:
			break;
		}
		cout << endl << endl << "----------Ausgabe-----------" << endl << endl;
	}
	return 0;
}

