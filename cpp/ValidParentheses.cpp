#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <stack>

using namespace std::literals;

class Solution {
public:
    bool isValid(std::string s) {
        assert(s.size() >= 1 && s.size() <= 10'000);

        std::stack<char> stack{};

        for (const auto& ch : s) {
            switch (ch) {
            case '(':
                [[fallthrough]];
            case '[':
                [[fallthrough]];
            case '{':
                stack.push(ch);
                break;
            case ')':
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                } else {
                    return false;
                }
                break;
            case ']':
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                } else {
                    return false;
                }
                break;
            case '}':
                if (!stack.empty() && stack.top() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
                break;
            default:
                return false;
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution solution;

    std::cout << "Test case 1: "s << std::boolalpha << solution.isValid("()"s) << std::endl;
    std::cout << "Test case 2: "s << std::boolalpha << solution.isValid("()[]{}"s) << std::endl;
    std::cout << "Test case 3: "s << std::boolalpha << solution.isValid("(]"s) << std::endl;
    std::cout << "Test case 4: "s << std::boolalpha << solution.isValid("([])"s) << std::endl;
    std::cout << "Test case 5: "s << std::boolalpha << solution.isValid("([)]"s) << std::endl;
}
