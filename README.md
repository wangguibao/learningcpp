# modern_cpp
Notes and code pieces developed in the process of learning modern C++ language

File name | Description
----------|------------
memory_order.c | A demo that shows that unrelated instructions can be reordered, causing surprising results
std_lock.cpp | Demonstrates the use of std::lock() which locks a set of locks simutaneously without deadlocking
thread_safe_resource_initialization.cpp | Demonstrates a safe way of initializing shared resource, by making sure the initialization is called only once
