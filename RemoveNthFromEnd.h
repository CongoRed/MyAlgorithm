#include<iostream>
using namespace std;

//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。 LeetCode 19

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n){
        ListNode *fast = head, *slow = head;
        while(n--){
            fast = fast -> next;
        }
        if(!fast) return head -> next;
        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode *temp = slow -> next;
        slow -> next = temp -> next;
        return head;
    }
};