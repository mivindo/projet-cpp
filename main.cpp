#include "fichier.cpp"

int main()
{
    Point A(1,2);
    Point B(3,4);

    std::vector<Point> toto = {A,B};

    /************** TRANSFORMATION DE HOUGH (m,p) ---> (x,y) ***************/

    // std::vector<std::vector<int>> tab_scores = A.Hough_x_y(toto);

    // Point inter = A.Point_score_max(tab_scores);

    // std::cout<<inter<<std::endl;

    // std::vector<std::vector<int>> droite_A_B = A.Droite_detectee_m_p(tab_scores, inter, toto);

    // tracer_droite(droite_A_B, "droite_détectée.ppm");

    // affiche(tab_scores);

    // affiche(droite_A_B);

    // tracer_droite(tab_scores, "test1.ppm");



    /************** TRANSFORMATION DE HOUGH (r,theta) ---> (x,y) ***************/

    std::vector<std::vector<int>> tab_scores = A.Hough_r_theta(toto);

    std::cout<< tab_scores.size()<<std::endl;
    std::cout<< tab_scores[0].size()<<std::endl;

    affiche(tab_scores);

    tracer_droite(tab_scores, "test2.ppm");


    
    
    

    // affiche(scores[0]);

    return 0;
}