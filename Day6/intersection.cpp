#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
    public:
        vector<int> intersection(vector<int>& num1, vector<int>& num2) {
            unordered_set<int> result_set;
            unordered_set<int> nums_set(num1.begin(), num1.end());
            for(int num:num2){
                if(nums_set.find(num) != nums_set.end()){
                    result_set.insert(num);
                }
            }
            return vector<int>(result_set.begin(), result_set.end());
        }
};

int main() {

	vector<int> num1 = {4,9,5};
    vector<int> num2 = {9,4,8,4};

    Solution solution;
    vector<int> result = solution.intersection(num1, num2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

	return 0;
}