#include <vector>
#include <iostream>
#include <cassert>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        assert(nums.size() >= 1 && nums.size() <= (10'000));

        int start = 0;
        int end = static_cast<int>(nums.size() - 1);

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            }
        }

        return -1;
    }

    int searchRecursive(std::vector<int>& nums, int target) {
        assert(nums.size() >= 1 && nums.size() <= 10'000);
        return recursiveBinarySearch(nums, target, 0, static_cast<int>(nums.size() - 1));
    }

    int recursiveBinarySearch(std::vector<int>& nums, int target, int start, int end) {
        if (start > end) {
            return -1;
        }

        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return recursiveBinarySearch(nums, target, mid + 1, end);
        }

        // case when nums[mid] > target
        return recursiveBinarySearch(nums, target, start, mid - 1);
    }
};

int main() {
    Solution solution;

    std::vector<int> test_case = {-1, 0, 3, 5, 9, 12};

    std::cout << "Test case 1: " << solution.search(test_case, 9) << std::endl;
    std::cout << "Test case 2: " << solution.search(test_case, 2) << std::endl;
    std::cout << "Test case 3: " << solution.searchRecursive(test_case, 9) << std::endl;
    std::cout << "Test case 4: " << solution.searchRecursive(test_case, 2) << std::endl;
}
