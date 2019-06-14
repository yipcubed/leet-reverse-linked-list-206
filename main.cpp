#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 *
*/

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Input: 1->2->3->4->5->NULL
    // Output: 5->4->3->2->1->NULL
    ListNode* reverseList(ListNode* head) {
        if (!head || ! head->next)
          return head;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *pprev = nullptr;
        while (curr) {
          pprev = prev;
          prev = curr;
          curr = curr->next;
          prev->next = pprev;
        }
        return prev;
    }
};

void print(ListNode* head) {
  cout << "[";
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << "]" << endl;
}
int main() {
  Solution S;

  ListNode *n1 = new ListNode(1);
  print(n1);
  print(S.reverseList(n1));

  n1->next = new ListNode(2);
  n1->next->next = new ListNode(3);
  n1->next->next->next = new ListNode(4);
  n1->next->next->next->next = new ListNode(5);
  print(n1);
  print(S.reverseList(n1));

  // need to delete stuff
  std::cout << "Done\n";
}