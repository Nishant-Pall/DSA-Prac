class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        ListNode *p = head;
        while(p){
            nums.emplace_back(p->val);
            p=p->next;
        }
        vector<int> ans(nums.size());
        stack<int> s;
        for (int i=nums.size()-1; i>=0; i--) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            ans[i] = s.top() ? 0 : s.top();
            s.push(nums[i]);
        }
        return ans;
    }
};
