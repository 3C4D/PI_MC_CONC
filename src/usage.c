// Fonction d'usage du programme

#include <stdlib.h>
#include <stdio.h>

// Fonction affichant l'usage correct du programme
void usage(char *s){
  fprintf(stderr, "\nUsage : %s <nb_tirage> [nb_thread]\n", s);
  fprintf(stderr, "    - nb_tirage : nombre de tirage à réaliser\n");
  fprintf(stderr, "    - nb_thread : nombre de threads souhaités\n\n");
}
