# modern_cpp
Notes and code pieces developed in the process of learning modern C++ language

File name | Description
----------|------------
demo_std_tie.cpp | Demo std::tie() usage
implementing_range_based_for.cpp | Implementing C++ ranged for for a user defined type. From the book Modern C++ Programming Cookbook, 2e, by Marius Bancila
memory_order.c | A demo that shows that unrelated instructions can be reordered, causing surprising results
rwlock.cpp | Use std::shared_mutex, std::shared_lock and std::lock_guard to simulate the behavior of rwlock
std_lock.cpp | Demonstrates the use of std::lock() which locks a set of locks simutaneously without deadlocking
thread_safe_resource_initialization.cpp | Demonstrates a safe way of initializing shared resource, by making sure the initialization is called only once
