/*
 * std_future.cpp
 * Demonstrates the std::future usage
 */
#include <future>
#include <iostream>

int calc(int x) {
    return x <= 0? 0 : x + calc(x - 1);
}

void do_something() {
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    std::cout << "do_something exit" << std::endl;
}

int main() {
    std::cout << "std::async launched with default launch policy" << std::endl;
    std::future<int> answer = std::async(calc, 3000);

    do_something();

    std::cout << answer.get() << std::endl;

    std::cout << "std::async launched in a new thread" << std::endl;
    answer = std::async(std::launch::async, calc, 10000);
    do_something();

    std::cout << answer.get() << std::endl;

    std::cout << "std::async launched deferred" << std::endl;
    answer = std::async(std::launch::deferred, calc, 15000);
    answer.wait();
    std::cout << "future valid: " << answer.valid() << std::endl;

    do_something();
    std::cout << answer.get() << std::endl;
    return 0;
}
