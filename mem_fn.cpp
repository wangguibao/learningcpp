/*
 * mem_fn.cpp
 *
 * Demonstrates mem_fn usage: wrap a pointer to member which can then be called as function
 */
#include <functional>
#include <iostream>

class Foo {
public:
    Foo() : data(5) {}
public:
    int get_data() {return data;}

    int add(int x) {return data + x;};
    int add(int x, int y) {return x + y;};

private:
    int data;
};

int main() {
    Foo foo;

    auto data = std::mem_fn(&Foo::get_data);
    std::cout << "get_data: " << data(foo) << std::endl;

    auto add1 = std::mem_fn<int(int), Foo>(&Foo::add);
    std::cout << "add(5): " << add1(foo, 5) << std::endl;

    auto add2 = std::mem_fn<int(int, int), Foo>(&Foo::add);
    std::cout << "add(10, 8): " << add2(foo, 10, 8) << std::endl;
}
