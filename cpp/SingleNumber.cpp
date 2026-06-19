#include <cassert>
#include <vector>
#include <iostream>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        assert(nums.size() >= 1 && nums.size() <= (3 * 10'000));

        int unique{};

        for (int num : nums) {
            unique ^= num;
        }

        return unique;
    }
};

int main() {
    Solution solution{};

    std::vector<int> test_case1 = {2, 2, 1};
    std::cout << "Test case1: " << solution.singleNumber(test_case1) << std::endl;

    std::vector<int> test_case2 = {4, 1, 2, 1, 2};
    std::cout << "Test case2: " << solution.singleNumber(test_case2) << std::endl;

    std::vector<int> test_case3 = {1};
    std::cout << "Test case3: " << solution.singleNumber(test_case3) << std::endl;
}
