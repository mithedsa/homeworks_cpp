#include <iostream>
#include <string>
class Animal {
public:
    virtual void saySmth() = 0;
//    {
//        std::cout << "I am an animal" << std::endl;
//    }
};

class Dog : public Animal {
public:
    Dog() {
        name_ = "Bobik";
    }

    void saySmth () override {
        std::cout << "I'm a Dog! My name is " << name_ << std::endl;
    }
private:
    std::string name_;

};

void print_info(Animal& animal){
    animal.saySmth();
}


int main(int argc, char **argv) {
    std::cout << "Hello, stranger!" << std::endl;
//    Animal animal;
    Dog dog;

//    print_info(animal);
    print_info(dog);

//    animal.saySmth();
    dog.saySmth();
    return 0;
}