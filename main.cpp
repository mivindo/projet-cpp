#include "fichier.cpp"

int main()
{
    Point A(1,1);
    Point B(3,1);

    std::vector<Point> toto = {A,B};


    // std::vector<std::vector<int>> tab_scores = A.Hough_x_y(toto);
    
    // affiche(tab_scores);

    //tracer_droite(tab_scores, "test1.ppm");

    std::vector<std::vector<int>> tab_scores = A.Hough_r_theta(toto);

    std::cout<< tab_scores.size()<<std::endl;
    std::cout<< tab_scores[0].size()<<std::endl;

    //affiche(tab_scores);

    tracer_droite(tab_scores, "test2.ppm");


    
    
    

    // affiche(scores[0]);

    return 0;
}