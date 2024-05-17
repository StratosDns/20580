#include "vec3.h"
#include "ray.h"

class Camera{
    private:
        vec3 center;
        int width;
        int height;

    public:

        Camera(){}

        Camera(vec3 center, int width, int height){
            this->center = center;
            this->width = width;
            this->height = height;
        }

        // Getters 
        int getWidth() const {
            return width;
        }

        int getHeight() const {
            return height;
        }

        vec3 getCenter() const {
            return center;
        }

        // Setters
        void setWidth(int newWidth) {
            width = newWidth;
        }

        void setHeight(int newHeight) {
            height = newHeight;
        }

        void setCenter(vec3 newCenter) {
            center = newCenter;
        }

        //Assignment Function

        vec3 getPixelCenter(int i, int j){
            vec3 pixelCenter = vec3(i,j,0);
            return pixelCenter;
        }

};