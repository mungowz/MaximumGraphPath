/*
    La classe Node rappresenterà i nodi (isole) del nostro grafo. La classe viene resa template per 
    rendere più generico il suo uso in caso di altri utilizzi. L'attributo template T key è la chiave
    nodo, i tre attributi privati interi color, dTime, fTime rappresentano rispettivamente il colore,
    il tempo di inizio ed il tempo di fine lettura del nodo. Il colore può essere valorizzato secondo i 
    tre parametri delle tre define eseguite nella parte del precompilatore: WHITE (1), GRAY (2) e 
    BLACK (3). Tra gli attributi privati vi è anche: parent di tipo puntatore alla classe che indica il 
    padre del nodo, adjacentList di tipo list di puntatori alla classe node ovvero la lista di adiacenze
    del nodo e il vector di int weightVet. WeightVet conterrà il valore del peso dell'arco tra il nodo 
    considerato e uno adiacente ad esso, infatti la lista di adiacenze ed il nodo avranno lo stesso size.
    Se consideriamo il nodo alla posizione i della lista di adiacenze, il peso dell'arco tra il nodo in
    questione e il nodo del parametro si troverà alla posizione i di weightVet. Infatti quando 
    aggiungeremo un'adiacenza ad un nodo generico u, questo verrà aggiunto richiamando il metodo addEdge
    della classe node, addEdge aggiungerà u ad adjacentList del nodo considerato mediante il metodo
    push_back della lista, quindi il nodo u sarà aggiunto nella coda della lista. Consecutivamente verrà
    richiamato il metodo addWeight il quale aggiungerà il peso dell'arco compreso tra u ed il nodo
    considerato in coda a weightVet. In questo modo riusciremmo a definire il peso dell'arco considerato.
*/

#ifndef Node_hpp
#define Node_hpp

#include <iostream>
#include <list>
#include <limits>
#include <vector>

using namespace std;

#define WHITE 1
#define GRAY  2
#define BLACK 3

template <typename T> 
class Node {
    private: 
        T key;
        int color;
        int dTime;
        int fTime; 
        Node<T> *parent;
        list<Node<T>*> adjacentList;
        vector<int> weightVet;
    public:
    /*
        Costruttore della classe Node con un parametro in input.
    */
        Node(T key) {
            this->key = key;
            color = WHITE;
            parent = nullptr;
            dTime = numeric_limits<int>::max();
            fTime = numeric_limits<int>::max();
        };
    /*
        Costruttore della classe Node senza parametro in input.
    */
        Node() {
            color = WHITE;
            parent = nullptr;
            dTime = numeric_limits<int>::max();
            fTime = numeric_limits<int>::max();
        };
    /*
        Distruttore della classe Node
    */
        ~Node(){}
    /*
        Metodo per aggiungere un nodo alla lista di adiacenze del vertice considerato.
    */
        void addEdge(Node<T> *newEdge){adjacentList.push_back(newEdge);};
    /*
        Metodo per restituire la lista di adiacenze del nodo.
    */
        list<Node<T>*> getAdjacentList(){return adjacentList;};
    /*
        Metodo per valorizzare il parametro key.
    */
        void setKey(T key){this->key = key;};
    /*
        Metodo per restituire il valore del parametro key.
    */
        T getKey(){return key;};
    /*
        Metodo per valorizzare il parametro color.
    */
        void setColor(int color){this->color = color;};
    /*
        Metodo per restituire il valore del parametro color.
    */
        int getColor(){return color;};
    /*
        Metodo per valorizzare il parametro parent.
    */
        void setParent(Node<T> *parent){this->parent = parent;};
    /*
        Metodo per restituire il valore del parametro parent.
    */
        Node<T> *getParent(){return parent;};
    /*
        Metodo per valorizzare il valore del parametro dTime.
    */
        void set_dTime(int dTime){this->dTime = dTime;};
    /*
        Metodo per restituire il valore del parametro dTime.
    */
        int get_dTime(){return dTime;};
    /*
        Metodo per valorizzare il parametro fTime.
    */
        void set_fTime(int fTime){this->fTime = fTime;};
    /*
        Metodo per restituire il valore del parametro fTime.
    */
        int get_fTime(){return fTime;};
    /*
        Metodo per aggiungere un peso al vettore dei pesi degli archi weightVet.
    */
        void addWeight(int weight){weightVet.push_back(weight);};
    /*
        Metodo per restituire il valore del peso di un arco.
    */
        int getWeight(int i){return weightVet.at(i);};
    /*
        Metodo per restituire il numero di pesi e quindi anche di adiacenze ed archi del nodo.
    */
        int getWeightSize(){return weightVet.size();};
};

#endif /* Node_hpp */
