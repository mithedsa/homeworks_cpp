#include <iostream> // cout, cin
#include <cmath> // abs
#include <string>

int chance(int age){
    int new_ball = abs(age - 100);
    return new_ball;
}

int main() {
    std::string name;
    std::string surname;

    int age;
    double points;

    std::cout << "Sername Name age point\n";
    std::cin >> surname >> name >> age >> points;
    double ball = chance(points);
    std::printf("Chance %d points from %s %s is %f %", points, name.data(), surname.data(), ball);

    return 0;
}
