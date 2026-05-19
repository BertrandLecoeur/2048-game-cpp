#include "modele.h" 

/** permet de savoir combien d'espace il faut mettre avant et apres le nombre en fonction de sa taille
 * @param un entier n
 * @return un entier
**/
int nbspaces(int n){
    if (n<10){
        return 5;
    } else if(n<100){
        return 4;
    } else if(n<1000){
        return 3;
    } else if(n<10000){
        return 2;
    } else{
        return 1;
    }
}






/** elimine tout les 0 dans un tableau
 * @param un entier a et un tableau
 * @retrun un tableau sans 0
**/
vector<int> elimine(int a,vector<int>tab){
    //cout<<"entrée dans la fonction elimine"<<endl;
    vector<int> resultat;
    for(int i=0;i<tab.size();i++){
        if(tab[i]!=a){
            resultat.push_back(tab[i]);
        }
    }
    return resultat;
}

      
      

/** additionne deux cases adajacentes
 * @param un tableau T et un entier i
 * @return un tableau où les 2 cases sont additionées
**/
vector<int> addition(vector<int>T,int i){
    //cout<<"entrée dans la fonction addition"<<endl;
    int N = T.size();
    if (i+1<N){
        vector<int>T2(0);
        for (int k=0; k<N;k++){
            if (k<i){
                T2.push_back(T[k]);
            }else if (k==i){
                T2.push_back(T[i]+T[i+1]);
            }else if (k>i+1){
                T2.push_back(T[k]);
            }
        }
        return T2;
            
     }else{
        return T;
     }
}

    

/** additionne 2 cases ayant la même valeur et  crée un tableau
 * @param un tableauT et un entier i
 * @return un tableau avec les 2 cases à la valeur identique additionnées
**/
vector<int> agrege(vector<int>T,int i, int& score){
    int N = T.size();
    if (i+1<N){
        if (T[i]==T[i+1]){
            score=score+T[i]+T[i+1];
            return agrege(addition(T,i),i+1,score);
            
        }else{
            return agrege(T,i+1,score);
        }
    }else{
        return T;
    }
}

    



    
/** permet d'inverser un tableau, ainsi le dernier element devient le premier, l'avant dernier devient le deuxième etc...
 * @param un tabelau t d'entiers
 * @return le tableau inversé
**/
vector<int> inverse(vector<int>t){
    //cout<<"entrée dans la fonction inverse"<<endl;
    vector<int> tableauinverse(4);
    for (int i=0;i<t.size();i++){
        tableauinverse[i]=t[t.size()-i-1];
        
    
    }
    return tableauinverse;

}

    
    
    



/** fonction qui transforme une colonne en ligne(transposée)
 * @param un tableau 2d t
 * @return un tableau 2d resultat où les colonnes de t sont maintenant les lignes de resultat
**/
Plateau changecolonneetligne(Plateau t){
    //cout<<"entrée dans la fonction changecolonneetligne"<<endl;
    Plateau resultat=t;
    for (int i=0;i<t.size();i++){
        for (int j=0;j<t.size();j++){
            resultat[i][j]=t[j][i];
        }
    }
    return resultat;
    
}



/** génère un Plateau de dimensions 4*4 ne contenant que des 0
 *  @return un Plateau vide
 **/
Plateau plateauVide(){
    //cout<<"entrée dans la fonction playeauVide"<<endl;
    Plateau Tableau(4,vector<int>(4));
    return Tableau;
}
//CHECK(plateauVide()==[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]])
/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial(){ // 
    //cout<<"entrée dans la fonction palteauInitial"<<endl;
    Plateau t=plateauVide();
    int a=tireDeuxOuQuatre();
    int b=tireDeuxOuQuatre();
    int c=rand()%4;
    int d=rand()%4;
    int e=rand()%4;
    int f=rand()%4;
    while ((e==c)and(f==d)){
        e=rand()%4;
        f=rand()%4;
    }
    t[c][d]=a;
    t[e][f]=b;
    return t;
        
}

            
    


    
 /** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre(){
    //cout<<"entrée dans la fonction tireDeuxOuQuatre"<<endl;
    int a=rand()%10;
    if (a>=1){
        return 2;
    }else{
        return 4;
    }
}

/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau, int& score){
    Plateau resultat=plateau;
    Plateau resultat2=resultat;
    for (int i=0;i<resultat.size();i++){
        resultat[i]=elimine(0,plateau[i]);
        resultat2[i]=agrege(resultat[i],0,score);
        int nbr_0=plateau[i].size()-resultat2[i].size();
        
        for (int j=0;j<nbr_0;j++){
            resultat2[i].push_back(0);
        }
        
    }
    return resultat2;
    
}






/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau, int& score){
Plateau tableauinverse(4,vector<int>(4));
    
    Plateau resultat2(4,vector<int>(4));
    for (int i=0;i<plateau.size();i++){
        tableauinverse[i]=inverse(plateau[i]);
    }
    Plateau resultat=deplacementGauche(tableauinverse,score);
    for (int j=0;j<plateau.size();j++){
        resultat2[j]=inverse(resultat[j]);
    }
    return resultat2;
}

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau, int& score){
Plateau resultat=changecolonneetligne(plateau);
    Plateau resultat2=deplacementGauche(resultat,score);
    Plateau resultat3=resultat2;
    for (int i=0;i<plateau.size();i++){
        for (int j=0;j<plateau.size();j++){
            resultat3[j][i]=resultat2[i][j];
        }
    }
   
    return resultat3;
}

/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau, int& score){
Plateau resultat=changecolonneetligne(plateau);
    Plateau resultat2=deplacementDroite(resultat,score);
    Plateau resultat3=resultat2;
    for (int i=0;i<plateau.size();i++){
        for (int j=0;j<plateau.size();j++){
            resultat3[j][i]=resultat2[i][j];
        }
    }
   
    return resultat3;
}

/** affiche un Plateau
 * @param p le Plateau
 **/
string dessine(Plateau p){
    std::stringstream sstream;
    system("clear");
    string sline("*****************************\n");

    // parcours des lignes
    for( int i=0; i<p.size(); i++ ){
        sstream << sline;
        // parcours des colonnes
        // *[a espaces][nombre][b espaces]
        // de sorte que a + taille nombre + b = cte = 6
        for( int j=0; j<p.size(); j++ ){
            if (p[i][j]==0){
                sstream<<"*      ";
            }else{
                sstream << "*";
                int n = nbspaces(p[i][j]);
                int a = (int)n/2; //(int) car je veux avoir la partie entière de n/2
                int b = n-a;
                for(int k=0; k<a; k++){
                    sstream << " ";
                }
                sstream << p[i][j];
                for(int k=0; k<b; k++){
                    sstream << " ";
                }
            }
        }
        sstream << "*\n";
    }
    sstream << sline;

    string num_str = sstream.str();
    
    return num_str;
}


/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTermine(Plateau plateau){
    for (int i=0;i<plateau.size();i++){
        for (int j=0;j<plateau.size();j++){
            if (plateau[i][j]!=0){
                return false;
            }
        }
    }
    return true;
}

    
  
 


/** permet de savoir si une partie est gagnée
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau){
    //cout<<"entrée dans la fonction estGagnant"<<endl;
    for (int i=0;i<plateau.size();i++){
        for (int j=0;j<plateau.size();j++){
            if (plateau[i][j]==2048){
                return true;
            }
        }
    }
    return false;
}

/** fonction qui tire une direction au hasard
 * return une lettre donnant un déplacement
**/
string lettrealeatoire(){
    int a=rand()%4;
    if (a==0){
        return "h";
    }else if(a==1){
        return "g";
    }else if(a==2){
        return "b";
    }else{
        return "d";
    }
    

}

/** fonction qui renvoie false si il y a un 0 dans le tabelau 2d, et false sinon
 * @param un tableau 2d t
 * return true si le tabelau est plein(il n'y a plus de 0), et true sinon
**/
bool estPlein(Plateau t){
    for (int i=0;i<t.size();i++){
        for (int j=0;j<t.size();j++){
            if (t[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

/** fonction qui permet de se déplacer dans n'importe quelle direction
 * @param un tableau 2d p et une chaine de caractère a
 * @erturn un nouveau tableau 2d avec le déplacement effectué
**/
Plateau deplacement(Plateau p, string a, int& score){
    Plateau t;
    if (a=="g"){
        t=deplacementGauche(p,score);
    }else if (a=="d"){
        t=deplacementDroite(p,score);
    }else if (a=="h"){
        t=deplacementHaut(p,score);
    }else if (a=="b"){
        t=deplacementBas(p,score);
    }
    return t;
}


/** vérifie qu'un déplacement est possible ou pas
 * @param un tableau 2d
 * return true si on peut encore jouer, et false sinon
**/
bool coupPossible(Plateau p){
    if (estPlein(p)==false){
        return true;
    } else{
        int s1=0;
        Plateau t;
        t=deplacementBas(p,s1);
        t=deplacementHaut(p,s1);
        t=deplacementGauche(p,s1);
        t=deplacementDroite(p,s1);
        if (s1>0){
            return true;
        } else{
            return false;
        }
    }
}


/** fonction qui permet de déplacer grâce aux flèches
**/
/**Plateau deplacement2(Plateau p){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        p=deplacementGauche(p);**/
    

                
                
                
                
                