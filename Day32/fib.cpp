#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        // int fib(int n){
        //     if(n == 0) return 0;
        //     if(n == 1) return 1;
        //     return (fib(n-1)+fib(n-2));
        // }

        int fib(int N) {
            if (N <= 1) return N;
            int dp[2];
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i <= N; i++) {
                int sum = dp[0] + dp[1];
                dp[0] = dp[1];
                dp[1] = sum;
            }
            return dp[1];
        }
};