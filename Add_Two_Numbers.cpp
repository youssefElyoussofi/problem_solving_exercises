

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


*/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addListTail(ListNode *list, ListNode *tail)
    {
        if (!list)
            return tail;
        ListNode *tmp = list;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = tail;
        return list;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *res = NULL;
        int rest = 0;
        while (l1 || l2)
        {
            int totale;
            if (rest)
            {
                totale = (l1 ? l1->val : 0)+ (l2 ? l2->val : 0) + rest;
                rest = 0;
            }
            else
                totale = (l1 ? l1->val : 0)+ (l2 ? l2->val : 0);
            if (totale > 9)
            {
                rest = totale / 10;
                totale %= 10;
            }
            ListNode* node = new ListNode(totale);

            res = addListTail(res,node);
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (rest)
        {
            ListNode* node = new ListNode(rest);

            res = addListTail(res,node);
        }
        return res;
    }
};

int main()
{
    /*
        Input: l1 = [2,4,3], l2 = [5,6,4]
        Output: [7,0,8]
        Explanation: 342 + 465 = 807.
    */
    ListNode l3(9, NULL), l2(9, &l3), l1(9, &l2);
    ListNode l4(9, NULL);

    Solution s;

    ListNode *res = s.addTwoNumbers(&l1, &l4);

    while (res)
    {
        std::cout << res->val << " ";
        ListNode* tmp = res;
        res = res->next;
        delete tmp;
    }
    std::cout << std::endl;
    return 0;
}