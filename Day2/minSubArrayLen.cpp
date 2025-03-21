#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size();
            int slowIndex = 0;
            int sum = 0;
            int length = n;
            for(int fastIndex = 0; fastIndex < n; fastIndex++){
                sum += nums[fastIndex];
                while(sum >= target){
                    length = min(length, fastIndex - slowIndex + 1);
                    sum -= nums[slowIndex++];
                }
            }
            if(length < n){
                return length;
            }
            return 0;
    }
};

int main() {
    Solution Solution;
    vector<int> nums = {1,4,4};
    int target = 4;
    cout << Solution.minSubArrayLen(target, nums) << endl;
    return 0;
}