#include "PQElement.h"


PQElement::PQElement(const PQElement& pq) {
	*this = pq;
}

PQElement& PQElement::operator=(const PQElement& pq) {
	this->priority = pq.priority;
	this->id = pq.id;
	return *this;
}