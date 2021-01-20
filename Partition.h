#ifndef _Partiton_
#define _Partition_
#include<iostream>
using namespace std;

/*给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。 LeetCode86
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution{
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *small_head = new ListNode(0);  
        ListNode *small = small_head;
        ListNode *large_head = new ListNode(0);                                                                                                                           
        ListNode *large = large_head;
        while(head){
            if(head -> val < x){
                small -> next = head;
                small = small -> next;
            }else{
                large -> next = head;
                large = large -> next;
            }
            head = head -> next;
        }
        large -> next = nullptr;
        small -> next = large_head -> next;
        return small -> next;
    }
};

#endif