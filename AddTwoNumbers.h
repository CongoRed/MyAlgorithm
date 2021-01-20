#ifndef _AddTwoNumber_
#define _AddTwoNumber_
#include<iostream>
using namespace std;

struct ListNode {
	
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *new_list = new ListNode(-1), *new_list_head;
        new_list_head = new_list;
        int temp = 0; //保存进位
        while(l1 || l2 || temp == 1){    
            int x = 0;
            if(l1){
                x += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                x += l2 -> val;
                l2 = l2 -> next;
            } 
            x += temp;
            new_list -> val = x % 10;
            temp = x >= 10 ? 1 : 0;
            if(temp == 1 || l1 || l2){
                new_list -> next = new ListNode(-1);
                new_list = new_list -> next;
            }
        }
        return new_list_head;
    }
};

#endif