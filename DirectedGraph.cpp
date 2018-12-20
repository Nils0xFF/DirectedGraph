#include "DirectedGraph.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

DirectedGraph::~DirectedGraph() {
	for (auto v : vertecies) {
		delete v.second;
	}
}

DirectedGraph::DirectedGraph(string fileName) {
	ifstream f; //filestream for the input file
	string line; // the current line
	string start; // start of the new Edge
	string end; // end of the new Edge
	float weight = 0.0f; // weight of the new Edge
	bool invalid = false; // check if given input was valid
	// open the file
	f.open(fileName, ios::in);
	// if file was opend succesfully
	if (f.is_open()) {
		// while there is still content in the file
		while (!f.eof()) {
			// get the entire line
			while (getline(f, line)) {
				int i = 0; // counter for valid check
				invalid = false; // current line is valid
				stringstream sstream(line);
				// get the line value by value
				while (getline(sstream, line, ' ')) {
					// if there are to many values in the line it is invalid
					if (i > 2) {
						invalid = true;
						break;
					}
					// parse the values
					if (i == 0) start = line;
					else if (i == 1) end = line;
					else weight = atof(line.c_str());
					i++;
				}
				// if the line is valid, parse it
				if (!invalid) { 
					// cout << start << " " << end << " " << weight << endl; 
					addEdge(start, end, weight);
				}
			}

		}
		f.close();
	}
	else {
		cout << "Cant open file !!" << endl;
	}
}

Vertex* DirectedGraph::addVertex(string name){
	if (vertecies.find(name) == vertecies.end()) {
		vertecies[name] = new Vertex(name);
	}
	return vertecies[name];

}

void DirectedGraph::addEdge(string start, string end, float weight) {
	Vertex* vertStart = addVertex(start);
	Vertex* vertEnd = addVertex(end);
	vertStart->addEdge(new Edge(vertStart, vertEnd, weight));
}

void DirectedGraph::BFS(std::string start, std::string end, int limit) {
	if (start == end) {
		cout << "Please enter two different vertices!!" << endl;
		return;
	}
	if (vertecies.find(start) == vertecies.end() || vertecies.find(end) == vertecies.end()) {
		cout << "Please enter two valid vertices!!" << endl;
		return;
	}
	int length = BFS(vertecies[start], vertecies[end], limit);
	if (length == -1) {
		cout << "No path was found!!" << endl;
	}
	else {
		Vertex* target = vertecies[end];
		cout << "There is the following path with a length of: " << length << " edges" << endl;
		stack<Vertex*> path;
		Vertex* temp = target->getPrev();
		while (temp != NULL) {
			path.push(temp);
			temp = temp->getPrev();
		}
		while (!path.empty()) {
			cout << *path.top() << "->";
			path.pop();
		}
		cout << *target;
	}
	
	for (auto v : vertecies) {
		v.second->reset();
	}
}

int DirectedGraph::BFS(Vertex* start, Vertex* end, int limit) {
	start->setDist(0);
	start->setPrev(NULL);
	start->mark();
	int length = 0;
	queue<Vertex*> myQueue;
	myQueue.push(start);

	int i = 0;
	while (!myQueue.empty()) {
		Vertex* temp = myQueue.front();
		myQueue.pop();
		if (temp->getDist() > limit) return -1;
		if (temp == end) break;
		for (Edge* e : temp->getEdges()) {
			if (!e->getEnd()->getMarked()) {
				e->getEnd()->mark();
				e->getEnd()->setPrev(temp);
				myQueue.push(e->getEnd());
				e->getEnd()->setDist(temp->getDist() + 1);
			}
		}
	}
	if (end->getPrev() == NULL) return -1;
	while (end->getPrev() != NULL) {
		length++;
		end = end->getPrev();
	}
	return length;
}

void DirectedGraph::singleShortestPath(string start) {
	if (vertecies.find(start) == vertecies.end()) {
		cout << "Please enter a valid vertex!!" << endl;
		return;
	}
	singleShortestPath(vertecies[start]);
	cout << "All paths: " << endl;
	Vertex* target;
	Vertex* temp;
	stack<Vertex*> path;
	for (auto vert : vertecies) {
		if (vert.first != start) {
			target = vert.second;
			temp = target->getPrev();
			if (temp == NULL) {
				cout << "No path to ";
			}
			else {
				while (temp != NULL) {
					path.push(temp);
					temp = temp->getPrev();
				}
				while (!path.empty()) {
					cout << *path.top() << "->";
					path.pop();
				}
			}
			cout << *target;
			cout << " Weigth: " << target->getDist() << endl;
		}
	}
	
	for (auto v : vertecies) {
		v.second->reset();
	}
}

void DirectedGraph::singleShortestPath(Vertex* start) {
	PriorityQueue pq(vertecies.size() + 1);
	for (auto v : vertecies) {
		v.second->setPrev(NULL);
		if (v.second == start) {
			v.second->setDist(0);
		}
		else v.second->setDist(FLT_MAX);
		pq.insert(PQElement(v.second->getBez(), v.second->getDist()));
	}
	while (!pq.empty()) {
		PQElement v = pq.extractMin();
		Vertex* currentVertex = vertecies[v.getId()];
		currentVertex->mark();
		for (Edge* e : currentVertex->getEdges()) {
			Vertex* end = e->getEnd();
			if (end->getMarked() == false && end->getDist() > currentVertex->getDist() + e->getWeight()) {
				e->getEnd()->setDist(currentVertex->getDist() + e->getWeight());
				e->getEnd()->setPrev(currentVertex);
				pq.update(e->getEnd()->getBez(), end->getDist());
			}
		}
	}
}