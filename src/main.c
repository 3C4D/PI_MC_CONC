// Programme principal

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "donnees_pi.h"
#include "pi_thread.h"

int nb_thread = 4;
int nb_tirage = 10000000;

int main(void){
  pthread_t threads[nb_thread];
  void *retours[nb_thread];
  int i, total= 0;

  // Initialisation de l'horloge
  srand(time(NULL));

  // Démarrage des threads
  for(i = 0; i < nb_thread; i++){
    pthread_create(&threads[i], NULL, calcul_pi, NULL);
  }

  // Attente de leur variable de retour et ajout au total
  for(i = 0; i < nb_thread; i++){
    pthread_join(threads[i], &retours[i]);
    printf("%d\n", ((retour_pi_t *)retours[i])->score);
    total += ((retour_pi_t *)retours[i])->score;
  }

  // On multiplie la valeur par 4 pour avoir PI
  printf("%f\n", ((double)total)/nb_tirage*4);

  exit(0);
}
