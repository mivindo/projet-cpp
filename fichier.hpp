#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


//on définira dans ce fichier les corps des fonctions


class Point
{
    double x;
    double y;

 public:
    Point();
    Point(const double abs, const double ord);
    Point(const Point & p);
    
    bool operator==(Point p);

    std::vector<std::vector<int>> Hough_x_y(std::vector<Point> tab_x_y, int N);
    std::vector<std::vector<int>> Hough_x_y(std::vector<std::vector<Point>> tab_x_y, int N);    //surcharge pour un vecteur de vecteurs de points

    std::vector<std::vector<int>> Droite_detectee_m_p(std::vector<std::vector<int>> scores, Point m_p, std::vector<Point> tab_x_y);
    std::vector<std::vector<int>> Droite_detectee_m_p(std::vector<std::vector<int>> scores, std::vector<Point> scores_max, std::vector<std::vector<Point>> tab_x_y);  //surcharge pour vecteur de vecteurs de points 
    

    std::vector<std::vector<int>> Hough_r_theta(std::vector<Point> tab_x_y, int N);

    
    
    
    friend std::ostream & operator <<(std::ostream & out, const Point & p);  

    ~Point();
};

Point Point_score_max(std::vector<std::vector<int>> scores);
std::vector<Point> Point_score_max_(std::vector<std::vector<int>> scores, std::vector<std::vector<Point>> tab_x_y);  //surcharge pour plusieurs droites

void tracer_droite(std::vector<std::vector<int>> scores, const char* filename, std::vector<Point> tab_x_y);
void tracer_droite(std::vector<std::vector<int>> scores, const char* filename, std::vector<std::vector<Point>> tab_x_y);  //surcharge pour plusieurs droites


void affiche(std::vector<Point> vect);
void affiche(std::vector<int> vect);
void affiche(std::vector<std::vector<int>> vect);

#endif