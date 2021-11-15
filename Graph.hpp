/*
    La classe Graph rappresenta l'implementazione di un grafo. La classe viene resa specifica sugli 
    interi, dato che il tipo in input è composto da numeri interi. Graph ha un rapporto HAS A con la
    classe node. Vi è infatti un attributo privato di tipo vector di puntatori alla classe Node cioè 
    nodes, il quale verrà allocato in memoria dal costruttore della classe Node. Nodes conterrà tutti i 
    nodi facenti parte del grafo, gli archi e i pesi fra questi sono rappresentati dall'attributo 
    adjacentList e weightVet della classe node. Gli attributi privati numVertex e numEdges assumeranno 
    il valore del numero di nodi ed del numero di archi del grafo. L'attributot time terra conto del 
    tempo impiegato per visitare un nodo all'interno di una visita. La funzione inizialized_singleSource 
    inizializza il parametro dTime di tutti i nodi a -infinito (numeric_limits<int>::min()) ed il 
    parametro parent a nullptr, solo il nodo di posizione i avrà il parametro dTime inizializzato a 0, 
    questo nodo sarà identificabile come sorgente. Il metodo DFS ovvero la visita in profondità 
    del grafo ci permetterà di svolgere l'ordinamento topologico dei nodi del grafo mediante uno stack.
    Questo sarà passato come puntatore al metodo DFS_visit e salverà l'ordine di precedenza dei vari
    nodi. Lo stack contenete i nodi ordinati in modo lineare è il valore di ritorno del metodo.Il 
    metodo MaxWeightPath calcolerà il cammino massimo da un nodo sorgente verso tutti gli altri, il nodo
    sorgente è quello identificato dalla posizione i all'interno del vettore dei nodi. MaxWeightPath 
    richiamerà il meto inzialized_single_source su i e "riceverà" lo stack proveniente dal metodo DFS.
    Verranno estratti tutti i nodi, appena un nodo viene preso dalla cima dello stack, si scorre la sua
    lista di adiacenze. Ad ogni nodo appartenente alla lista viene incrementato il contatore intero j in
    base al quale si riconosce l'arco e il peso dell'arco che si sta analizzando. Prima di analizzare
    un'altro nodo infatti si richiama il metodo relax sul al quale viene passato la chiave del nodo u 
    estratto dallo stack, la chiave del nodo v della lista di adiacenze di u e j. La funzione relax
    infatti riconoscerà il nodo u del vettore dei nodi perchè questo corrisponde alla posizione della 
    chiave di u, il nodo v del vettore dei nodi perchè questo corrisponde alla posizione della 
    chiave di v e il peso dell'arco compreso tra u e v perchè corrisponde a quello nella posizione j 
    nel vettore dei pesi di u. Il metod relax migliorerà la stima del cammino massimo nei casi
    possibili cambiando il valore del parametro dTime e parent v.
*/

#ifndef Graph_hpp
#define Graph_hpp

#include <stack>
#include <vector>
#include "Node.hpp"

class Graph {
    private:
        vector<Node<int>*> *nodes;
        int numVertex;
        int numEdges;
        int time;
    /*
        Metodo usato per inizializzare i nodi.
    */
        void inizialized_singleSource(int i);
    /*
        Metodo usato per migliorare la stima del cammino massimo.
    */
        void relax(int u, int v, int j);
    /*
        Metodo usato per mostrare il valore del cammino massimo da i a tutti gli altri nodi.
    */
        void showWay(int i);
    /*
        Metodo che sfruttando la visita in profondità implementa un ordinamento topologico.
    */
        stack<Node<int>*> DFS();
    /*
        Metodo complementare per la visita in profondità e ordinamento topologico.
    */
        void DFS_visit(Node<int> *u, stack<Node<int>*> &S);
    public:
    /*
        Costruttore della classe Graph.
    */
        Graph(){nodes = new vector<Node<int>*>;};
    /*
        Distruttore della classe Graph.
    */
        ~Graph(){};
    /*
        Metodo che restituisce il vettore di nodi.
    */
        vector<Node<int>*> *getNodes(){return nodes;};
    /*
        Metodo che aggiune un nodo al grafo.
    */
        void addNode(int key);
    /*
        Metodo che valorizza il peso e aggiunge un adiacenza al nodo in posizione index.
    */
        void setItemNode(int index, int weight, int adj);
    /*
        Metodo che valorizza l'attributo numVertex ovvero il numero di vertici.
    */
        void set_numVertex(int numVertex){this->numVertex = numVertex;};
    /*
        Metodo che restituisce il valore di numVertex ovvero il numero di vertici
    */
        int get_numVertex(){return numVertex;};
    /*
        Metodo che valorizza l'attributo numEdges ovvero il numero di archi.
    */
        void set_numEdges(int numEdges){this->numEdges = numEdges;};
    /*
        Metodo che restituisce il valore di numEdges ovvero il numero di vertici.
    */
        int get_numEdges(){return numEdges;};
    /*  
        Metodo che calcola il cammino massimo dalla sorgente in posizione i verso tutti i gli altri nodi.
    */
        void MaxWeightPath(int i);
};

#endif /* Graph_hpp */