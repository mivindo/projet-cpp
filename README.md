# projet-cpp IVINDO ONANGA Mélissa et TOUISS Haitem


## COMPRÉHENSION DU SUJET

Suite à la lecture du sujet, nous avons compris assez vite que le but du projet était de détecter et reproduire une doite à partir de points (pour ma part. Je pense que d'autres l'auront fait à partir d'une image ppm) et après application de la transformée de Hough.

## MISE EN OEUVRE 

### FICHIERS 

Le projet contitent 4 fichiers principaux. Le fichier .hpp dans lequel nous avons défini les types, noms et paramètres de la classe et ses fonctions; le fichier .cpp dans lequel nous avons implémenté les fonctions; le fichier main.cpp dans lequel nous avons nos tests; le README.md qui est celui-ci et qui sert de rapport.

### CLASSE POINT

Alors nous avons créé une classe Point (car nous allons travailler principalement avec des points). Après avoir implémenté les constructeurs, le déstructeur et une surcharge de l'opérateur '==', nous nous sommes mis à l'implémentation des fonctions qui appliqueront les transformées de Hough pour trouver (m,p) avec 'Hough_x_y' et ($r$, $\theta$) avec 'Hough_r_theta'. 

### SURCHARGES D'AFFICHAGE (fonctions hors classe)

Nous avons implémenté différentes surcharges d'affichages hors de la classe:

- surchage de l'opérateur '<<' pour la classe Point
- affiche(std::vector<$Point$> vect)
- affiche(std::vector<$int$> vect)
- affiche(std::vector<std::vector<$int$>> vect)

Celles-ci serviront à l'affichage des points, vecteurs d'entiers, de points, ou des vecteur de vecteurs d'entiers.

### FONCTIONS
- ### HOUGH_X_Y

Celle-ci était relativement facile à implémenter (vu que nos coordonnées sont des entiers). Elle prend en paramètre le vecteur de points dont on veut détecter la droite, et un N qui nous servira à fixer la taille de l'image. La fonction Hough_x_y retourne la matrice des scores. 

Dans la fonction, nous créons un vecteur de vecteurs qui est notre matrice des scores. 

Pour chaque point de notre vecteur des points:
- Si la matrice scores est vide, pour chaque m compris entre (-N,N) on crée un vecteur v et pour chaque p entre (-N,N), si le couple (m, p) vérifie l'équation p = -x*m+y, on ajoute 1 au vecteur de la matrice, sinon on ajoute 0.

- Sinon pour chaque m et p entre (-N,N) qui vérifient l'équation, on parcourt scores et on augmente le score à la case de 1.

Ceci est la version qu'on a faite pour détecter un droite. Elle nous a servi de tremplin pour écrire la version qui détecte un ensemble de droites. On fait la même chose pour chaque point de la droite.

- ### HOUGH_R_THETA

Cette fonction a été beaucoup plus compliquée pour moi à cause de l'aspect cyclique de  l'équation. On ne savait pas s'il fallait utiliser la longueur PI ou l'angle. L'aspect des points sur l'image indiquait quelque chose de période, oui, mais n'avait pas l'aspect sinusoïdale recherché. 

Cette fonction ne fonctionne toujours pas. 

- ### POINT_SCORE_MAX (fonction hors classe)

Prend en paramètre la matrice des scores obtenue avec la transformée de Hough et retourne le point ayant le score maximal. 

Dans le cas de la détection de plusieurs droites, on renvoie le vecteur des points aux scores maximaux. 

En effet, il ya autant de scores maximaux qu'il y a de droites à détecter.


- ### DROITE_DETECTEE_M_P

Prends en paramètre la matrice des scores, le point (m,p) qui correspond au Point_score_max de la matrice des scores. C'est grâce à celui-ci qu'on trouvera tous les points (x,y) de la droite à détecter et qu'on la tracera.

La surcharge pour la détection de plusieurs droites fait la même chose, pour chque droite (vecteur de points) de l'ensemble des droites à détecter et pour chacun de leur score maximal.

- ### TRACER_DROITE (fonction hors classe)

Crée l'image ppm à partir de la matrice des points (scores ou droite_détectée) donnée , on lui donne un nom et l'ensembles des droites ( vecteurs de Points) à tracer.

## Ces fonctions de détection de droite et de traçage fonctionnent pour les deux méthodes car celles-ci génèrent une matrice des scores qui représente les droites dans l'espace de Hough qu'il soit (m,p) ou (r, $\theta$) et l'outil principal permettant de tracer les droites.

## DIFFICULTÉS RENCONTRÉES

Outre la fonction Hough_r_theta, nous avons eu des petites difficultés pour comprendre comment créer l'image. Après explication, celà s'est fait facilement. Sinon, rien n'a vraiment été difficile, nous n'avons pas eu d'erreurs incompréhensibles non plus. 

Nous espérons avoir assez compris le sujet et avoir fourni un travail convenable. Bien sûr, nous n'avons pas tout fait, comme la suppression des doublons et le choix de la meilleure droite; Je suppose que cette partie avait plus de rapport avec Hough_r_theta, au vu de l'aspect périodique de celle-ci. 

Nous n'avons pas encore perfectionné l'affichage des droites.

## MODE D'UTILISATION

Comme expliqué au début, nous utilisons des points et non des images. Alors pour pouvoir utiliser le code, il vous faudra créer des points. Ces points seront les points des droites à détecter. Ensuite les stocker dans un vecteur qui représentera du coup votre droite, ici "toto". Si il y a plusieurs droites à détecter, créez plusieurs vecteurs avec leurs points et stocker le tout dans un vecteur qui vous servira du coup de "plan" (x,y) avec ses droites, ici "titi".

- Après que vous ayez posé votre base, vous pourrez appeler la fonction:

std::vector<std::vector<$int$>> tab_scores = A.Hough_x_y(toto, N); 

ou

std::vector<std::vector<$int$>> tab_scores = A.Hough_x_y(titi, N); 

N étant un entier positif qui servira à fixer la taille de la matrice des scores. 

ATTENTION, les fonctions de Hough sont des fonctions de la classe, il faut donc les appeler  avec un point, en l'occurence ici, A. Peu importe le point choisi, il n'aura pas d'impacte sur la fonction.Ceci vous sortira la matrice des scores. 

- Il faudra ensuite chercher le(s) point(s) (m,p) correspindant(s) au(x) score(s) maximal(aux) de cette matrice (dans le cas d'un plan de droites). C'est ce point (m,p) qui vous permettra de retracer la(les) droite(s) détectée(s).

Vous appelerez pour ça 

Point inter = Point_score_max(tab_scores);

ou

std::vector<$Point$> inter = Point_score_max(tab_scores, titi);

- Vous pouvez maintenant chercher la matrice de la(des) droite(s) détectée(s).

std::vector<std::vector<$int$>> droite_A_B = A.Droite_detectee_m_p(tab_scores, inter, toto);

ou

std::vector<std::vector<$int$>> droite_A_B = A.Droite_detectee_m_p(tab_scores, inter, titi);


ATTENTION, les fonctions Droite_detectee_m_p sont des fonctions de la classe, il faut donc les appeler  avec un point, en l'occurence ici, A. Peu importe le point choisi, il n'aura pas d'impacte sur la fonction.

- Et vous tracez:

tracer_droite(droite_A_B, "droite_détectée.ppm");

ou

tracer_droite(droite_A_B, "droites_détectées.ppm", titi);

- Pour compiler tout ça, vous utiliserez la commande g++:

g++ -Wall -std=c++11 main.cpp -o main

- et pour executer:

./main


VOILI VOILOU~ ~ 