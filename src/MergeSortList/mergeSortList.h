/**
* https://leetcode.com/problems/sort-list/
* merge sort list implementation based on NeetCode explanation https://www.youtube.com/watch?v=TGveA1oFhrc
**/

#ifndef MERGE_SORT_LIST_H
#define MERGE_SORT_LIST_H

/*
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class MergeSort {
public:
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next == nullptr)
            return head;
        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* tmp = right->next;
        right->next = nullptr;
        right = tmp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
    ListNode* getMid(ListNode* root)
    {
      ListNode* slow = root;
      ListNode* fast = root->next;
      while(slow && fast && fast->next)
      {
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right)
    {
      ListNode dummy;
      ListNode* tail = &dummy;
      while(left && right)
      {
        if (left->val < right->val)
        {
          tail->next = left;
          left = left->next;
        }
        else
        {
          tail->next = right;
          right = right->next;
        }
        tail = tail->next;
      }
      if (left)
        tail->next = left;
      if (right)
        tail->next = right;
      return dummy.next;
    }
};

#endif