class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *p = head;
    ListNode *q = p;
    ListNode *r = q;
    int t = k;
    while (t != 1) {
      p = p->next;
      r = r->next;
      t--;
    }
    while(r->next){
        q = q->next;
        r = r->next;
    }
    int temp = p->val;
    p->val = q->val;
    q->val = temp;
    return head;
  }
}
