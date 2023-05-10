/*
 * atom_compare_exchange_weak.cpp
 * Implements a lock-free stack using std::atomic<T>::compare_exchange_weak
 */
#include <atomic>
#include <iostream>
#include <vector>
#include <thread>
#include <sstream>

template <typename T>
struct Node {
    T value;
    Node<T>* next;

    Node(T& v) : value(v), next(nullptr) {}
};

template <typename T>
class Stack {
public:
    void push(T v) {
        Node<T>* new_node = new Node<T>(v);
        new_node->next = head.load(std::memory_order::memory_order_relaxed);

        while (!head.compare_exchange_weak(
                new_node->next,
                new_node,
                std::memory_order::memory_order_release,
                std::memory_order::memory_order_relaxed)) {}
    }

    void print() {
        auto* p = head.load(std::memory_order::memory_order_relaxed);
        std::ostringstream oss;
        while (p) {
            if (p == head) {
                oss << p->value;
            } else {
                oss << ", " << p->value;
            }

            p = p->next;
        }

        std::cout << oss.str().c_str() << std::endl;
    }
private:
    std::atomic<Node<T>*> head;
};

Stack<int> s;

const int THREADS = 10;
const int REPEATS = 2;

void push_element(int x) {
    s.push(x);
}

int main() {
    std::vector<std::thread> threads;
    for (auto i = 0; i < THREADS; ++i) {
        threads.emplace_back(push_element, i);
    }

    for (auto i = 0; i < THREADS; ++i) {
        threads[i].join();
    }

    s.print();

    return 0;
}
