// Routine du thread estimant la valeur de PI/4

#include <stdlib.h>
#include <stdio.h>
#include "donnees_pi.h"

extern int nb_thread;
extern int nb_tirage;

// Rountine d'un pi_thread
void *calcul_pi(void *arg){
  int i, score, nb_tirage_local;
  double x, y;
  retour_pi_t *retour = malloc(sizeof(retour_pi_t));

  score = 0;
  nb_tirage_local = nb_tirage/nb_thread;

  for(i = 0; i < nb_tirage_local; i++){
    x = ((double)(rand()%1001))/1000.0;
    y = ((double)(rand()%1001))/1000.0;

    score += (x * x + y * y <= 1);
  }

  retour->score = score;

  return retour;
}
