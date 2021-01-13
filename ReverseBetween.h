#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        int begin = m;
        int x = n - m + 1, y = n - m;
        ListNode *temp = head, *front = head;
        while(-- begin){
            temp = temp -> next;
            if(begin > 1)   front = front -> next;
        }
        ListNode* new_head = temp;
        ListNode* next = NULL;
        while(x --){
            next = temp -> next;
            temp -> next = new_head;
            new_head = temp;
            temp = next;
        }
        front -> next = new_head;
        ListNode *_new_head = new_head;
        while(y --){
            new_head = new_head -> next;
        }
        new_head -> next = next;
        if(m == 1) return _new_head;
        return head;
    }

    //思路：head表示需要反转的头节点，pre表示需要反转头节点的前驱节点
    //我们需要反转n-m次，我们将head的next节点移动到需要反转链表部分的首部，需要反转链表部分剩余节点依旧保持相对顺序即可
    //比如1->2->3->4->5,m=1,n=5
    //第一次反转：1(head) 2(next) 3 4 5 反转为 2 1 3 4 5
    //第二次反转：2 1(head) 3(next) 4 5 反转为 3 2 1 4 5
    //第三次发转：3 2 1(head) 4(next) 5 反转为 4 3 2 1 5
    //第四次反转：4 3 2 1(head) 5(next) 反转为 5 4 3 2 1
    // ListNode* reverseBetween(ListNode* head, int m, int n) {
    //     ListNode *dummy=new ListNode(-1);
    //     dummy->next=head;
    //     ListNode *pre=dummy;
    //     for(int i=1;i<m;++i)pre=pre->next;
    //     head=pre->next;
    //     for(int i=m;i<n;++i){
    //         ListNode *nxt=head->next;
    //         //head节点连接nxt节点之后链表部分，也就是向后移动一位
    //         head->next=nxt->next;
    //         //nxt节点移动到需要反转链表部分的首部
    //         nxt->next=pre->next;
    //         pre->next=nxt;//pre继续为需要反转头节点的前驱节点
    //     }
    //     return dummy->next;
    // }
};