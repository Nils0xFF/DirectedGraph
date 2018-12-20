#pragma once
#include <string>
#include <vector>
#include "Edge.h"

class Edge;

class Vertex
{
private:
	std::string bez = "";
	std::vector<Edge*> edges;
	bool marked = false;
	Vertex* prev = NULL;
	float dist = FLT_MAX;

public:
	Vertex(std::string);
	~Vertex();
	
	std::string getBez() { return this->bez; }
	const std::vector<Edge*>& getEdges() { return this->edges; }
	void addEdge(Edge* e);

	void mark() { this->marked = true; }
	bool getMarked() { return this->marked; }
	void setPrev(Vertex* p) { this->prev = p; }
	Vertex* getPrev() { return this->prev; }
	void setDist(float dist) { this->dist = dist; }
	float getDist() { return this->dist; }
	void reset() {
		this->prev = NULL;
		this->marked = false;
		this->dist = FLT_MAX;
	};

	friend std::ostream& operator<< (std::ostream& stream, const Vertex& edge) {
		stream << edge.bez;
		return stream;
	}

};

