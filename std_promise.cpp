/*
 * std_promise.cpp
 * Demonstrates the std::promise usage
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

void calc_fab(int x, std::promise<int> promise) {
    int ret = calc(x);
    promise.set_value(ret);
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread work_thread = std::thread(calc_fab, 100, std::move(promise));

    std::cout << "answer = " << future.get() << std::endl;

    work_thread.join();
    return 0;
}
