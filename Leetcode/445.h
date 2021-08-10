class ListNode{
    public:
        int val;
        ListNode* next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> a;
        stack<int> b;
        while (l1) {
            a.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            b.push(l2->val);
            l2 = l2->next;
        }
        ListNode* final = new ListNode(0);
        int carry = 0;
        int sum = 0;
        while (!a.empty() || !b.empty() || carry) {
            if (!a.empty()) {
                sum += a.top();
                a.pop();
            }
            if (!b.empty()) {
                sum += b.top();
                b.pop();
            }
            ListNode* node = new ListNode(sum % 10);
            node->next = final->next;
            final->next = node;

            carry = (sum /= 10);
        }
        return final->next;
    }
};
