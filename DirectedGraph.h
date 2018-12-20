#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "Vertex.h"
#include "Edge.h"
#include "PriorityQueue.h"

class DirectedGraph
{
private:
	std::map<std::string, Vertex*> vertecies;

protected:
public:
	DirectedGraph(std::string);
	~DirectedGraph();

	void BFS(std::string start, std::string end, int limit);
	int BFS(Vertex* start, Vertex* end, int limit);

	void singleShortestPath(std::string start);
	void singleShortestPath(Vertex* start);

	Vertex* addVertex(std::string);
	void addEdge(std::string , std::string, float weight);

	void toString() {
		for (auto v : vertecies) {
			for (Edge* e : v.second->getEdges()) {
				std::cout << *e << std::endl;
			}
		}
	}

	friend std::ostream& operator<< (std::ostream& stream, const DirectedGraph& graph) {
		for (auto v : graph.vertecies) {
			for (Edge* e : v.second->getEdges()) {
				stream << *e << std::endl;
			}
		}
		return stream;
	}
};

