/*
 * atomic_flag_test_and_set.cpp
 * Implements a spinlock using std::atomic_flag::test_and_set
 */
#include <atomic>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class spinlock_mutex {
public:
    spinlock_mutex(): flag(ATOMIC_FLAG_INIT) {};

    void lock() {
        while (flag.test_and_set()) {}
    }

    void unlock() {
        flag.clear();
    }
private:
    std::atomic_flag flag;
};

struct atomic_counter {
    int counter = 0;
    spinlock_mutex mutex;
};

atomic_counter counter;

void thread_func(int id) {
    counter.mutex.lock();
    ++counter.counter;
    std::cout << counter.counter << std::endl;
    counter.mutex.unlock();
}

int main() {
    std::vector<std::thread> threads;

    for (auto i = 0; i < 10; ++i) {
        threads.emplace_back(thread_func, i);
    }

    for (auto i = 0; i < 10; ++i) {
        threads[i].join();
    }
    return 0;
}
