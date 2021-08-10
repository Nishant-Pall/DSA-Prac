class ListNode {
public:
    int val;
    ListNode* next;
};

class Solution {
public:
    void mergeList(ListNode* head1, ListNode* head2)
    {
        ListNode* res = head1;
        ListNode* l = res;
        if (head1->val < head2->val) {
            res = head1;
            head1 = head1->next;
            l->next = nullptr;
        } else {
            res = head2;
            head2 = head2->next;
            l->next = nullptr;
        }
        while (head1 && head2) {
            if (head2->val < head1->val) {
                l->next = head2;
                head2 = head2->next;
                l = head2;
                l->next = nullptr;
            } else {
                l->next = head1;
                head1 = head1->next;
                l = head1;
                l->next = nullptr;
            }
        }
    }

    ListNode* sortList(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next->next && head) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        sortList(head);
        sortList(head2);
        mergeList(head, head2);
        return head;
    }
};
