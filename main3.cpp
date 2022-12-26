#include <iostream>

void swap_by_pointers(int* a, int* b) {

}

void swap_by_reference(){

}

int main(){
    int a;
    int b;

    int *pa = &a;
    int *pb = &b;

    std::cout << "input A and B\n";
    std::cin >> a >> b;
    std::printf("data A: %d, data B: %d\n", a, b);
    std::cout << "ss A: " << &a << ", " << "ss B: " << &b << "\n";

    std::printf("%X", *pa);
    std::printf("%X", *pb);
    return 0;
}