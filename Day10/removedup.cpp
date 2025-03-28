#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
    public:
        string removeDuplicates(string S){
            stack<char> st;
            for (char s : S) {
                if (st.empty() || s != st.top()) {
                    st.push(s);
                } else {
                    st.pop(); // s 与 st.top()相等的情况
                }
            }
            string res = "";
            while(!st.empty()){
                res += st.top();
                st.pop();
            }
            reverse (res.begin(), res.end());
            return res;
        }
};

int main(){
    string s = "abbaca";

    Solution solution;
    string res = solution.removeDuplicates(s);
    cout << res << endl;
    return 0;
}