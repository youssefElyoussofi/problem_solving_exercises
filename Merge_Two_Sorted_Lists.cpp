/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

*/


#include <iostream>

struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergeList = nullptr;
        while(list1 && list2)
        {
            ListNode* node;
            if (list1->val <= list2->val)
            {
                node = list1;
                list1 = list1->next;
            }
            else
            {
                node = list2;
                list2 = list2->next;
            }
            node->next = nullptr;
            if (mergeList)
            {
               ListNode *lst = mergeList;
                while (lst->next)
                {
                    lst = lst->next;
                }
                lst->next = node;
            }
            else
                mergeList = node;
        }
        if (list1)
        {
            if (mergeList)
            {
                ListNode *lst = mergeList;
                while (lst->next)
                {
                    lst = lst->next;
                }
                lst->next = list1;
            }
            else
                mergeList = list1;
        }
        if (list2)
        {
            if (mergeList)
            {
                ListNode *lst = mergeList;
                while (lst->next)
                {
                    lst = lst->next;
                }
                lst->next = list2;
            }
            else
                mergeList = list2;
        }
        return mergeList;
    }
};

int main()
{
    ListNode l3(4),l2(2,&l3),l1(1,&l2);
    ListNode l7(4),l6(3,&l7),l5(1,&l6);

    Solution s;
    ListNode* merge = s.mergeTwoLists(&l1,&l5);

    while (merge)
    {
        std::cout << merge->val << " ";
        merge = merge->next;
    }
    std::cout << std::endl;
    
    return 0;
}