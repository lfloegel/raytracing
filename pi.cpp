#include "rtweekend.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

int main() {
    int inside_circle = 0;
    int inside_circle_stratified = 0;
    int sqrt_N = 10000;
    for (int i = 0; i < sqrt_N; i++) { //two for loops as 10000x10000 grid 
        for (int j = 0; j < sqrt_N; j++) {
            auto x = random_double(-1,1); //normal 
            auto y = random_double(-1,1);
            if (x*x + y*y < 1) //length of line from orign to point 
                               //if less than raidus, then inside circle 
                inside_circle++;
            x = 2*((i + random_double()) / sqrt_N) - 1; //stratified 
            y = 2*((j + random_double()) / sqrt_N) - 1;
            if (x*x + y*y < 1)
                inside_circle_stratified++;
        }
    }

    auto N = static_cast<double>(sqrt_N) * sqrt_N;
    std::cout << std::fixed << std::setprecision(12);
    std::cout
        << "Regular    Estimate of Pi = "
        << 4*double(inside_circle) / (sqrt_N*sqrt_N) << '\n' //probability of point being inside circle 
                                                             //4*sum / N 
        << "Stratified Estimate of Pi = "
        << 4*double(inside_circle_stratified) / (sqrt_N*sqrt_N) << '\n';
}
    /*
    int N = 1000; //samples 
    int inside_circle = 0;
    int runs = 0;
    std::cout << std::fixed << std::setprecision(12);
    //for (int i = 0; i < N; i++) {
    while(true) { 
        runs++; 
        auto x = random_double(-1,1);
        auto y = random_double(-1,1);
        if (x*x + y*y < 1) //if less than radius inside origin, x*x + y*y >= 0 
                           //center at origin (0,0) and r = 1 
                           //equation of a circle: (x - h)^2 + (y - k)^2 = r^2 
                           //buffon needle case study 
            inside_circle++;

        if (runs % 100000 == 0)
            std::cout << "Estimate of Pi = "
                      << 4*double(inside_circle) / runs
                      << '\n';
    }
    //std::cout << std::fixed << std::setprecision(12);
    //std::cout << "Estimate of Pi = " << 4*double(inside_circle) / N << '\n';
    */