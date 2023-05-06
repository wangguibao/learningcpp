/*
 * std_future.cpp
 * Demonstrates std::future and std::async()
 */
#include <future>
#include <iostream>

int calc(int x) {
    return x <= 0? 0 : x + calc(x - 1);
}

void do_something() {
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    std::cout << "idle exit" << std::endl;
}

int main() {
    std::future<int> answer = std::async(calc, 3000);

    do_something();

    std::cout << answer.get() << std::endl;
    return 0;
}
