#include <iostream>
#include <vector>
#include <queue>
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
        //先序遍历
        void traversal(TreeNode* cur, vector<int>& vec){
            if(cur == NULL) {
                vec.push_back(-1);
                return;
            }
            vec.push_back(cur->val);
            traversal(cur->left, vec);
            traversal(cur->right, vec);
        }
        //中序遍历
        // void traversal(TreeNode* cur, vector<int>& vec){
        //     if(cur == NULL) return;
        //     traversal(cur->left, vec);
        //     vec.push_back(cur->val);
        //     traversal(cur->right, vec);
        // }
        //后序遍历
        // void traversal(TreeNode* cur, vector<int>& vec){
        //     if(cur == NULL) return;
        //     traversal(cur->left, vec);
        //     traversal(cur->right, vec);
        //     vec.push_back(cur->val);
        // }
        vector<int> preorderTraversal(TreeNode* root){
            vector<int> result;
            traversal(root, result);
            return result;
        }
};

void print_binary_tree(TreeNode* root){
    queue<TreeNode*> que;
    if(root != NULL) que.push(root);
    vector<vector<int>> result;
    while(!que.empty()){
        vector<int> vec;
        int size = que.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            if(node != NULL){
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }else{
                vec.push_back(-1);
            }
        }
        result.push_back(vec);
    }
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = construct_binary_tree(vec);
    
    Solution solution;
    vector<int> res;
    solution.traversal(root, res);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    print_binary_tree(root);

    return 0;

}