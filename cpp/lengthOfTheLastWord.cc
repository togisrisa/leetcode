#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:
        int lengthOfTheLastWord(string s);
};

int Solution::lengthOfTheLastWord(string s) {
    assert(((s.length() >= 1) && (s.length() <= pow(10, 4))) &&
            "Input data does not correspond to requirements!");

    vector<string> words {};
    const string separator = " ";

    auto start = s.find_first_not_of(separator);
    while (start != string::npos) {
        auto end = s.find_first_of(separator, start + 1);

        if (end == string::npos)
            end = s.length();

        auto word = s.substr(start, end - start);
        words.push_back(word);

        start = s.find_first_not_of(separator, end + 1);
    }

    return words.back().length();
}

int main() {
    Solution solution;

    const string testCase1 = "Hello World";
    const string testCase2 = "   fly me   to   the moon  ";
    const string testCase3 = "luffy is still joyboy";

    cout << "Result test case 1: " << solution.lengthOfTheLastWord(testCase1) << endl;
    cout << "Result test case 2: " << solution.lengthOfTheLastWord(testCase2) << endl;
    cout << "Result test case 3: " << solution.lengthOfTheLastWord(testCase3) << endl;

    return 0;
}
