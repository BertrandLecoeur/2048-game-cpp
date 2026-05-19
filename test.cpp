#include "modele.h"
/** Infrastructure minimale de test**/
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

typedef vector<int> liste;

void testnbspaces(){
    CHECK(nbspaces(3)==5);
    CHECK(nbspaces(2000)!=1);
}
void testelimine(){
    CHECK(elimine(0,{0,6,4,7,0})==(liste ({6,4,7})));
    CHECK(elimine(5,{5,5,4,5})!=(liste ({5,4})));    
}

void testaddition(){
    CHECK(addition({2,4,2,2},0)==(liste({6,2,2})));
    CHECK(addition({4,4,4,4},2)==(liste({4,4,8})));
}

void testagrege(){
    int score=0;
    CHECK(agrege({2,4,2,2},0,score)==(liste({2,4,4})));
    CHECK(agrege({4,4,4,4},0,score)==(liste({8,8})));
}

void testinverse(){
    CHECK(inverse({3,4,5,6})==(liste({6,5,4,3})));
}

void testchangecolonneetligne(){
    CHECK(changecolonneetligne({{0,4},{3,5}})==(Plateau({{0,3},{4,5}})));
}

void testplateauVide(){
    CHECK(plateauVide()==(Plateau({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}})));
}

void testdeplacementGauche(){
    int score=0;
    CHECK(deplacementGauche({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},score)==(Plateau({{2,0,0,0},{8,0,0,0},{16,0,0,0},{2,8,0,0}})));
}

void testdeplacementDroite(){
    int score=0;
    CHECK(deplacementDroite({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},score)==(Plateau({{0,0,0,2},{0,0,0,8},{0,0,0,16},{0,0,2,8}})));
}

void testdeplacementHaut(){
    int score=0;
    CHECK(deplacementHaut({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},score)==(Plateau({{8,8,4,2},{2,0,0,8},{0,0,0,4},{0,0,0,0}})));
}

void testdeplacementBas(){
    int score=0;
    CHECK(deplacementBas({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},score)==(Plateau({{0,0,0,0},{0,0,0,2},{8,0,0,8},{2,8,4,4}})));
}



void testestTermine(){
    CHECK(estTermine({{0,0,0,0},{0,0,0,2},{8,0,0,8},{2,8,4,4}})==false);
    CHECK(estTermine({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}})==true);
}

void testestGagnant(){
    CHECK(estGagnant({{0,2048,0,0},{0,0,0,2},{8,0,0,8},{2,8,4,4}})==true);
    CHECK(estGagnant({{0,0,2,0},{0,2,4,8},{0,0,2,2},{0,16,0,8}})==false);
}

void testestPlein(){
    CHECK(estPlein({{4,4,4,4},{2,4,8,2},{8,2,2,8},{2,8,4,4}})==true);
    CHECK(estPlein({{4,0,0,0},{4,4,0,0},{0,2,0,0},{0,0,16,8}})==false);
}

void testdeplacement(){
    int score=0;
    CHECK(deplacement({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},"g",score)==(Plateau({{2,0,0,0},{8,0,0,0},{16,0,0,0},{2,8,0,0}})));
    CHECK(deplacement({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},"d",score)==(Plateau({{0,0,0,2},{0,0,0,8},{0,0,0,16},{0,0,2,8}})));
    CHECK(deplacement({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},"h",score)==(Plateau({{8,8,4,2},{2,0,0,8},{0,0,0,4},{0,0,0,0}})));
    CHECK(deplacement({{0,0,0,2},{0,4,4,0},{8,0,0,8},{2,4,0,4}},"b",score)==(Plateau({{0,0,0,0},{0,0,0,2},{8,0,0,8},{2,8,4,4}})));
}

void testcoupPossible(){
    CHECK(coupPossible({{4,4,4,0},{2,0,8,2},{8,0,0,8},{2,8,0,4}})==true);
    CHECK(coupPossible({{4,4,4,4},{2,4,8,2},{8,2,2,8},{2,8,4,4}})==true);
    CHECK(coupPossible({{4,2,8,16},{2,4,16,2},{8,2,4,8},{2,8,16,2}})==false);
}
                        
                        
          
                                      



 

    


int main(){
    
    testnbspaces();
    testelimine();
    testaddition();
    testagrege();
    testinverse();
    testchangecolonneetligne();
    testplateauVide();
    testdeplacementGauche();
    testdeplacementDroite();
    testdeplacementHaut();
    testdeplacementBas();
    testestTermine();
    testestGagnant();
    testestPlein();
    testdeplacement();
    testcoupPossible();
    
    
    return 0 ;
}
    
    
