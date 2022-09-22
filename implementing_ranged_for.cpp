/**
 * @file implementing_ranged_for.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2022/09/19 18:01:17
 * @brief implementing C++ ranged for for a user defined type.
 * From the book Modern C++ Programming Cookbook, 2e, by Marius Bancila
 *
 **/
#include <iostream>
#include <vector>
#include <map>

template <typename T, size_t const Size>
class dummy_array {
public:
    const T& getAt(int i) {
        if (i < Size) {
            return _data[i];
        }

        throw std::out_of_range("Out of range");
    }

    void setAt(size_t const index, T const& value) {
        if (index < Size) {
            _data[index] = value;
        } else {
            throw std::out_of_range("Out of range");
        }
    }

    size_t getSize() const {
        return Size;
    }

private:
    T _data[Size] = {};
};

template <typename T, typename C, size_t const Size>
class dummy_array_iterator_type {
public:
    dummy_array_iterator_type(C& collection, size_t const index):
        _index(index), _collection(collection) {}

    bool operator != (dummy_array_iterator_type const& other) {
        return this->_index != other._index;
    }

    T const operator*() const {
        return _collection.getAt(_index);
    }

    dummy_array_iterator_type& operator++() {
        ++_index;
        return *this;
    }

    dummy_array_iterator_type operator++(int) {
        auto tmp = *this;
        operator++();
        return tmp;
    }

private:
    size_t _index;
    C& _collection;
};

template <typename T, size_t const Size>
using dummy_array_iterator =
    dummy_array_iterator_type<T, dummy_array<T, Size>, Size>;

template <typename T, size_t const Size>
using dummy_array_const_iterator =
    dummy_array_iterator_type<T, dummy_array<T, Size> const, Size>;

template <typename T, size_t const Size>
inline dummy_array_iterator<T, Size> begin(dummy_array<T, Size>& collection) {
    return dummy_array_iterator<T, Size>(collection, 0);
}

template <typename T, size_t const Size>
inline dummy_array_iterator<T, Size> end(dummy_array<T, Size>& collection) {
    return dummy_array_iterator<T, Size>(collection, collection.getSize());
}

template <typename T, size_t const Size>
inline dummy_array_const_iterator<T, Size> begin(dummy_array<T, Size> const& collection) {
    return dummy_array_const_iterator<T, Size>(collection, 0);
}

template <typename T, size_t const Size>
inline dummy_array_const_iterator<T, Size> end(dummy_array<T, Size> const& collection) {
    return dummy_array_const_iterator<T, Size>(collection, collection.getSize());
}

int main() {
    dummy_array<int32_t, 10> my_array;

    my_array.setAt(1, 2);
    my_array.setAt(8, 10);
    my_array.setAt(9, 11);

    for (const auto&& e: my_array) {
        std::cout << e << std::endl;
    }

    return 0;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
