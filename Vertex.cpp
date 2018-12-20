#include "Vertex.h"
#include <string>

using namespace std;

Vertex::Vertex(string name)
{
	this->bez = name;
}


Vertex::~Vertex()
{
	for (int i = 0; i < edges.size(); i++) {
		delete edges.at(i);
	}
}

void Vertex::addEdge(Edge* e) {
	if (e->getStart() != this) return;
	this->edges.push_back(e);
	return;
}