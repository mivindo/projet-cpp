# projet-cpp IVINDO ONANGA Mélissa et TOUISS Haitem


## COMPRÉHENSION DU SUJET

Suite à la lecture du sujet, nous avons compris assez vite que le but du projet était de détecter et reproduire une doite à partir de points (pour ma part. Je pense que d'autres l'auront fait à partir d'une image ppm) et après application de la transformée de Hough.

## MISE EN OEUVRE 

### FICHIERS 

Le projet contitent 4 fichiers principaux. Le fichier .hpp dans lequel nous avons défini les types, noms et paramètres de la classe et ses fonctions; le fichier .cpp dans lequel nous avons implémenté les fonctions; le fichier main.cpp dans lequel nous avons nos tests; le README.md qui est celui-ci et qui sert de rapport.

### CLASSE POINT

Alors nous avons créé une classe Point (car nous allons travailler principalement avec des points). Après avoir implémenté les constructeurs, le déstructeur et une surcharge de l'opérateur '==', nous nous sommes mis à l'implémentation des fonctions qui appliqueront les transformées de Hough pour trouver (m,p) avec 'Hough_x_y' et ($r$, $\theta$) avec 'Hough_r_theta'. 

### SURCHARGES

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

Ceci est la version qu'on a faite pour détecter un droite. Elle nous a servi de tremplin pour écrire la version qui détecte un ensemble de droites.

- ### HOUGH_R_THETA

Cette fonction a été beaucoup plus compliquée pour moi à cause de l'aspect cyclique de  l'équation. On ne savait pas s'il fallait utiliser la longueur PI ou l'angle. L'aspect des points sur l'image indiquait quelque chose de période, oui, mais n'avait pas l'aspect sinusoïdale recherché. 

Cette fonction ne fonctionne toujours pas. 

- ### POINT_SCORE_MAX

Prend en paramètre la matrice des scores obtenue avec la transformée de Hough et retourne le point ayant le score maximal.

- ### DROITE_DETECTEE_M_P

Prends en paramètre la matrice des scores, le point 