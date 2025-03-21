#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (nums[fastIndex] != val)
            {
                nums[slowIndex++] = nums[fastIndex];
            } 
        }
        return slowIndex;
    }
};

int main() {
    Solution Solution;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    cout << Solution.removeElement(nums, val) << endl;
    return 0;
}