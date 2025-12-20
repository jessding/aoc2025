#include <input.h>
#include <iostream>
#include <fstream>
#include <string>

static int START = 50;
static int MAX = 99;
static int COUNTER = 0;

int get_next_num(const std::string& line, int cur) {
    char dir = line[0];
    int size = std::stoi(line.substr(1));
    int next = 0;
    switch (dir) {
        case 'L':
            next = cur - size;
            if (next < 0) next = MAX + 1 + next;
            return next % (MAX + 1);
            break;
        default: // case 'R'
            next = cur + size;
            return next % (MAX + 1);
            break;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Input in; // wraps std::cin

    std::string line;
    int cur = START;
    int password = 0;
    while (std::getline(in.in, line)) {
        cur = get_next_num(line, cur);
        if (cur == COUNTER) password++;
    }

    std::cout << "Password is " << password << std::endl;
    return 0;
}