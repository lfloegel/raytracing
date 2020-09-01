#include "color.h" 
#include "ray.h" 
#include "vec3.h"  

#include <iostream> 
//build/raytracingOneWeekend > image.ppm 

//linear blends, or interpolation, colors depending on height of y 
color ray_color(const ray& r) { //const & forusing a simple alias, passing in objects 
    vec3 unit_direction = unit_vector(r.direction()); //scale ray direction to unit length 
                                                      //-1.0 < y < 1.0 
    auto t = 0.5*(unit_direction.y() + 1.0); 
    //lerp: blendedValue = (1 - t) * startValue + t * endValue 
    //startValue = white 
    //endValue = blue 
    //t going from 0 to 1 
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0); 
} 

int main() 
{
    //image 
    const auto aspect_ratio = 16.0 / 9.0;
    const int img_width = 400;
    const int img_height = static_cast<int>(img_width / aspect_ratio);

    // camera 

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    //render 

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n"; 

    //iterate through all pixels displaying a new color from top to bottom 
    for (int i = img_height - 1; i >= 0; --i)  //--i or i-- performs the same in a for loop 
    { 
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;  
        for (int l = 0; l < img_width; ++l) 
        { 
            auto u = double(l) / (img_width-1);
            auto v = double(i) / (img_height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            //color pixel_color(double(l)/(img_width - 1), double(i)/(img_height - 1), 0.25); //vec3 
            write_color(std::cout, pixel_color); 

            /*
            //normalize colors from 0 to 1 
            auto r = double(l) / (img_width - 1); //red begins from left to right 
            auto g = double(i) / (img_height - 1); //green begins from top to bottom 
            auto b = 0.98; //limits blue to bottom left corner, influence lessens as red and green grow 

            int ir = static_cast<int>(255.999 * r); //static_cast converts between types, casting to int  
            int ig = static_cast<int>(255.999 * g); //converting back to color value 
            int ib = static_cast<int>(255.999 * b);  

            std::cout << ir << ' ' << ig << ' ' << ib << '\n'; 
            */ 
        }

    } 

    std::cerr << "\nDone.\n"; 

}