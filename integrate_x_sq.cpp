#include "rtweekend.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

inline double pdf(double x) { //pdf: 3/8 * x^2 
    return 3*x*x/8;
}

/*
inline double pdf(double x) { //pdf: 1 / 2
    return 0.5;
}
*/

/*
inline double pdf(double x) { //pdf: x / 2
    return 0.5*x;
}
*/

int main() {
    int N = 1;
    //int N = 1000000;
    auto sum = 0.0;
    for (int i = 0; i < N; i++) { //integral: 2 * avg(x^2, 0, 2) 
        auto x = pow(random_double(0,8), 1./3.); //inverse cdf 
        //auto x = random_double(0,2);
        //auto x = sqrt(random_double(0,4)); //0 < x < 4 as squared bounds 
                                          //compute new bounds for cdf 
        sum += x*x / pdf(x); //proportional to 1 / pdf 
    }
    std::cout << std::fixed << std::setprecision(12);
    std::cout << "I = " << 2 * sum/N << '\n';
}