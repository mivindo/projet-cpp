#include "fichier.cpp"

int main()
{
    Point A(1,2);
    Point B(3,4);
    Point C(-2,-1);
    Point D(-4,-3);

    Point E(0,0);
    Point F(1,1);
    Point G(-6,-6);

    std::vector<Point> toto = {A,B,C,D};
    std::vector<Point> tata = {E,F,G};

    std::vector<std::vector<Point>> titi = {toto, tata};

    int N = 15;

    /************** TRANSFORMATION DE HOUGH (m,p) ---> (x,y) ***************/


    /************** DÉTECTION SUR UNE DROITE ***************/

    // std::vector<std::vector<int>> tab_scores = A.Hough_x_y(toto,N);

    // Point inter = Point_score_max(tab_scores);

    // std::cout<<inter<<std::endl;

    // std::vector<std::vector<int>> droite_A_B = A.Droite_detectee_m_p(tab_scores, inter, toto);

    // tracer_droite(droite_A_B, "droite_détectée.ppm");

    // affiche(tab_scores);

    // affiche(droite_A_B);

    // tracer_droite(tab_scores, "test1.ppm");


    /************** DÉTECTION SUR UN ENSEMBLE DE DROITES ***************/

    // std::vector<std::vector<int>> tab_scores = A.Hough_x_y(titi,N);

    // std::vector<Point> inter = Point_score_max(tab_scores, titi);

    // affiche(inter);

    // std::vector<std::vector<int>> droite_A_B = A.Droite_detectee_m_p(tab_scores, inter, titi);

    // tracer_droite(droite_A_B, "droite_détectée.ppm", titi);

    // affiche(tab_scores);

    // affiche(droite_A_B);

    // tracer_droite(tab_scores, "test_n_droites.ppm", titi);



    /************** TRANSFORMATION DE HOUGH (r,theta) ---> (x,y) ***************/
    

    // std::vector<std::vector<int>> tab_scores = A.Hough_r_theta(toto, N);

    // std::cout<< tab_scores.size()<<std::endl;
    // std::cout<< tab_scores[0].size()<<std::endl;

    // affiche(tab_scores);

    // tracer_droite(tab_scores, "test2.ppm");


    return 0;
}