#include <input.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ranges>
#include <algorithm>
#include <unordered_set>

std::vector<int> get_length_divisors(int len) {
    std::vector<int> divisors;
    std::vector<int> larger_divisors;
    for (int i = 1; i <= std::sqrt(len); i++) {
        if (len % i == 0) {
            divisors.push_back(i);
            if (len/i != i) {
                larger_divisors.push_back(len/i);
            }
        }
    }
    for (int d : std::views::reverse(larger_divisors)) {
        divisors.push_back(d);
    }
    return divisors;
}

long long rep_subnum_n_times(int subnum, int reps) {
    long long result = 0;
    int sublen = std::floor(log10(subnum)) + 1;
    for (int i = 0; i < reps; i++) {
        result = result * (long long)std::pow(10, sublen) + subnum;
    }
    return result;
}

long long sum_invalid_in_range(long long l, long long r) {
    int l_len = std::floor(log10(l)) + 1;
    int r_len = std::floor(log10(r)) + 1;

    long long sum = 0;
    std::unordered_set<long long> invalids;

    for (int len = l_len; len <= r_len; len++) {
        std::vector<int> len_divisors = get_length_divisors(len);

        for (int sublen_i = 0; sublen_i < len_divisors.size() - 1; sublen_i++) {
            int sublen = len_divisors[sublen_i];

            long long l_stub = std::stoll(std::to_string(l).substr(0, sublen));
            long long pow_start = static_cast<long long>(std::round(std::pow(10, sublen - 1)));
            long long start_subnum = (len == l_len)? l_stub : pow_start;

            for (long long subnum = start_subnum; subnum < std::pow(10, sublen); subnum++) {
                long long invalid = rep_subnum_n_times(subnum, len/sublen);
                if ((invalids.find(invalid) == invalids.end())) {
                    if (l <= invalid && invalid <= r) {
                        sum += invalid;
                        invalids.insert(invalid);
                    }
                    if (invalid > r) break;
                }
            }
        }
    }
    std::cout << "invalids " ;
    for (const auto& element : invalids) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
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
