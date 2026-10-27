#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::map<char, int> frequency;

    for (char c : text) {
        frequency[c]++;
    }

    std::vector<std::pair<char, int>> result(
        frequency.begin(), frequency.end()
    );

    std::stable_sort(
        result.begin(),
        result.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        }
    );

    for (const auto& item : result) {
        std::cout << item.first << ": " << item.second << '\n';
    }

    return 0;
}
