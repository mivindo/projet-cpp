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

### FONCTION HOUGH_X_Y

Celle-ci était relativement facile à implémenter. Elle prend en paramètre le vecteur de points dont on veut détecter la droite. 