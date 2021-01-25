#ifndef _GetIntersectionNode_
#define _GetIntersectionNode_

#include<iostream>
using namespace std;

//找到两个单链表相交的起始节点。
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;
        ListNode *h1 = headA; 
        ListNode *h2 = headB;
        int count = 0;
        while(h1 != h2){
            h1 = h1 ? h1 -> next : headB;
            h2 = h2 ? h2 -> next : headA;
            count ++;
        }
        return h1;
    }
};
//链表相连不一定要地址相连，通过变量也可以相连，而且防止环的产生
#endif