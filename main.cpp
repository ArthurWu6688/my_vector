#include <iostream>
#include <cassert>
#include <algorithm>
#include "vector.h"

void test_vector1() {
    wyp::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector2() {
    wyp::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    v.resize(10, 0);
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector3() {
    wyp::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
//    v.pop_back();
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector4() {
    wyp::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    v.insert(v.begin(), 0);
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        v.insert(it, 10);
    }
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    v.pop_back();
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector5() {
    wyp::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        v.erase(it);
    }
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector6() {
    wyp::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        if (*it % 2 == 0) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }

    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector7() {
    wyp::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    std::cout << "v1:";
    for (auto e: v1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::vector<int> v2(v1);
    std::cout << "v2:";
    for (auto e: v1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector8() {
    wyp::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for (auto e: v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::vector<int>::reverse_iterator rit = v.rbegin();
    while (rit != v.rend()) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;
}

int main() {
    test_vector8();
    return 0;
}
