#ifndef Island_cpp
#define Island_cpp

#include "Island.hpp"

Island::Island(string nameFile) {
    in.open(nameFile.c_str());
    if(in.fail()) cout << "Error opening file " << nameFile << endl;
    int numVertex, numEdges, node, adj, weight;
    in >> numVertex >> numEdges;
    graph.set_numEdges(numEdges);
    graph.set_numVertex(numVertex);
    for (auto i = 0; i < numVertex; i++) this->graph.addNode(i);
    for (auto i = 0; i < numEdges; i++) {
        in >> node >> adj >> weight;
        this->graph.setItemNode(node, weight, adj);
    }
}

#endif /* Island.cpp */
