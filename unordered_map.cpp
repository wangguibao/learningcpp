#include <iostream>
#include <unordered_map>

class Foo {
public:
    int val;
};

class KeyHash {
public:
    size_t operator() (const Foo& foo) const {
        return foo.val;
    }
};

class KeyCompare {
public:
    bool operator() (const Foo& left, const Foo& right) const {
        return (left.val == right.val);
    }
};

class Bar {
public:
    bool operator == (const Bar& bar) const {
        return val == bar.val;
    }

    int val;
};

namespace std {
template<> struct hash<Bar> {
    size_t operator() (const Bar& bar) const {
        return bar.val;
    }
};
}

int main() {
    std::unordered_map<int, std::string> m1;
    m1.insert({1, "dddddd"});
    m1.insert({2, "eeeeee"});

    for (auto& [first, second]: m1) {
        std::cout << first << ": " << second << std::endl;
    }

    std::unordered_map<Foo, std::string, KeyHash, KeyCompare> m2;
    Foo foo1;
    foo1.val = 3;

    Foo foo2;
    foo2.val = 5;

    m2.insert({foo1, "foo1"});
    m2.insert({foo2, "foo2"});

    for (auto& [first, second]: m2) {
        std::cout << first.val << ": " << second << std::endl;
    }

    std::unordered_map<Bar, std::string> m3;
    Bar bar1;
    bar1.val = 6;

    Bar bar2;
    bar2.val = 7;

    m3.insert({bar1, "bar1"});
    m3.insert({bar2, "bar2"});

    for (auto& [first, second]: m3) {
        std::cout << first.val << ": " << second << std::endl;
    }
    return 0;
}
