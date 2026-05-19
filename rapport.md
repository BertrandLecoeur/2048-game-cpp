---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.14.5
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

# Rapport de projet

Programmation impérative M. Nicolas Thiéry
Rapport de projet - 2048

+++

## Auteur

LECOEUR Bertrand bertrand.lecoeur@universite-paris-saclay.fr L1 MI3

+++

## Résumé du travail effectué

Présentation du jeu :
Le jeu 2048 est un jeu vidéo développé en 2014 par l’italien Gabriele Cirulli qui avait alors 19 ans. Le but de ce jeu est de déplacer des nombres sur une grille pour additionner des nombres de mêmes valeurs. L’utilisateur a gagné lorsqu’il atteint le nombre 2048.

Niveau 0 : Pour obtenir jusqu’à 12/20.

Pour la première fonction « plateauVide », cela a été plutôt simple à faire, je n’ai pas eu de problèmes particuliers.

Pour la fonction » plateauInitial », j’ai dû d’abord faire la fonction « tireDeuxOuQuatre », afin d’avoir soit un 2 soit un 4 sur deux cases aléatoires de mon plateau. J’ai confiance en cette fonction, tout compile bien.

La fonction « tireDeuxOuQuatre » est réalisée, testée.

La fonction « deplacementGauche » a été assez compliquée à développer. Mais elle a finalement été traitée et testée. (Intuitivement, au départ, j’ai tout de suite pensé que je pourrais faire les autres fonctions de déplacement à partir de celle pour aller à gauche. Je me suis inspiré de mon cours en algèbre et géométrie sur les matrices et de leur transposée pour faire déplacement bas et haut).

Les fonctions « deplacementDroite », « deplacementHaut » et « deplacementBas » ont été plus simple à développer grâce à la fonction « deplacementGauche ». Elles sont toutes traitées et testées. J’ai totalement confiance en ces 3 fonctions car tous les tests que j’ai effectués sont concluants. J’ai dû néanmoins écrire quelques fonctions à côtés afin de pouvoir faire ces 4 fonctions. (Par exemple « elimine », « agrege », « addition », « echangecolonneetligne » …).

La fonction « dessine » a été la plus compliqué à trouver, néanmoins elle est traitée et testée, et tout compile parfaitement.

La fonction « estTermine » est traitée et réalisée, même si collectivement, après échange avec mes camarades, nous pensons qu’il y a une erreur dans la documentation fournie.

La fonction « estGagant » est testée et réalisée.

J’ai écrit une fonction permettant à mon jeu de jouer tout seul. Cette fonction est « lettrealeatoire », elle est testée et cela compile très bien.

+++

## Démonstration

En faisant la commande suivante :
	g++ 2048.cpp modele.cpp -o 2048
Le jeu compile, il n’y a aucun problème. Mon intelligence artificielle est intelligente car le programme peut jouer tout seul. Seulement, ce n’est pas sûr qu’elle gagne. Mais sinon lorsque c’est un utilisateur qui joue, il n’y a pas de problème.

Ce premier exemple montre que ma fonction « dessine »  fonctionne, « plateauInitial » aussi, « tireDeuxOuQuatre » également ainsi que « deplacementGauche ».
![image.png](attachment:image.png)

Ces deux exemples montrent que mes fonctions « deplacementDroite », « deplacementHaut » et « deplacementBas » compilent bien.
![image-2.png](attachment:image-2.png)
![image-3.png](attachment:image-3.png)

L’exemple suivant montre que la fonction « estGagnant » compile. (Afin de le montrer, j’ai changé dans ma fonction « estGagnant » 2048 par 16, car je ne suis pas arrivé à atteindre 2048 lorsque je joue).
![image-4.png](attachment:image-4.png)

Le message « Félicitations, vous avez gagné ! » s’affiche bien lorsque j’ai atteint 16.


L’exemple suivant montre que ma fonction « tireDeuxOuQuatre » fonctionne car un 4 a été généré, puis un 2.
![image-5.png](attachment:image-5.png)
![image-6.png](attachment:image-6.png)
 
Enfin, l’exemple suivant montre que la fonction « coupPossible », qui permet de savoir si l’on peut encore jouer ou pas quand le plateau est plein et donc qui permet de savoir si l’on a perdu ou non, fonctionne très bien.
![image-7.png](attachment:image-7.png)

En effet, le message « Vous avez perdu » s’affiche bien lorsque j’ai perdu, c’est-à-dire lorsque mon plateau est plein et que plus aucun déplacement n’est possible.

De plus, tous mes tests compilent très bien.
![image-8.png](attachment:image-8.png)

Enfin, ce dernier exemple montre que mon intelligence artificielle fonctionne car elle joue toute seule, mais n’est pas optimisée pour gagner.
![image-9.png](attachment:image-9.png)

```{code-cell}
! info-111 g++ 2048.cpp -o 2048
```

## Organisation du travail

J’ai mené ce projet tout seul. Tous les jours j’ai travaillé au moins 3 heures pendant 2 semaines. J’ai demandé de l’aide à des binômes et des étudiants de l’université pour m’assurer que j’avais bien compris le projet. Je suis allé à chaque TP afin de pouvoir poser des questions aux professeurs. Je me suis également renseigné sur certains sites et certains forums afin d’obtenir de l’aide pour mon programme (comme le site « waytolearnx »). Enfin, à chaque fois que j’écrivais une fonction, je faisais plusieurs tests de non-régression afin de m’assurer que cela fonctionnait bien.

+++

## Prise de recul

J’ai eu beaucoup de difficultés à faire ce projet. Tout d’abord, j’ai commencé par le projet-Image. Il me semblait plus abordable pour quelqu’un de mon niveau et menant ce projet seul. Finalement au bout d’une semaine, j’ai changé de projet pour celui du jeu de 2048. Ce projet m’a appris beaucoup de choses, comme la compilation de programme, le résonnement et la logique informatique qui sont très différents de ceux que l’on fait en mathématiques. Dans ce projet j’ai principalement utilisé le chapitre sur les tableaux à 2 dimensions, mais également celui sur les boucles conditionnelles. La réalisation dont je suis le plus fier est d’avoir réussi à faire le lien entre ce projet et mon cours d’algèbre dans certaines fonctions et plus particulièrement le principe de transposée de matrices pour la programmation des fonctions permettant d’aller en haut et en bas. 
Finalement, si je devais le refaire, j’accorderais plus de temps à la lecture et l’analyse des 2 sujets pour faire un choix éclairé et définitif. J’ai trouvé le projet très compliqué pour quelqu’un comme moi qui a commencé l’informatique cette année, et je pense qu’il faudrait revoir le barème, car n’avoir « que » 12/20 pour le travail demandé n’est à mon avis pas assez. Avoir une notation qui permettrait d’avoir 14 me parait plus motivant pour l’élève.

```{code-cell}

```

```{code-cell}

```
