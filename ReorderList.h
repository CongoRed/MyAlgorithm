#ifndef _ReorderList_
#define _ReorderList_
#include<iostream>
#include<vector>
using namespace std;

/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
		if(!head) return;
		ListNode *temp = head;
		vector<ListNode*> v;
		int left = 0, right = 0;
		while(head){
			v.push_back(head);
			head = head -> next;
			right ++;
		}		
		right --;
		while(left < right){
			v[left] -> next = v[right];
			left ++;
			if(left == right)	break;
			v[right] -> next = v[left];
			right -- ;
		}
		v[left] -> next = nullptr;
		head = temp;
    }
};

#endif