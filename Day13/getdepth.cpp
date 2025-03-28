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
        int getdepth(TreeNode* node){
            if(node == NULL) return 0;
            int leftdepth = getdepth(node->left);
            int rightdepth = getdepth(node->right);
            int depth = 1 + max(leftdepth, rightdepth);
            return depth;
        }
        //最小深度
        int getDepth(TreeNode* node){
            if(node == NULL) return 0;
            int leftDepth = getDepth(node->left);
            int rightDepth = getDepth(node->right);
            if(node->left == NULL && node->right != NULL){
                return 1+ rightDepth;
            }
            if(node->left != NULL && node->right == NULL){
                return 1+ leftDepth;
            }
            return (1 + min(leftDepth, rightDepth));
        }
};

int main(){
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = construct_binary_tree(vec);
    
    Solution solution;
    int depth = solution.getdepth(root);

    cout << depth << endl;

    return 0;

}