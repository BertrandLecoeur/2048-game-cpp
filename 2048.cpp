#include "modele.h"


/*Plateau deplacement(Plateau plateau, int direction) {
  switch ( direction ) {
    case GAUCHE:
      return deplacementGauche(plateau);
    case DROITE:
      return deplacementDroite(plateau);
    case HAUT:
      return deplacementHaut(plateau);
    case BAS:
      return deplacementBas(plateau);
    default:
      cerr << "Deplacement non-autorise!" << endl;
      exit(-1);
  }
}*/


int main(){
    int score=0;
    srand(time(NULL)); // j'ai mis cette ligne afin d'initilaiser mon générateur de nombre aléatoire aléatoirement.
    Plateau t=plateauInitial();
    cout<<dessine (t);
    Plateau tprecedent=plateauVide();
    while((estGagnant(t)==false)and(coupPossible(t)==true)){
                tprecedent=t;
                cout<<"Veuillez taper sur la touche h de votre clavier pour aller en haut,b pour aller en bas,g pour aller a gauche et d pour aller a droite"<<endl;
                string a;
                //string a=lettrealeatoire();
                cin>>a;
                t=deplacement(t,a,score);
                while (t==tprecedent){
                    cout<<"cette direction napporte rien"<<endl;
                    //string a=lettrealeatoire();
                    cin>>a;
                    //t=deplacement(t,a,score);
                }
                int deuxouquatre=tireDeuxOuQuatre();
                int c=rand()%4;
                int d=rand()%4;
                while(t[c][d]!=0){
                    c=rand()%4;
                    d=rand()%4;
                }
                t[c][d]=deuxouquatre;
                cout<<dessine (t);
                cout <<"Score:"<<score<<endl;
 
        
    }
          if(coupPossible(t)==false){
                    cout<<"Vous avez perdu"<<endl;
          }else if(estGagnant(t)==true){
              cout<<"Félicitations, vous avez gagné!"<<endl;
          }
                
    
    
        
    
        return 0;
}

