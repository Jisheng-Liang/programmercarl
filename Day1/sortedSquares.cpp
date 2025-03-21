#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n = nums.size();
            vector<int> result(n);
            int k = n-1;
            for (int i = 0, j = n-1; i <= j;){
                if(nums[i]*nums[i] > nums[j]*nums[j]){
                    result[k--] = nums[i]*nums[i];
                    i++;
                }else{
                    result[k--] = nums[j]*nums[j];
                    j--;
                }
            }
            return result;
        }
    };

int main() {
    Solution Solution;
    vector<int> nums = {-7,-3,2,3,11};
    for(auto array: Solution.sortedSquares(nums)){
        cout << array << " ";
    }
    cout << endl;
    return 0;
}