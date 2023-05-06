/**
 * thread_safe_resource_initialization.cpp
 * Demonstrates a safe way of initializing shared resource, by making sure
 * the initialization is called only once
 */
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>

class some_resource {
public:
    void do_something() {
        std::cout << "some_resource::do_something called" << std::endl;
    }
};

std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;

void once_func() {
    resource_ptr.reset(new some_resource);
}

void foo() {
    std::call_once(resource_flag, once_func);
    resource_ptr->do_something();
}

void thread_func() {
    foo();
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(std::thread(thread_func));
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }

    return 0;
}
