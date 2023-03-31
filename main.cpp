#include "fichier.cpp"

int main()
{
    Point A(1,2);
    Point B(3,4);

    std::vector<Point> toto = {A,B};


    // std::vector<std::vector<int>> tab_scores = A.Hough_x_y(toto);
    
    // affiche(tab_scores);

    //tracer_droite(tab_scores, "test1.ppm");

    std::vector<std::vector<int>> tab_scores = A.Hough_r_theta(toto);

    affiche(tab_scores);
    
    
    

    // affiche(scores[0]);

    return 0;
}