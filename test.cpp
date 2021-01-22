#include <bits/stdc++.h>
#include"ReorderList.h"

using namespace std;

int main(){
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;  
    d.next = &e;
    ListNode *head = &a;
    Solution s;
    s.reorderList(head);
    while(head){
        cout<<head -> val<<" "<<endl;
        head = head -> next;
    }
    getchar();
}