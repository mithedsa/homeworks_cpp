#include <iostream> // cout, cin
#include <cmath> // sqrt, pow

int main(){
    int count;
    int step;


    std::cout << "input count of number ";
    std::cin >> count;
    int mas[count];
    std::cout << "input numbers\n";

    for(int i=0; i<count; ++i){
        std::cin >> mas[i];
    }

    int sum = 0;

    for (int i=0; i <count; i++){
        sum += mas[i];
    }
    double sr_znach = sum/count;
    std::cout << sr_znach;

    std::cout << "\ninput step\n";
    std::cin >> step;

    int c = 0;
    int new_sum = 0;
    for (int i=0; i < count; i += step){
        c++;
        new_sum += mas[i];
    }

    double new_sr_znach = new_sum/c;
    std::cout << new_sr_znach;

    return 0;
}