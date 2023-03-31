#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "fichier.hpp"

typedef struct {int red; int green; int blue;} pixel;
//on définira dans ce fichier les définitions des fonctions

Point::Point()
{
    /*Constructeur par défaut*/
    x = 0.0;
    y = 0.0;
}
Point::Point(const double abs, const double ord)
{
    /*Constructeur par paramètre*/
    x = abs;
    y = ord;
}

Point::Point(const Point & p)
{
    /*Constructeur par copie*/
    x = p.x; y = p.y;
}

bool Point::operator==(Point p)
{
    return ((x == p.x) && (y == p.y));
}

std::vector<std::vector<int>> Point::Hough_x_y(std::vector<Point> tab_x_y)
{
    /*Fonction qui calcule l'ensemble de points (m,p) qui vérifient 
    l'équation p = -xm+y pour chaque point de tab_x_y et renvoie tableau 2D contenant les scores 
    de chaque point selon le nombre de passages par ce point*/

    int N = 15;
    
    std::vector<std::vector<int>> scores;

    for(unsigned int i =0; i!=tab_x_y.size(); ++i)
    {
        if(scores.empty()==1)
        {
            
            for(int m = -N; m != N+1; ++m)
            {
                std::vector<int> v1;

                for(int p = -N; p != N+1; ++p)
                {
                    if (p == tab_x_y[i].x*m+tab_x_y[i].y)
                    {
                        v1.push_back(1);
                    }
                    else
                    {
                        v1.push_back(0);
                    }
                }
                scores.push_back(v1);
            }
        }
        else
        {
            for(int m = -N; m != N+1; ++m)
            {
                for(int p = -N; p != N+1; ++p)
                {
                    if (p == tab_x_y[i].x*m+tab_x_y[i].y)
                    {
                        scores[m+N][p+N] += 1;
                    }
                }
            }
       }
    }

    return scores;
}


std::vector<std::vector<int>> Point::Hough_r_theta(std::vector<Point> tab_x_y)
{/*Fonction qui calcule l'ensemble de points (m,p) qui vérifient 
    l'équation p = -xm+y pour chaque point de tab_x_y et renvoie tableau 2D contenant les scores 
    de chaque point selon le nombre de passages par ce point*/

    int R = 3;
    double pas = 1e-2;
    double pas_theta = M_PI/6;
    
    std::vector<std::vector<int>> scores;

    for(unsigned int i =0; i!=tab_x_y.size(); ++i)
    {
        if(scores.empty()==1)
        {
            double r = -R;
            while(r < R)
            {
                std::vector<int> v1;

                std::cout<<"r="<<r<<std::endl;

                double theta = 0;

                while(theta < M_PI)
                {
                    std::cout<<"theta="<<theta<<std::endl;

                    if (r == tab_x_y[i].x*cos(theta)+tab_x_y[i].y*sin(theta))
                    {
                        v1.push_back(1);
                    }
                    else
                    {
                        v1.push_back(0);
                    }

                    theta += pas_theta;
                }
                scores.push_back(v1);

                r += pas;
            }

            std::cout<<"scores de A faits"<<std::endl;
        }
        // else
        // {
        //     for(int i =0; i != scores.size(); ++i)
        //     {
        //         for(int j =0; j!= scores[0].size(); ++j)
        //         {
        //             double r = 0;
        //             while(r < R)
        //             {
        //                 double theta = 0;
        //                 while(theta < 2*M_PI)
        //                 {
        //                     if (r == tab_x_y[i].x*cos(theta)+tab_x_y[i].y*sin(theta))
        //                     {
        //                         scores[i][j] += 1;
        //                     }

        //                     theta += pas_theta;
        //                 }

        //                 r += pas;
        //             }
        //         }
        //     }
        // }
    }

    return scores;
}

Point::~Point(){}


/*************Fonctions hors classe***************/

void tracer_droite(std::vector<std::vector<int>> scores, const char* filename)
{
    /*Pour le moment elle lit une image ppm*/

    const int lignes = scores[0].size();
    const int colonnes = scores.size();

    std::ofstream file(filename, std::ios::out | std::ios::binary);
    file<<"P3"<<std::endl;
    file<<"#dimensions de l'image"<<std::endl;
    file<< lignes<< " " << colonnes<<std::endl;
    file<<"#valeur max"<<std::endl;
    file<< 250<<std::endl;
    file<<"#valeur max"<<std::endl;

    for(int i = 0; i != lignes; ++i)
    {
        for(int j =0; j != colonnes; ++j)
        {
            if(scores[i][j] == 0)
            {
                file<< 250<<std::endl;
                file<< 250<<std::endl;
                file<< 250<<std::endl;
            }
            else if(scores[i][j] == 1)
            {
                file<< 0<<std::endl;
                file<< 0<<std::endl;
                file<< 0<<std::endl;
            }
            else
            {
                file<< 250<<std::endl;
                file<< 0<<std::endl;
                file<< 0<<std::endl;
            }
        }
    }

    file.close();

}

/***********Fonction d'affichage************/

std::ostream & operator <<(std::ostream & out, const Point & p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

void affiche(std::vector<Point> vect)  //fonction pour afficher un vecteur de points
{
    std::cout<<"vect=";
    for(Point elem : vect)
    {
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
}

void affiche(std::vector<int> vect)  //surcharge de affiche pour vecteurs d'entiers
{
    std::cout<<"vect=";
    for(int elem : vect)
    {
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
}

void affiche(std::vector<std::vector<Point>> vect)  //fonction pour afficher un vecteur de points
{
    std::cout<<"vect=";
    for (unsigned int i = 0; i != vect.size(); ++i) 
    {
        for (unsigned int j = 0; j != vect[i].size(); ++j)
        {
            std::cout << vect[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void affiche(std::vector<std::vector<int>> vect)  //fonction pour afficher un vecteur de vecteurs d'entiers
{
    std::cout<<"vect="<<std::endl;
    for (unsigned int i = 0; i != vect.size(); ++i) 
    {
        for (unsigned int j = 0; j != vect[i].size(); ++j)
        {
            std::cout << vect[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
