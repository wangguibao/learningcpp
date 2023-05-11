# modern_cpp
Notes and code pieces developed in the process of learning modern C++ language

File name | Description
----------|------------
atomic_compare_exchange_weak.cpp | Implements a lock-free stack using std::atomic<T>::compare_exchange_weak
atomic_flag_test_and_set.cpp | Implements a spinlock using std::atomic_flag::test_and_set
demo_std_tie.cpp | Demo std::tie() usage
implementing_range_based_for.cpp | Implementing C++ ranged for for a user defined type. From the book Modern C++ Programming Cookbook, 2e, by Marius Bancila
memory_order.c | A demo that shows that unrelated instructions can be reordered, causing surprising results
rwlock.cpp | Use std::shared_mutex, std::shared_lock and std::lock_guard to simulate the behavior of rwlock
std_future.cpp | Demonstrates std::future and std::async()
std_lock.cpp | Demonstrates the use of std::lock() which locks a set of locks simutaneously without deadlocking
std_promise.cpp | Demonstrates the std::promise usage
thread_safe_resource_initialization.cpp | Demonstrates a safe way of initializing shared resource, by making sure the initialization is called only once
