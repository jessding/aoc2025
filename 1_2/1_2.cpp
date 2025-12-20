#include <input.h>
#include <iostream>
#include <fstream>
#include <string>

static int START = 50;
static int MAX = 99;
static int COUNTER = 0;

std::pair<int, int> get_next_num_and_passes(const std::string& line, int cur) {
    // TODO: pass computation implicitly assumes COUNTER number is 0
    char dir = line[0];
    int size = std::stoi(line.substr(1));
    int next = 0;
    int passes = 0;
    switch (dir) {
        case 'L':
            next = (cur - size) % (MAX + 1);
            if (next < 0) {
                next += (MAX + 1);
            }
            passes = (cur - size >= 0) ? 0 : (size - cur - 1) / (MAX + 1) + 1;
            if (cur == 0) passes--;
            return std::make_pair((next % (MAX + 1)), passes);
            break;
        default: // case 'R'
            next = cur + size;
            passes = next / (MAX + 1);
            if ((next % (MAX + 1)) == 0) passes--;
            return std::make_pair(next % (MAX + 1), passes);
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
        auto [next, passes] = get_next_num_and_passes(line, cur);
        std::cout << "line " << line << " next " << next << " passes " << passes << std::endl;
        cur = next;
        if (cur == COUNTER) password++;
        password += passes;
    }

    std::cout << "Password is " << password << std::endl;
    return 0;
}