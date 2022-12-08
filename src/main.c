// Programme principal

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <sys/time.h>
#include "donnees_pi.h"
#include "pi_thread.h"
#include "usage.h"

int nb_thread;
int nb_tirage;

int main(int argc, char **argv){
  pthread_t *threads;
  struct timeval debut, fin;
  donnees_pi_t arguments[8];
  double temps;
  int i, total = 0;

  if(argc < 2){
    usage(argv[0]);
    exit(-1);
  }

  // Nombre de threads
  nb_thread = (argc > 2)?atoi(argv[2]):get_nprocs();
  threads = malloc(sizeof(pthread_t) * nb_thread);

  nb_tirage = atoi(argv[1]);      // Nombre de tirage
  srand(time(NULL));              // Initialisation de l'horloge
  printf("\nLe programme démarre avec %d threads\n\n", nb_thread);
  gettimeofday(&debut, NULL);     // Temps au début

  for(i = 0; i < nb_thread; i++){ // Démarrage des threads
    pthread_create(&threads[i], NULL, calcul_pi, &arguments[i]);
  }

  // Attente de leur variable de retour et ajout au total
  for(i = 0; i < nb_thread; i++){
    pthread_join(threads[i], NULL);
    total += arguments[i].score;
  }

  gettimeofday(&fin, NULL);       // Temps  à la fin

  // On multiplie la valeur par 4 pour avoir PI
  printf("Résultat : PI = %f\n\n", ((double)total)/nb_tirage*4);

  temps = (fin.tv_sec-debut.tv_sec) + (fin.tv_usec-debut.tv_usec)/1000000.0;
  printf("Temps de calcul : %f sec\n\n", temps);

  exit(0);
}
