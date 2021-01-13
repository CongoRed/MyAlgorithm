#include<iostream>
#include<stack>
#include<queue>
#include<string>

/* 外观数列   LeetCode 38
1.     1
2.     11
3.     21
4.     1211
5.     111221
*/

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        queue<int> q1;
        queue<int> q2;
        int currentNum = 1;
        int numCount = 0;
        q1.push(currentNum);
        string str = "";
        while(--n){
            currentNum = q1.front();
            while(!q1.empty()){
                if(currentNum == q1.front()){
                    numCount ++;
                    q1.pop();
                }else{
                    q2.push(numCount);
                    q2.push(currentNum);
                    numCount = 0;
                    currentNum = q1.front();
                }
                if(q1.empty()){
                    q2.push(numCount);
                    q2.push(currentNum);
                    numCount = 0;
                }
            }
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        while(!q1.empty()){
            str += to_string(q1.front());
            q1.pop();
        }
        return str;
    }
};