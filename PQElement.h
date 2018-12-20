#pragma once
#include <string>

class PQElement {
private:
	float priority; /* priority of the element */
	std::string id; /* id of the element */
public:
	// default constructor
	PQElement() { this->priority = -1; this->id = -1; }
	// parameter constructors
	PQElement(float prio) { this->priority = prio; }
	PQElement(std::string id, float prio) { this->id = id; this->priority = prio; }
	// copy constructor
	PQElement(const PQElement& pq);
	// destructor
	~PQElement() {};
	// overloaded assignment operator
	PQElement& operator=(const PQElement& pq);
	// overloaded compare operators
	bool operator== (const PQElement& e) const {
		return priority == e.priority;
	}
	bool operator< (const PQElement& e) const {
		return priority < e.priority;
	}
	bool operator>(const PQElement& e) const {
		return this->priority > e.priority;
	}
	// getter and setter methods
	float getPriority(void) const { return this->priority; }
	std::string getId(void) const { return this->id; }
	void setPriority(float priority) { this->priority = priority; }
	void setId(std::string id) { this->id = id; }

};