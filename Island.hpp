/*
    La classe Island produrrà il grafo in base agli input forniti dal file e permetterà l'interazione
    utente programma. La classe Island ha un rapporto di tipo HAS A con la classe Graph, tra gli
    attributi privati è istanziata una variabile di tipo Graph , che rappresenta il grafo letto
    in input. La lettura del file avviene il costruttore della classe Island, a questo viene passato il
    nome del file da leggere sotto forma di stringa. Tramite il parametro in di tipo ifstream
    apre il file mediante il metodo open, verificherà inoltre se la sua apertura avviene in modo corretto
    mediante il metodo fail. In caso di errore viene prodotto dal programma un messaggio diagnostico di 
    errore. I primi due numeri interi del file corrispondono al numero di nodi ed al numero di archi del
    grafo. Tramite l'operatore di flusso >> questi passano da in per essere memorizzati in numVertex e
    numEdges. Vengono aggiunti poi i nodi con chiave da 0 ad N-1 (NumVertex-1), sapendo il numero totale
    di vertici, come espresso dalla traccia, questi saranno identificati dalle chiavi che vanno da 0 ad 
    N-1. Ogni riga dopo la prima contiene tre numeri interi che corrispondono rispettivamente a: il nodo
    di partenza, il nodo di arrivo, e il peso. Questi vengono salvati nelle varibili node, adj e weight.
    Tramite al metodo setItemNode assegneremo al nodo in posizione node, l'adiacenza del nodo adj con
    un peso weight. Viene scelto di usare una classe ulteriore specifica per il problema in modo da
    garantire la massima "sicurezza" alla struttura del grafo letto in input, in questo modo infatti
    l'utente non potra modificarla, ma potrà solamente interagire con essa tramite i metodi che la 
    classe Island richiama sul grafo letto in input. 
*/

#ifndef Island_hpp
#define Island_hpp

#include <fstream>
#include <string>
#include <stack>

#include "Graph.cpp"

class Island {
    private:
        ifstream in;
        Graph graph;
    public:
    /*
        Costruttore della classe Island.
    */
        Island(string nameFile);
    /*
        Distruttore della classe Island
    */
        ~Island(){};
    /*
        Metodo che richiamando il metodo get_numVertex del grafo valorizza il numero di vertici. 
    */
        int getNumVertex(){graph.get_numVertex();};
    /*
        Metodo che richiamando il metodo get_numEdges del grafo valorizza il numero di archi. 
    */
        int getNumEdges(){graph.get_numEdges();};
    /*
        Metodo che richiamando il metodo MaxWeightPath del grafo calcolando il cammino massimo. 
    */
        void maxWay(int i){this->graph.MaxWeightPath(i);};
};

#endif /* Island_hpp */