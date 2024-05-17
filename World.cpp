#include "ray.h"
#include "color.h"
#include "vec3.h"
#include "Sphere.cpp"
#include "Camera.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class World{

    private:
        vector<Sphere> Spheres;
        color background;
    
    public:

        Camera camera;
        World(){}

        World(vector<Sphere> spheres, color background){
            this->Spheres = spheres;
            this->background = background;
        }

        // Getters
        vector<Sphere> getSpheres() const {
            return Spheres;
        }

        Camera getCamera() const {
            return camera;
        }

        color getBackground() const {
            return background;
        }

        // Setters
        void setSpheres(vector<Sphere> newSpheres) {
            Spheres = newSpheres;
        }

        void setCamera(Camera newCamera) {
            camera = newCamera;
        }

        void setBackground(color newBackground) {
            background = newBackground;
        }

        //Other Methods
        void Add(Sphere& newSphere) {
            Spheres.push_back(newSphere);
        }

        color ray_color(const Sphere& sphere,float rad, const ray &r, World& world){
            // This line calls the hit_sphere function with a sphere centered at (0, 0, -1), a radius of 0.5, and a ray r. 
            // The hit_sphere function checks if the ray intersects the sphere and returns true if it does and false otherwise.
            // If the hit_sphere function returns true, it returns a color object representing the color red. 
            // The color class is a custom type that represents a color in RGB format. 
            // The constructor color() initializes a color with the given red, green, and blue c`omponents. 
            // In this case, the color is fully red, as indicated by the arguments (1, 0, 0).
            vec3 spherePosition = sphere.getPosition();
            if (sphere.Hit(spherePosition, rad, r))
                return sphere.getColor(); // red
            else
                return world.getBackground();

            
        }

        void Render(Camera& camera, auto pixel00_loc, auto pixel_delta_u, auto pixel_delta_v, string filename, World& world) {
            ofstream Image;
            Image.open(filename + ".ppm");
            Image << "P3\n" << camera.getWidth() << " " << camera.getHeight() << "\n255\n";

            for (int j = 0; j < camera.getHeight(); ++j) // y coordinates
            {
                std::clog << "\rScanlines remaining: " << (camera.getHeight() - j) << ' ' << std::flush; // number of scanlines remaining
                for (int i = 0; i < camera.getWidth(); ++i) // x coordinates
                {
                    // calculates the location of the center of the current pixel in the viewport. 
                    // It starts from the location of the center of the pixel at the (0,0) position (pixel00_loc), 
                    // and then moves i times the width of a pixel in the u direction and j times the height of a pixel in the v direction.
                    auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);

                    // This line calculates the direction of the ray that will be cast through the current pixel. 
                    // It subtracts the position of the camera from the position of the pixel center, 
                    // resulting in a vector that points from the camera to the pixel center.
                    auto ray_direction = pixel_center - camera.getCenter();
                    
                    // creates a ray object with the camera center as the origin and the calculated direction.
                    ray r(camera.getCenter(), ray_direction);
                    
                    // initialize the closest hit distance to a large value
                    float closest_hit_distance = std::numeric_limits<float>::max();
                    color pixel_color = world.getBackground(); // default background color
                    
                    // iterate over all spheres in the world
                    for (const auto& sphere : world.getSpheres()) {
                        // check if the ray intersects the current sphere
                        if (sphere.Hit(sphere.getPosition(), sphere.getRadius(), r)) {
                            // calculate the hit distance
                            float hit_distance = sphere.getHitDistance(sphere.getPosition(),sphere.getRadius(), r);
                            // check if the current hit distance is closer than the previous closest hit distance
                            if (hit_distance < closest_hit_distance) {
                                closest_hit_distance = hit_distance;
                                // calculate the color of the pixel based on the current sphere
                                pixel_color = ray_color(sphere, sphere.getRadius(), r, world);
                            }
                        }
                    }
                    
                    // writes the color to the output stream in a format suitable for an image file.
                    write_color(Image, pixel_color);
                }
            }
            cout << "\rDone. \n";
            Image.close();
        }
};