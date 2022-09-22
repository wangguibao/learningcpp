/**
 * @file demo_std_tie.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2022/09/22 12:31:57
 * @brief std::tie() demo.
 * Need --std=c++11
 **/
#include <set>
#include <tuple>
#include <iostream>

int main() {
    std::set<int32_t> set_of_int;

    std::set<int32_t>::iterator iter;
    bool inserted = false;

    // There's conversion begween std::tuple and std::pair here
    std::tie(iter, inserted) = set_of_int.insert(1);

    if (inserted) {
        std::cout << "Insert into std::set first time success" << std::endl;
    } else {
        std::cout << "Insert into std::set first time fail" << std::endl;
    }

    // Here use std::ignore
    std::tie(std::ignore, inserted) = set_of_int.insert(1);
    if (inserted) {
        std::cout << "Insert the same value second time success" << std::endl;
    } else {
        std::cout << "Insert the same value second time fail" << std::endl;
    }

    return 0;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
