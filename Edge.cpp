#include "Edge.h"

std::ostream& operator<< (std::ostream& stream, const Edge& edge) {
	stream << "From " << *(edge.start) << " to " << *(edge.end) << " with the weight: " << edge.weight;
	return stream;
}