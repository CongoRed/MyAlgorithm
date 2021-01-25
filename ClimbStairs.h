#ifndef _ClimbStairs_
#define _ClimbStairs_

#include<iostream>
using namespace std;

//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

class Solution {
public:
    int a[50];
    int climbStairs(int n) {
        a[1] = 1;
        a[2] = 2;
        for(int i = 3;i <= n;i ++){
            a[i] = a[i - 1] + a [i - 2];
        }
        return a[n];
    }
};

#endif