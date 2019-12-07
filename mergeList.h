合并两个链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && 12 ==NULL)
            return NULL;
        else if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        ListNode *l1_now = l1;
        ListNode *l2_now = l2;
        ListNode *head = NULL;
        ListNode *ret = new ListNode(0);
        if(l1_now->val < l2_now->val)
        {
            ret->val = l1_now->val;
            head = ret;
            l1_now = l1_now->next;
        }
        else
        {
            ret->val = l2_now->val;
            head = ret;
            l2_now = l2_now->next;
        }
        while(l1_now != NULL && l2_now != NULL)
        {
            if(l1_now->val == l2_now->val)
            {
                ListNode *temp = new ListNode(l1_now->val);
                ret->next = temp;
                ret = ret->next;
                ListNode *temp2 = new ListNode(l2_now->val);
                ret->next = temp2;
                ret = ret->next;
                l1_now = l1_now->next;
                l2_now = l2_now->next;
            }
            else if(l1_now->val < l2_now->val)
            {
                ListNode *temp = new ListNode(l1_now->val);
                ret->next = temp;
                ret = ret->next;
                l1_now = l1_now->next;
            } 
            else if(l1_now->val > l2_now->val)
            {
                ListNode *temp = new ListNode(l2_now->val);
                ret->next = temp;
                ret = ret->next;
                l2_now = l2_now->next;
            } 
        }
        if(l1_now == NULL)
        {
            ret->next = l2_now;
        }
        else if(l2_now == NULL)
        {
            ret->next = l1_now;
        }
        return head;
    }
};