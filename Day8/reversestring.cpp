#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
    public:
        void reversestring(vector<char>& s){
            int tmp;
            for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
};

int main(){
    string str;
    cin >> str;

    vector<char> s={};
    for (int i = 0; i < str.length(); i++){
        s.insert(s.begin()+i, str[i]);
    }
    Solution solution;
    solution.reversestring(s);

    for (int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}