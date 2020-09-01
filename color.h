#ifndef COLOR_H 
#define COLOR_H 

#include "vec3.h" 

#include <iostream> 

//writes single pixel's color to standard output stream 
void write_color(std::ostream &out, color pixel_color) 
{
    //write translated [0, 255] of each color component 
    out << static_cast<int>(255.999 * pixel_color.x()) << ' ' 
        << static_cast<int>(255.999 * pixel_color.y()) << ' ' 
        << static_cast<int>(255.999 * pixel_color.z()) << '\n'; 
        
} 

#endif 