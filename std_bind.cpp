#include <functional>
#include <iostream>

int func2(int x, int y) {
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}

int func3(int x, int y, int z) {
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    return 0;
}



int main() {
    int x = 1;
    int y = 2;
    int z = 3;

    // f is a function object that can be called without arguments
    auto f = std::bind(func2, x, y);
    f();

    // g is a function object that can be called without arguments
    auto g = std::bind(func3, x, y, z);
    g();
}
