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
        
        bool Hit(const ray&, double&){
            return true;
        }
};



int main()
{

    Sphere s1(vec3(1,2,3) , vec3(1,0,0) , 6.0);

    

    
}