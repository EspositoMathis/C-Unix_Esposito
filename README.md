1) la version parallèle est plus rapide car elles execute les 10 donéees en même temps.
2) Parralèle :
    1 000 : 88ms
    1 000 000 : 90 023ms
   Séquenciel :
    1 000 : 870ms
    1 000 000 : 861 376ms

6) 4 coeurs
7) Vu qu'on associe ube valeur par thread, 100 threads serait inutile il y en aurait que 10 utilisé 

----
1) si on augmente le nombre de threads, il y aurait plus de race condition donc avec un seule thread le resultat serait correct car aucune race condition.
2) changer le nombre d'itération ne changera pas le nombre d'erreur mais la difference (+ ou - grande).
3) 