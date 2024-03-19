#include <iostream>

using namespace std;

class Animal{
    private:
        int age;
        string name;
    
    public:

        Animal() {}

        Animal(int x, string y){
            this->age = x;
            this->name = y;

        }

        Animal(int x){
            this->age = x;

        }

        Animal(string y){
            this->name = y;

        }


        // Getters
        int getAge() const {
            return age;
        }

        string getName() const {
            return name;
        }

        // Setters
        void setAge(int newAge) {
            age = newAge;
        }

        void setName(string newName) {
            name = newName;
        }
};

class Dog : public Animal {
    private:
        string breed;
    
    public:
        Dog(int age, string name, string breed) : Animal(age, name) {
            this->breed = breed;
        }

        string getBreed() const {
            return breed;
        }

        void setBreed(string newBreed) {
            breed = newBreed;
        }
};

int main() {
    // Your code goes here

    Animal animal1(3, "Leo"); // Instantiate an object of the Animal class

    Animal animal2;

    Animal animal3(4);

    Dog dog1(3, "Leo", "Pitbull");

    int age = animal1.getAge();
    int age2 = animal3.getAge();

    //cout << "The age of the animal is: " << age << endl;

    int* ptr = &age;

    cout << age << endl; //3

    cout << &age << endl; //0x7ffebc3e3a3c

    age = 6;

    cout << age << endl; //6

    cout << &age << endl; //0x7ffebc3e3a3c

    cout << ptr << endl;

    cout << *ptr << endl;

    cout << &ptr << endl;

    
    return 0;
}