#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree (vec.size(), NULL);
    TreeNode* root = NULL;
    // 把输入数值数组，先转化为二叉树节点数组
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]); // 用 -1 表示null
        vecTree[i] = node;
        if(i == 0) root = node;
    }
    // 遍历一遍，根据规则左右孩子赋值就可以了
    // 注意这里 结束规则是 i * 2 + 1 < vec.size()，避免空指针
    // 为什么结束规则不能是i * 2 + 2 < arr.length呢?
    // 如果i * 2 + 2 < arr.length 是结束条件
    // 那么i * 2 + 1这个符合条件的节点就被忽略掉了
    // 例如[2,7,9,-1,1,9,6,-1,-1,10] 这样的一个二叉树,最后的10就会被忽略掉
    // 遍历一遍，根据规则左右孩子赋值就可以了
           
    for (int i = 0; i * 2 + 1 < vec.size(); i++) {
        if(vecTree[i] != NULL){
            vecTree[i]->left = vecTree[i*2+1];
            if(i*2 + 2 < vec.size()){
                vecTree[i]->right = vecTree[i*2+2];
            }
        }
    }
    return root;
};

class Solution{
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            stack<TreeNode*> st;
            vector<int> result;
            if (root == NULL) return result;
            st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();                       // 中
                st.pop();
                result.push_back(node->val);
                if (node->right) st.push(node->right);           // 右（空节点不入栈）
                if (node->left) st.push(node->left);             // 左（空节点不入栈）
            }
            return result;
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> st;
            TreeNode* cur = root;
            while (cur != NULL || !st.empty()) {
                if (cur != NULL) { // 指针来访问节点，访问到最底层
                    st.push(cur); // 将访问的节点放进栈
                    cur = cur->left;                // 左
                } else {
                    cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                    st.pop();
                    result.push_back(cur->val);     // 中
                    cur = cur->right;               // 右
                }
            }
            return result;
        }
        vector<int> postorderTraversal(TreeNode* root) {
            stack<TreeNode*> st;
            vector<int> result;
            if (root == NULL) return result;
            st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();                       // 中
                st.pop();
                result.push_back(node->val);
                if (node->left) st.push(node->left);             // 左（空节点不入栈）
                if (node->right) st.push(node->right);           // 右（空节点不入栈）
            }
            reverse(result.begin(), result.end());
            return result;
        }
};

int main(){
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = construct_binary_tree(vec);
    
    Solution solution;
    vector<int> res = solution.preorderTraversal(root);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;

}