#include <input.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N_TURN_ON = 12;

vector<int> get_max_joltage(vector<int> bank) {
    // idea: greedy L to R
    // keep a stack of max size N_TURN_ON
    // for each digit you see, if it's geq top of stack push it and continue
    // else start popping from top of stack until top not geq cur or you won't be able to reach N_TURN_ON size even if you pushed all remaining
    vector<int> stack;
    for (int i = 0; i < bank.size(); i++) {
        int digit = bank[i];
        int remaining = bank.size() - i;

        while (!stack.empty()
               && digit > stack.back()
               && stack.size() + remaining > N_TURN_ON) {
            stack.pop_back();
        }

        stack.push_back(digit);
    }

    stack.resize(N_TURN_ON);
    return stack;
}

long long ivtoll(vector<int> list) {
    // smallest index = most significant digit!
    long long result = 0;
    for (const int& digit : list) {
        result = result * 10 + digit;
    }
    return result;
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
    long long total_joltage = 0;
    while (std::getline(in.in, bank)) {
        std::cout << bank << std::endl;
        vector<int> digits = stoiv(bank);
        vector<int> turned_on = get_max_joltage(digits);

        std::cout << "turned on elements: ";
        for (const auto& element : turned_on) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        long long max_joltage = ivtoll(turned_on);
        cout << "max joltage " << max_joltage << endl;
        total_joltage += max_joltage;
    }

    cout << "The total max output joltage is " << total_joltage << endl;

    return 0;
}
