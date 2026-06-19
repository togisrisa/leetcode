#include <vector>
#include <iostream>

static void printVector(std::vector<int>& vec, std::ostream& out) {
    using namespace std::literals;

    bool first = true;
    for (const auto& it : vec) {
        if (!first) {
            out << ", "s;
        }
        first = false;
        out << it;
    }
    out << std::endl;
}

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = 0, j = 0;
        std::vector<int> result;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        nums1 = result;
    }
};

int main() {
    using namespace std::literals;

    Solution solution;

    std::cout << "Test case 1:"s << std::endl;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    printVector(nums1, std::cout);

    std::cout << "Test case 2:"s << std::endl;
    nums1 = {1};
    nums2 = {};
    solution.merge(nums1, 1, nums2, 0);
    printVector(nums1, std::cout);

    std::cout << "Test case 3:"s << std::endl;
    nums1 = {0};
    nums2 = {1};
    solution.merge(nums1, 0, nums2, 1);
    printVector(nums1, std::cout);
}
