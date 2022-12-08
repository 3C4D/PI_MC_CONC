// Programme principal

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include "donnees_pi.h"
#include "pi_thread.h"
#include "usage.h"

int nb_thread;
int nb_tirage;

int main(int argc, char **argv){
  pthread_t threads[nb_thread];
  void *retours[nb_thread];
  int i, total= 0;

  if(argc < 2){
    usage(argv[0]);
    exit(-1);
  }

  // Nombre de threads
  if(argc > 2){
    nb_thread = atoi(argv[2]);
  }
  else{
    nb_thread = get_nprocs();
  }

  // Nombre de tirage
  nb_tirage = atoi(argv[1]);

  // Initialisation de l'horloge
  srand(time(NULL));

  printf("\nLe programme démarre avec %d threads\n\n", nb_thread);

  // Démarrage des threads
  for(i = 0; i < nb_thread; i++){
    pthread_create(&threads[i], NULL, calcul_pi, NULL);
  }

  // Attente de leur variable de retour et ajout au total
  for(i = 0; i < nb_thread; i++){
    pthread_join(threads[i], &retours[i]);
    total += ((retour_pi_t *)retours[i])->score;
  }

  // On multiplie la valeur par 4 pour avoir PI
  printf("Résultat : PI = %f\n\n", ((double)total)/nb_tirage*4);

  exit(0);
}
