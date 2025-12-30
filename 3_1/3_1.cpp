#include <input.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int get_max_joltage(vector<int> bank) {
    // use DP where dp[i] = max( dp[i+1], bank[i] ) starting from back
    // dp[i] repr max(bank[i+1:])
    vector<int> dp(bank.size()+1);
    dp[bank.size()] = 0;
    for (int i = bank.size()-1; i >= 0; i--) {
        dp[i] = max(bank[i], dp[i+1]);
    }

    vector<int> joltages;
    for (int i = 0; i < bank.size() - 1; i++) {
        joltages.push_back(10*bank[i] + dp[i+1]);
    }
    return *max_element(joltages.begin(), joltages.end());
}

vector<int> stoiv(string bank) {
    vector<int> digits;
    for (char& digit : bank) {
        digits.push_back(digit - '0');
    }
    return digits;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Input in; // wraps std::cin

    std::string bank;
    int total_joltage = 0;
    while (std::getline(in.in, bank)) {
        std::cout << bank << std::endl;
        vector<int> digits = stoiv(bank);
        cout << "max joltage " << get_max_joltage(digits) << endl;
        total_joltage += get_max_joltage(digits);
    }

    cout << "The total max output joltage is " << total_joltage << endl;

    return 0;
}
