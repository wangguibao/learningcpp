/*
 * heap_demo.cpp
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/18 16:53
 * @brief demonstrates heap related algorithms in C++
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>

void print(std::vector<int> vec) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << vec[i];
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Before make_heap: ";
    print(vec);

    std::make_heap(vec.begin(), vec.end());
    std::cout << "After make_heap:";
    print(vec);

    std::cout << "is_heap: " << std::is_heap(vec.begin(), vec.end()) << std::endl;

    std::pop_heap(vec.begin(), vec.end());
    std::cout << "After pop_heap:";
    print(vec);

    auto it = std::is_heap_until(vec.begin(), vec.end());
    std::cout << "Is heap until: " << *it << std::endl;

    std::pop_heap(vec.begin(), it);
    std::cout << "After pop_heap:";
    print(vec);
    it = std::is_heap_until(vec.begin(), vec.end());
    std::cout << "Is heap until: " << *it << std::endl;
    return 0;
}
