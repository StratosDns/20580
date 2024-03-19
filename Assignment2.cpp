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


class Sphere{
    private:
        vec3 position;
        vec3 color ;
        double radius;
    
    public:
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
        void setPosition(const vec3& newPosition) {
            position = newPosition;
        }

        void setColor(const vec3& newColor) {
            color = newColor;
        }

        void setRadius(double newRadius) {
            radius = newRadius;
        }
        
};



int main()
{
}