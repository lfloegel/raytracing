#ifndef RAY_H
#define RAY_H

#include "vec3.h" 

class ray {
    public:
        ray() {}
        ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {} 
        //translates to: 
        //orig = origin 
        //dir = direction 

        point3 origin() const  { return orig; } //const: function not allowed to change state of value invoked on 
        vec3 direction() const { return dir; }

        point3 at(double t) const { //ray function 
            return orig + t*dir;
        }

    public:
        point3 orig;
        vec3 dir;
};

#endif