#include <iostream>
#include <string>

using namespace std;

class Board {
public :
	void defplateau(){
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				plateau[y][x] = '*';
			}
		}
	}

	void affichage() {
		cout << "   1 2 3 \n";
		cout << "-----------\n";
		for (int y = 0; y < 3; y++) {
			cout << y + 1 << ". ";
			for (int x = 0; x < 3; x++) {
				cout << plateau[y][x] << " ";
			}
			cout << "\n";
		}
	}

	void changement(int a, int b, char symbole) {
		plateau[a][b] = symbole;
	}

private :
	char plateau[3][3];
};

int main()
{
	int ligne, colonne, joueur;
	char signe = 'X', zone[3][3];
	Board plateaujeu;
	plateaujeu.defplateau();
	plateaujeu.affichage();
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			zone[y][x] = '*';
		}
	}

	int a = 0, victoire = 0;
	while (a < 9 && victoire == 0) {
		if (a % 2 == 0) {
			joueur = 1;
			signe = 'X';
		}
		else {
			joueur = 2;
			signe = 'O';
		}
		cout << "\nAu tour du joueur " << joueur << " (symbole "<< signe << " ).\nChoisir une ligne : ";
		cin >> ligne;
		cout << "Choisir une colonne : ";
		cin >> colonne;
		if (zone[ligne - 1][colonne - 1] == '*') {
			zone[ligne - 1][colonne - 1] = signe;
		}
		else {
			a += -1;
		}
		cout << "\n\n   1 2 3 \n";
		cout << "-----------\n";
		for (int y = 0; y < 3; y++) {
			cout << y + 1 << ". ";
			for (int x = 0; x < 3; x++) {
				cout << zone[y][x] << " ";
			}
			cout << "\n";
		}
		//tour(0, 0, joueur, signe);
		a++;
		for (int c = 0; c < 3; c++) {
			if (zone[c][0] == zone[c][1] && zone[c][1] == zone[c][2] && zone[c][1] != '*') {
				victoire = 1;
			}
			if (zone[0][c] == zone[1][c] && zone[1][c] == zone[2][c] && zone[1][c] != '*') {
				victoire = 1;
			}
			if (zone[1][1] == zone[2][2] && zone[2][2] == zone[0][0] && zone[1][1] != '*') {
				victoire = 1;
			}
			if (zone[2][0] == zone[1][1] && zone[1][1] == zone[0][2] && zone[1][1] != '*') {
				victoire = 1;
			}
		}
	}

	if (victoire == 1) {
		cout << "\nJoueur " << joueur << " a gagne !";
	}
	else {
		cout << "\nMatch nul !";
	}

	cout << "\n\n\n\n";
	system("PAUSE");
	return 0;
}