#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr; //tells cmpiler gettingthese from std, do not need to prefex them with std in rest of code 
using std::make_shared;

//class stores a list of hittables 
//i.e. a list of spheres 
class hittable_list : public hittable {
    public:
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); } //have pointer in list point sahre ownership 

        void clear() { objects.clear(); }
        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        virtual bool hit(
            const ray& r, double tmin, double tmax, hit_record& rec) const override;

    public:
        std::vector<shared_ptr<hittable>> objects; //vector to store hittable objects 
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) { //finds closest hit t vlaue iterating over all objects in list 
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif 