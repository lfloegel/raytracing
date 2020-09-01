#ifndef RAY_H
#define RAY_H

#include "vec3.h" 

/* 
ray function: P(t) = A + tb 
P: 3d position along line in 3d 
A: ray origin 
b: ray direction 
P(t) moves point along ray based on t value 

ray tracer: sends rays through pixels 
path tracing: tracing individual rays from camera, tracking rays' interactions, 
cating shadows, reflections, and oath back to light sourse 

limits calculation based on what camera sees 
ray sorting: grouping together similar directional ray to allow faster rendering 

steps: 
a. calculate ray from eye to pixel 
b. determine object ray intersects 
c. compute color at intersection point 
*/ 

class ray {
    public:
        ray() {}
        ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {}

        point3 origin() const  { return orig; }
        vec3 direction() const { return dir; }

        point3 at(double t) const { //ray function 
            return orig + t*dir;
        }

    public:
        point3 orig;
        vec3 dir;
};

#endif