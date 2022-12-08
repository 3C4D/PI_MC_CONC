# Estimation de PI par la méthode de Monte-Carlo

On souhaite estimer la valeur de PI par la méthode de Monte-Carlo à l'aide de
plusieurs threads POSIX (pthreads).

# Compilation

```
make
```

# Exécution

```
Usage : ./bin/PI_CONC <nb_tirage> [nb_thread]
    - nb_tirage : nombre de tirage à réaliser
    - nb_thread : nombre de threads souhaités
```

L'indication du nombre de thread est optionnelle, il est mis par défaut au
nombre de processeurs disponibles sur la machine courante.
