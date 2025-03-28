#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        vector<vector<int>> result; // 存放符合条件结果的集合
        vector<int> path; // 用来存放符合条件结果
        void backtracking(int n, int k, int startIndex) {
            if(path.size() == k){
                result.push_back(path);
                return;
            }
            for (int i = startIndex; i <= n; i++){
                path.push_back(i);
                backtracking(n, k, i+1);
                path.pop_back();
            }
        }
    public:
        vector<vector<int>> combine(int n, int k) {
            backtracking(n, k, 1);
            return result;
        }
    };