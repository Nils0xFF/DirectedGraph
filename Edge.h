#pragma once

#include <string>
#include <sstream>
#include "Vertex.h"
class Vertex;

class Edge
{
private:
	Vertex* start = NULL;
	Vertex* end = NULL;
	float weight = 1.0f;

public:
	Edge(Vertex* start, Vertex* end, float w):start(start),end(end),weight(w) {};
	~Edge() {};

	Vertex* getStart() { return this->start; }
	void setStart(Vertex* v) { this->start = v; }
	
	Vertex* getEnd() { return this->end; }
	void setEnd(Vertex* v) { this->end = v; }

	float getWeight() { return this->weight; }
	void setWeight(float w) { if (w > 0) this->weight = w; }

	friend std::ostream& operator<< (std::ostream& stream, const Edge& edge);
	
};
