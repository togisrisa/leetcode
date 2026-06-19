#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    // test case 1
    {
        ListNode *head = new ListNode(3);
        ListNode *sec = new ListNode(2);
        ListNode *thr = new ListNode(0);
        ListNode *fr = new ListNode(-4);

        head->next = sec;
        sec->next = thr;
        thr->next = fr;
        fr->next = sec;

        Solution solution;
        std::cout << "Test case 1: " << std::boolalpha << solution.hasCycle(head) << std::endl;

        delete fr;
        delete thr;
        delete sec;
        delete head;
    }

    // test case 2
    {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = head;

        Solution solution;
        std::cout << "Test case 2: " << std::boolalpha << solution.hasCycle(head) << std::endl;

        delete head->next;
        delete head;
    }

    // test case 3
    {
        ListNode *head = new ListNode(1);

        Solution solution;
        std::cout << "Test case 3: " << std::boolalpha << solution.hasCycle(head) << std::endl;

        delete head;
    }
}
