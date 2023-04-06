#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>

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

std::vector<std::vector<int>> Point::Hough_x_y(std::vector<Point> tab_x_y, int N)
{
    /*Fonction qui calcule l'ensemble de points (m,p) qui vérifient 
    l'équation p = -xm+y pour chaque point de tab_x_y et renvoie tableau 2D contenant les scores 
    de chaque point selon le nombre de passages par ce point*/

    
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

std::vector<std::vector<int>> Point::Hough_x_y(std::vector<std::vector<Point>> tab_x_y, int N)
{
    /*Fonction qui calcule l'ensemble de points (m,p) qui vérifient 
    l'équation p = -xm+y pour chaque ensemble de points (droite) de tab_x_y 
    et renvoie un tableau 2D contenant les scores de chaque point selon 
    le nombre de passages par ce point*/

    
    std::vector<std::vector<int>> scores;

    for(unsigned int i =0; i!=tab_x_y.size(); ++i)
    {
        for(unsigned int j = 0; j != tab_x_y[i].size(); ++j)
        {
            if(scores.empty()==1)
            {
                
                for(int m = -N; m != N+1; ++m)
                {
                    std::vector<int> v1;

                    for(int p = -N; p != N+1; ++p)
                    {
                        if (p == tab_x_y[i][j].x*m+tab_x_y[i][j].y)
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
                        if (p == tab_x_y[i][j].x*m+tab_x_y[i][j].y)
                        {
                            scores[m+N][p+N] += 1;
                        }
                    }
                }
            }
        }
    }

    return scores;
}

std::vector<std::vector<int>> Point::Droite_detectee_m_p(std::vector<std::vector<int>> scores, Point m_p, std::vector<Point> tab_x_y)
{
    int N = scores.size()/2;

    std::vector<std::vector<int>> droite_detectee;

   
    if(droite_detectee.empty()==1)
    {
        for(int x = -N; x != N+1; ++x)
        {
            std::vector<int> v1;

            for(int y = -N; y != N+1; ++y)
            {
                if (y == -m_p.x*x+m_p.y)
                {
                    v1.push_back(1);
                }
                else
                {
                    v1.push_back(0);
                }
            }
            droite_detectee.push_back(v1);
        }
    }
    for(unsigned int i =0; i != tab_x_y.size(); ++i)
    {
        if(droite_detectee.empty()==0)
        {  
            for(int x = -N; x != N+1; ++x)
            {
                for(int y = -N; y != N+1; ++y)
                {
                    Point p = Point(x,y);
                    if ((p == tab_x_y[i])==1)
                    {   
                        droite_detectee[x+N][y+N] += 1;
                    }
                }
            }
            
        }
    }
    
    return droite_detectee;  
}


std::vector<std::vector<int>> Point::Droite_detectee_m_p(std::vector<std::vector<int>> scores, std::vector<Point>  scores_max, std::vector<std::vector<Point>> tab_x_y)
{
    int N = scores.size()/2;

    std::vector<std::vector<int>> droite_detectee;

    for(unsigned int k = 0; k != tab_x_y.size(); ++k)
    {
        if(droite_detectee.empty()==1)
        {
            for(int x = -N; x != N+1; ++x)
            {
                std::vector<int> v1;

                for(int y = -N; y != N+1; ++y)
                {
                    if (y == -scores_max[k].x*x+scores_max[k].y)
                    {
                        v1.push_back(1);
                    }
                    else
                    {
                        v1.push_back(0);
                    }
                    
                }
                droite_detectee.push_back(v1);
            }
        }

        else
        {  
            for(int x = -N; x != N+1; ++x)
            {
                for(int y = -N; y != N+1; ++y)
                {
                    if (y == -scores_max[k].x*x+scores_max[k].y)
                    {
                        droite_detectee[x+N][y+N] += 1;
                    }
                }
            }
            
        }
        
        if(droite_detectee.empty()==0)
        {  
            for(int x = -N; x != N+1; ++x)
            {
                for(int y = -N; y != N+1; ++y)
                {
                    for(unsigned int j = 0; j != tab_x_y[k].size(); ++j)
                    {
                        Point p = Point(x,y);
                        if ((p == tab_x_y[k][j])==1)
                        {   
                            droite_detectee[x+N][y+N] += 1;
                        }
                    }
                }
            }
            
        }
        
    }
    
    return droite_detectee;  
}

std::vector<std::vector<int>> Point::Hough_r_theta(std::vector<Point> tab_x_y, int N)
{
    /*Fonction qui calcule l'ensemble de points (m,p) qui vérifient 
    l'équation p = -xm+y pour chaque point de tab_x_y et renvoie tableau 2D contenant les scores 
    de chaque point selon le nombre de passages par ce point*/

    int R = 2*N+1;
    double pas_theta = M_PI/6;

    std::vector<int> r;
    std::vector<int> thet;
    
    std::vector<std::vector<int>> scores;

    for(unsigned int i =0; i!=tab_x_y.size(); ++i)
    {
        if(scores.empty()==1)
        {
            double theta = 0;
            while(theta < M_PI)
            {   
                r.push_back(int(100.*(tab_x_y[i].x*cos(theta)+tab_x_y[i].y*sin(theta))));
                thet.push_back(theta);
                theta +=pas_theta;
                std::cout<<"r="<<int(100.*(tab_x_y[i].x*cos(theta)+tab_x_y[i].y*sin(theta)))<<"theta="<<theta<<std::endl;
            }

            int min_r = *min_element(r.begin(), r.end());
            int max_r = *max_element(r.begin(), r.end());

            std::cout<<min_r<<std::endl;
            std::cout<<max_r<<std::endl;

            for(unsigned int rr =0; rr!= r.size(); ++rr)
            {
                std::vector<int> v1;
                 
                for(unsigned int theta = 0; theta != thet.size(); ++theta)
                {                   
                        
                        if(r[rr] == r[theta])  
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

            std::cout<<"scores de A faits"<<std::endl;

        }
        // else
        // {
        //     for(int i =0; i != scores.size(); ++i)
        //     {
        //         for(int j =0; j!= scores[0].size(); ++j)
        //         {
                    
        //         }
        //     }
        // }
    }

    return scores;
}

Point::~Point(){}


/*************Fonctions hors classe***************/

Point Point_score_max(std::vector<std::vector<int>> scores)
{
    auto result = max_element(scores.begin(), scores.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return *max_element(a.begin(), a.end()) < *max_element(b.begin(), b.end());
        });

    int row = distance(scores.begin(), result);
    int col = distance(result->begin(), max_element(result->begin(), result->end()));

    int N = scores.size()/2;

    Point m_p = Point(row-N, col-N);

    return m_p;
}


std::vector<Point> Point_score_max(std::vector<std::vector<int>> scores, std::vector<std::vector<Point>> tab_x_y)
{
    std::vector<Point> scores_max;

    for(unsigned int i = 0; i != tab_x_y.size(); ++i)
    {
        auto result = max_element(scores.begin(), scores.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return *max_element(a.begin(), a.end()) < *max_element(b.begin(), b.end());
        });

        int row = distance(scores.begin(), result);
        int col = distance(result->begin(), max_element(result->begin(), result->end()));

        if(scores[row][col] == tab_x_y[i].size())
        {
            int N = scores.size()/2;

            scores_max.push_back(Point(row-N, col-N));

            scores[row][col] = 0;
        }

    }

    return scores_max;
}

void tracer_droite(std::vector<std::vector<int>> scores, const char* filename, std::vector<Point> tab_x_y)
{
    /*Elle crée l'image ppm à partir de la matrice des scores*/

    const int lignes = scores[0].size();
    const int colonnes = scores.size();

    std::ofstream file(filename, std::ios::out | std::ios::binary);
    file<<"P3"<<std::endl;
    file<<"#dimensions de l'image"<<std::endl;
    file<< lignes<< " " << colonnes<<std::endl;
    file<<"#valeur max"<<std::endl;
    file<< 250<<std::endl;
    file<<"#valeur max"<<std::endl;

    for(int i = 0; i != colonnes; ++i)
    {
        for(int j =0; j != lignes; ++j)
        {
            if(scores[i][j] == 0)
            {
                file<< 250<<std::endl;
                file<< 250<<std::endl;
                file<< 250<<std::endl;
            }
            else if(scores[i][j] == tab_x_y.size())
            {
                file<< 250<<std::endl;
                file<< 0<<std::endl;
                file<< 0<<std::endl;
            }
            else
            {
                file<< 0<<std::endl;
                file<< 0<<std::endl;
                file<< 0<<std::endl;
            }
        }
    }

    file.close();

}

void tracer_droite(std::vector<std::vector<int>> scores, const char* filename, std::vector<std::vector<Point>> tab_x_y)
{
    /*Elle crée l'image ppm à partir de la matrice des scores*/

    const int lignes = scores[0].size();
    const int colonnes = scores.size();

    std::ofstream file(filename, std::ios::out | std::ios::binary);
    file<<"P3"<<std::endl;
    file<<"#dimensions de l'image"<<std::endl;
    file<< lignes<< " " << colonnes<<std::endl;
    file<<"#valeur max"<<std::endl;
    file<< 250<<std::endl;
    file<<"#valeur max"<<std::endl;

    for(unsigned int k = 0; k != tab_x_y.size(); ++k)
    {
        for(int i = 0; i != colonnes; ++i)
        {
            for(int j =0; j != lignes; ++j)
            {
                if(scores[i][j] == 0)
                {
                    file<< 250<<std::endl;
                    file<< 250<<std::endl;
                    file<< 250<<std::endl;
                }
                else if(scores[i][j] == tab_x_y[k].size())
                {
                    file<< 250<<std::endl;
                    file<< 0<<std::endl;
                    file<< 0<<std::endl;
                }
                else
                {
                    file<< 0<<std::endl;
                    file<< 0<<std::endl;
                    file<< 0<<std::endl;
                }
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
