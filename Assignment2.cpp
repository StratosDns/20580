/**
 * @file Assignment2.cpp
 *  
 * @brief Assignment 2 - HY-150
 * 
 * @author: csd5598
 */

#include <iostream>
#include <fstream>

#include "vec3.h"

#include "ray.h"

using namespace std;


class Sphere{

    private:
        vec3 position;
        vec3 color ;
        float radius;
    
    public:

        Sphere(){}

        Sphere(vec3 position, vec3 color, float radius){
            this->position = position;
            this->color = color;
            this->radius = radius;
        }


        // Getters
        vec3 getPosition() const {
            return position;
        }

        vec3 getColor() const {
            return color;
        }

        double getRadius() const {
            return radius;
        }

        // Setters
        void setPosition(vec3 newPosition) {
            position = newPosition;
        }

        void setColor(vec3 newColor) {
            color = newColor;
        }

        void setRadius(double newRadius) {
            radius = newRadius;
        }
        
        bool hit_sphere(const point3 &center, double radius, const ray &r){
            // calculates the vector from the sphere's center to the origin of the ray. 
            // This is done by subtracting the center of the sphere from the origin of the ray.
            vec3 oc = r.origin() - center;
            
            // This line calculates the dot product of the ray's direction with itself. 
            // This is equivalent to the square of the length of the direction vector, 
            // which is always 1 for a normalized direction vector.
            auto a = dot(r.direction(), r.direction());
            
            // This line calculates twice the dot product of the vector oc and the ray's direction. 
            // This is part of the quadratic equation used to find the intersection points of the ray and the sphere.
            auto b = 2.0 * dot(oc, r.direction());
            
            // This line calculates the dot product of the vector oc with itself, which is the square of the length of oc, 
            // and subtracts the square of the sphere's radius. This is also part of the quadratic equation.
            auto c = dot(oc, oc) - radius * radius;
            
            // This line calculates the discriminant of the quadratic equation. 
            // The discriminant is used to determine the number of solutions to the equation.
            auto discriminant = b * b - 4 * a * c;
            
            // This line returns a boolean value indicating whether the discriminant is greater than or equal to zero. 
            // If the discriminant is negative, the quadratic equation has no real solutions, 
            // which means the ray does not intersect the sphere. 
            // If the discriminant is zero or positive, the equation has one or two real solutions, 
            // which means the ray intersects the sphere at one or two points.
            return (discriminant >= 0);
        }
};





int main()
{

    Sphere s1(vec3(1,2,3) , vec3(1,0,0) , 2.0);

    ray r1(vec3(1,2,3) , vec3(1,0,0));

    bool hit = s1.hit_sphere(s1.getPosition(), s1.getRadius(), r1);

    if(hit){
        cout << "The ray intersects with the sphere" << endl;

    
    }
}