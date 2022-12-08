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
  donnees_pi_t *donnees = (donnees_pi_t *)arg;

  score = 0;
  nb_tirage_local = nb_tirage/nb_thread;

  for(i = 0; i < nb_tirage_local; i++){
    x = ((double)(rand()%1001))/1000.0;
    y = ((double)(rand()%1001))/1000.0;

    score += (x * x + y * y <= 1);
  }

  donnees->score = score;

  return NULL;
}
