/*
    *progetto Battleship
    *Vadym Zaverukha - 08/01/2026
    *Battleship Game
*/

#define DIM 10


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inizializzaMatrice(char matrice[DIM][DIM]){
for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            matrice[i][j] = '-';
        }
    }
}


void piazzaNave( char matrice[DIM][DIM], int length ) {
    // Funzione per piazzare una nave di lunghezza "length" nella matrice
    int riga = rand() % DIM;
    int colonna = rand() % (DIM-(length-1)); // Per evitare overflow
    for (int i=0; i<length; i++) matrice[riga][colonna+i] = '*';
}
void piazzaNavi(char matrice[DIM][DIM]){
    piazzaNave(matrice,4);
    piazzaNave(matrice,3);
    piazzaNave(matrice,3);
}
void stampaMatrice( char matrice[DIM][DIM] ) {
    cout << endl << "  ";
    for (int i=1; i<=DIM; i++) cout << i << " ";
    for (int i=0; i<DIM; i++) {
        cout << endl << (char)('A'+i) << " ";
        for (int j=0; j<DIM; j++) {
            cout << matrice[i][j] << " ";
        }
    }
    cout << endl << endl;
}
void play(char matrice[DIM][DIM]){
    string shot;
    stampaMatrice(matrice);3
    while(true){
       cout << "Inserisci la coordinata (es. A5): ";
       cin >> shot; 
       int riga = shot[0] - 'A';
       int colonna = stoi(shot.substr(1)) - 1;
       if(matrice[riga][colonna] == 'X' || matrice[riga][colonna] == 'O'){
            cout << "Hai già sparato in questa posizione. Riprova." << endl;
            continue;
       }
       if(matrice[riga][colonna] == '*'){
            cout << "Colpito!" << endl;
            matrice[riga][colonna] = 'X';
       } else {
            cout << "Mancato!" << endl;
            matrice[riga][colonna] = 'O';
        }
    }
}

int main() {
    srand(time(NULL));
    char m[DIM][DIM];
    inizializzaMatrice(m);
    piazzaNavi(m);
	stampaMatrice(m);

	return 0;
}