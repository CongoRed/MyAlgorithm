#include<iostream>
using namespace std;

/*
给定一个链表，判断链表中是否有环。 LeetCode 141
*/

/*
思路：快慢指针
快慢指针可由出发早晚和速度来区分其快和慢，本题用速度
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head -> next)   return false;
        ListNode *fast = head -> next, *slow = head;
        while(slow != fast){
            if(!fast || !fast -> next)   return false;
            slow = slow -> next;
            if(fast -> next && fast -> next -> next){
                fast = fast -> next -> next;
            }else{
                return false;
            }
        }
        return true;
    }
};