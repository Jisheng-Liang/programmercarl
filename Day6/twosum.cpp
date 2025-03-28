#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> twosum(vector<int>& num, int target){
            std::unordered_map <int,int> map;
            for(int i = 0; i < num.size(); i++){
                auto iter = map.find(target - num[i]);
                if(iter != map.end()){
                    return {iter->second, i};
                }
                map.insert(pair<int,int>(num[i], i));
            }
            return {};
        }
};

int main(){
    vector<int> num = {2,7,11,15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twosum(num, target);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " "; 
    }
    cout << endl;
    return 0;
}
