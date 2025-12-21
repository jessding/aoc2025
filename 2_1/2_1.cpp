#include <input.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

long long sum_invalid_in_range(long long l, long long r) {
    // Notice invalid IDs can be written as x * (10^k+1)
    // Where k >= 1 and 10^(k-1) <= x <= 10^k - 1
    // This gives invalid IDs of digit length 2k
    int l_len = std::floor(log10(l)) + 1;
    int r_len = std::floor(log10(r)) + 1;
    long long sum = 0;
    for (int k = std::floor(l_len/2); k <= std::ceil(r_len/2); k++) {
        for (long long x = std::pow(10, k-1); x <= std::pow(10, k) -1; x++) {
            long long invalid = x * (std::pow(10, k) + 1);
            if (l <= invalid && invalid <= r) sum += invalid;
            if (invalid > r) break;
        }
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Input in; // wraps std::cin

    std::string range;
    long long sum = 0;
    while (std::getline(in.in, range, ',')) {
        std::cout << range << std::endl;
        size_t pos = range.find('-');
        long long l = std::stoll(range.substr(0, pos));
        long long r = std::stoll(range.substr(pos + 1));
        sum += sum_invalid_in_range(l, r);
    }

    std::cout << "Sum of invalid IDs is " << sum << std::endl;

    return 0;
}
