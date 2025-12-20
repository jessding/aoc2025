#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cassert>

struct Input {
    std::istream& in;
    explicit Input(std::istream& is = std::cin) : in(is) {}

    template <typename T>
    Input& operator>>(T& x) {
        in >> x;
        return *this;
    }

    Input& line(std::string& s) {
        std::getline(in >> std::ws, s);
        return *this;
    }
};
