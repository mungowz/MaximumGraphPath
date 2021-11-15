#ifndef Graph_cpp
#define Graph_cpp

#include "Graph.hpp"

void Graph::addNode(int key) {
    Node<int> *newNode = new Node<int>(key);
    nodes->push_back(newNode);
}

void Graph::setItemNode(int index, int weight, int adj) {
    this->nodes->at(index)->addEdge(nodes->at(adj));
    this->nodes->at(index)->addWeight(weight);
}

void Graph::inizialized_singleSource(int i) {
    for (auto &u : *nodes) {
        u->set_dTime(numeric_limits<int>::min());
        u->setParent(nullptr);
    }
    nodes->at(i)->set_dTime(0);
}

void Graph::relax(int u, int v, int j) {
    if (nodes->at(v)->get_dTime() < nodes->at(u)->get_dTime() + nodes->at(u)->getWeight(j))
        nodes->at(v)->set_dTime(nodes->at(u)->get_dTime() + nodes->at(u)->getWeight(j));
        nodes->at(v)->setParent(nodes->at(u));
}


void Graph::showWay(int i) {
    for (auto u : *nodes) {
        if (u->get_dTime() <= -2000000000) cout << i << " -> " << u->getKey() << " -infty" << endl;
        else cout << i << " -> " << u->getKey() << " " << u->get_dTime() << endl;
    }
}

void Graph::MaxWeightPath(int i) {
    inizialized_singleSource(i);
    auto S = DFS();
    while (!S.empty()){
        auto u = S.top();
        S.pop();
        auto j = 0;
        for (auto &v : u->getAdjacentList()) { 
            relax(u->getKey(), v->getKey(), j);
            j++;
        }
    }
    showWay(i);
}

stack<Node<int>*> Graph::DFS() {
    stack<Node<int>*> S;
    for (auto &u : *nodes) u->setColor(WHITE);
    for (auto &u : *nodes) if (u->getColor() == WHITE) DFS_visit(u, S); 
    return S;
}

void Graph::DFS_visit(Node<int> *u, stack<Node<int>*> &S) {
    u->setColor(GRAY);
    for (auto &v : u->getAdjacentList()) if (v->getColor() == WHITE) DFS_visit(v, S);
    u->setColor(BLACK);
    S.push(u);
}

#endif /* Graph_cpp */