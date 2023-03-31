#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <opencv2/opencv.hpp>


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

    std::vector<std::vector<int>> Hough_x_y(std::vector<Point> tab_x_y);
    std::vector<std::vector<int>> Hough_r_theta(std::vector<Point> tab_x_y);
    
    
    friend std::ostream & operator <<(std::ostream & out, const Point & p);

    ~Point();
};

void tracer_droite(std::vector<std::vector<int>> scores, const char* filename);




#endif