#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <sstream>
#include <stdexcept>



using namespace std;

//const int GAUCHE = 7, DROITE = 4, HAUT = 8, BAS = 2;
typedef vector<vector<int>> Plateau;
//Des fonctions peuvent être ajoutés à ce fichier si besoin est (fonctions pour mettre à jour le score par exemple)



Plateau plateauVide();         
  
        
    
/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial();

    

    
 /** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre();
 

/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau,int& score);

/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau,int& score);

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau,int& score);

/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau,int& score);




/** affiche un Plateau
 * @param p le Plateau
 **/
string dessine(Plateau p);

/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTermine(Plateau plateau);

/** permet de savoir si une partie est gagnée
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);
            
string lettrealeatoire();

bool estPlein(Plateau t);

Plateau deplacement(Plateau p, string a,int& score);

bool coupPossible(Plateau p);

int nbspaces(int n);

vector<int>elimine(int a,vector<int>tab);

vector<int> addition(vector<int>T,int i);

vector<int> agrege(vector<int>T,int i, int& score);

vector<int> inverse(vector<int>t);

Plateau changecolonneetligne(Plateau t);

            
            
         
    
                
                
                
                
                
                
                
                
    
