#include<iostream>
#include<string>
#include<stack>
using namespace std;

//二进制数相加

class Solution {
public:
    string addBinary(string a, string b) {
        stack<int> s;
        int temp = 0;
        int a_length = a.length(), b_length = b.length();
        int length = a.length() < b.length() ? a.length() : b.length();
        string temp_str = a.length() > b.length() ? a : b;
        string str = "";
        for(int i = 0;i < length;i ++){
            int num = a[a_length - 1 - i] + b[b_length - 1 - i] - 96;
            num += temp;
            s.push(num % 2);
            temp = num / 2;
        }
        for(int i = temp_str.length() - length - 1;i >= 0;i --){
            int num = temp_str[i] - '0' + temp;
            s.push(num % 2);
            temp = num / 2;
        }
        if(temp > 0) s.push(temp);
        while(!s.empty()){
            str += to_string(s.top());
            s.pop();
        }
        return str;
    }
};