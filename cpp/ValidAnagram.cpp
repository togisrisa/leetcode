#include <string>
#include <cassert>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        assert(s.size() >= 1 && s.size() <= (5 * 10'000));
        assert(t.size() >= 1 && t.size() <= (5 * 10'000));

        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> chars{};

        for (size_t i = 0; i < s.size(); i++) {
            chars[s[i]]++;
            chars[t[i]]--;
        }

        for (const auto& [ch, cnt] : chars) {
            if (cnt) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    using namespace std::literals;

    Solution solution;

    std::cout << "Test case 1: " << std::boolalpha << solution.isAnagram("anagram"s, "nagaram"s) << std::endl;
    std::cout << "Test case 2: " << solution.isAnagram("rat"s, "car"s) << std::endl;
}
