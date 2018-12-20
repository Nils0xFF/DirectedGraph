#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "PQElement.h"

using namespace std;

class PriorityQueue {
	int amount; /* current amount of elements in the queue */
	int size; /* max size of the queue */
	int refLength; /* length of the referenceArray*/
	PQElement *queue; /* fuer das Feld */
	map<string, int> ref; /* referenceArray used for increas and delete operations by id */
public:
	// parameter constructor with default value
	PriorityQueue(int size = 1000) {
		this->size = size;
		this->refLength = size;
		amount = 0;
		queue = new PQElement[size + 1];
	}
	// destructor
	~PriorityQueue();
	
	// string methods
	string toString() const;
	operator string() const;

	// getters
	PQElement& getMin(void) const;
	int getSize(void) const { return size; }
	int getParentIndex(int i) const;
	int getRightChildIndex(int i) const;
	int getLeftChildIndex(int i) const;
	bool empty() {
		return amount < 1;
	}

	// queue functionallity

	// extracts the element with the smallest prio and returns it
	PQElement extractMin(void);
	// checks if the minHeap is valid
	bool isValid() const;
	// inserts an given element into the queue and restores the Heap
	void insert(const PQElement&);
	// restores the heap of a given subtree starting at index i
	void heapDown(int i);
	// restores the heap of a given parent tree starting at index i
	void heapUp(int i);
	// swaps the elements in the queue and the corresponding positions in the refArray
	void swap(PQElement& a, PQElement& b);

	// increasing the priority of an element using sequential search
	void increaseSearch(string id, float value);
	// increasing the priority of an element using the refArray
	void increase(string id, float value);
	// removing an element using sequential search
	void removeSearch(string id);
	// removing an element using the refArray
	void remove(string id);
	
	// resets the queue
	void reset() {
		this->amount = 0;
	}

	void update(string id, float prio) {
		if (ref.find(id) != ref.end()) {
			float oldPrio = queue[ref[id]].getPriority();
			queue[ref[id]].setPriority(prio);
			if (prio > oldPrio) heapDown(ref[id]);
			else heapUp(ref[id]);
		}
	}
};