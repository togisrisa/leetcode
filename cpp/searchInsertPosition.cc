#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

class Solution {
    public:
        [[nodiscard]] int searchInsert(std::vector<int>& nums, int target);
};

int Solution::searchInsert(std::vector<int>& nums, int target) {
    assert(nums.size() >= 1);
    assert(nums.size() <= pow(10, 4));

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    Solution solution;

    /// test case 1
    std::vector<int> testCase1 {1, 3, 5, 6};
    std::cout << "Test case 1: result: " << solution.searchInsert(testCase1, 5) << std::endl;

    /// test case 2
    std::cout << "Test case 2: result: " << solution.searchInsert(testCase1, 2) << std::endl;

    /// test case 3
    std::cout << "Test case 3: result: " << solution.searchInsert(testCase1, 7) << std::endl;

    /// test case 4
    std::cout << "Test case 3: result: " << solution.searchInsert(testCase1, 0) << std::endl;

    return 0;
}
