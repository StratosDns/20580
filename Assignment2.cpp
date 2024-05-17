#include <iostream>
#include <fstream>
#include <vector>
#include "vec3.h"
#include "ray.h"
#include "color.h"
#include "World.cpp"

using namespace std;

int main()
{
    ifstream inputFile("world.txt");
    if (!inputFile)
    {
        cerr << "Failed to open world.txt" << endl;
        return 1;
    }

    string filename;
    getline(inputFile, filename);

    double cameraCenterX, cameraCenterY, cameraCenterZ;
    inputFile >> cameraCenterX >> cameraCenterY >> cameraCenterZ;
    vec3 cameraCenter(cameraCenterX, cameraCenterY, cameraCenterZ);

    int imageWidth, imageHeight;
    inputFile >> imageWidth >> imageHeight;

    double skyColorR, skyColorG, skyColorB;
    inputFile >> skyColorR >> skyColorG >> skyColorB;
    color skyColor(skyColorR, skyColorG, skyColorB);

    int numSpheres;
    inputFile >> numSpheres;

    vector<Sphere> spheres;
    for (int i = 0; i < numSpheres; i++)
    {
        double sphereColorR, sphereColorG, sphereColorB;
        inputFile >> sphereColorR >> sphereColorG >> sphereColorB;
        color sphereColor(sphereColorR, sphereColorG, sphereColorB);

        double spherePositionX, spherePositionY, spherePositionZ;
        inputFile >> spherePositionX >> spherePositionY >> spherePositionZ;
        vec3 spherePosition(spherePositionX, spherePositionY, spherePositionZ);

        double sphereRadius;
        inputFile >> sphereRadius;

        spheres.push_back(Sphere(spherePosition, sphereColor, sphereRadius));
    }

    inputFile.close();

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(imageWidth) / imageHeight);

    Camera camera(cameraCenter, imageWidth, imageHeight);

    World world(spheres, skyColor);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / imageWidth;
    auto pixel_delta_v = viewport_v / imageHeight;
    
    // Calculate the position of the upper left corner of a viewport
    // and the location of the center of the pixel at the (0,0) position in a 3D space.
    // It starts from the camera_center, moves backwards along the z-axis by
    // focal_length units (since vec3(0, 0, focal_length) represents a vector pointing along the z-axis),
    // and then moves half the viewport's width and height in the negative u and v directions.
    // The result is stored in the viewport_upper_left variable.
    auto viewport_upper_left = camera.getCenter() - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;

    // This line calculates the location of the center of the pixel at the (0,0) position.
    //  It starts from the viewport_upper_left position, and then moves half the width and
    //  height of a pixel in the positive u and v directions. The result is stored in the pixel00_loc variable.
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    world.Render(camera, pixel00_loc, pixel_delta_u, pixel_delta_v, filename, world);

    string openCommand = "start " + filename + ".ppm";
    system(openCommand.c_str());

    return 0;
}