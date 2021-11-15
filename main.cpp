/*
    T1
    Q2
*/

/*
    Dopo il terribile terremoto del Dicembre 2019, a seguito di ingenti investimenti economici, la regina
    dell'arcipelago di Grapha-Nui è riuscita a ripristinare i collegamenti tra le isole. È ora necessario
    incentivare il turismo nell’arcipelago per rimpinguare le casse del governo ed a tal fine il Primo 
    Ministro vuole sapere quali collegamenti tra le isole pubblicizzare maggiormente. Viene nuovamente 
    convocata la famosa consulente informatica Ros Walker con il compito di calcolare i percorsi che 
    massimizzano la soddisfazione dei turisti, partendo da una generica isola verso tutte le altre isole.
    Ros ha a disposizione la piantina dell’arcipelago con la rete di collegamenti tra le isole. Per ogni 
    collegamento la piantina specifica la direzione ed un valore (anche negativo) che misura la qualità 
    del collegamento. I collegamenti tra le isole non danno origine a cicli. 
    Dati di input:
    È assegnato un file di testo contenente nel primo rigo due interi separati da uno spazio: il numero N 
    delle isole (numerate da 0 ad N-1) ed il numero P dei ponti. I successivi P righi contengono ciascuno
    tre numeri I1, I2 e Q per indicare che è possibile raggiungere l’isola I2 dall’isola I1 dove Q 
    rappresenta la qualità del collegamento.
*/

/*
    All'interno del main del programma viene istanziata una variabile island della classe Island,
    attraverso questa verrà richiamato il costruttore della Island al quale viene passato la stringa 
    contenente il nome del file da leggere. Dopodichè si entra nel while che conterrà il menù con il
    quale l'utente dovrà interagire. Il menù ed il while sono gestiti dalla variabile di tipo int choice
    e dalla variabile di tipo char stop. Se la variabile stop assume il valore 0 si uscirà dal while
    interrompendo il programma. Il programma stamperà il numero di nodi e archi letti da file, subito 
    dopo l'utente immetterà da tastiera il numero corrispondete all'isola che vuole identificare come 
    sorgente, il numero digitato valorizzerà la variabile choice. Verrano stampati i valori del percorso 
    massimo dalla sorgente ad ogni nodo, i nodi che non sono raggiungibili dalla sorgente saranno 
    contrassegnati da meno infinito. Terminata la stampa dei cammini massimi, l'utente sceglierà se 
    visualizzare nuovamente il risultato del programma ma a partire da una sorgente diversa, o uscire dal 
    programma digitando 0 in modo da far assumere alla variabile stop il medesimo valore. Viene scelto il
    tipo char per la variabile stop poichè se l'utente vuole continuare ad interagire con il programma
    può digitare qualsiasi altro carattere.
*/

#include "Island.cpp"

int main()
{
    Island island("Island.txt");
    int choice;
    char stop;
     while (stop != '0') {  
        cout << "Grapha-Nui with " << island.getNumVertex() << " islands and " << island.getNumEdges() << " bridges was created from the file" << endl;
        cout << "Choose an island from 0 to " << island.getNumVertex()-1 << " from which routes are calculated that maximize tourist satisfaction ";
        cin >> choice;
        cout << "Path from island "<< choice << " to others which maximaze tourist satisfaction" << endl;
        island.maxWay(choice);
        cout << endl;
        cout << "Type 0 to exit any other key to continue "; 
        cin >> stop; 
     }
    return 0;
}