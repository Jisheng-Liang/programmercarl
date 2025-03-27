#include <iostream>
#include <vector>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            ListNode* dummyhead = new ListNode(0);
            dummyhead->next = head;
            ListNode* tmp = dummyhead;
            while(tmp->next != NULL && tmp->next->next != NULL){
                ListNode* node1 = tmp->next;
                ListNode* node2 = tmp->next->next->next;

                tmp->next = tmp->next->next;
                tmp->next->next = node1;
                tmp->next->next->next = node2;

                tmp = tmp->next->next;                
            }
            ListNode* res = dummyhead->next;
            delete dummyhead;
            return res;
        }
};

int main() {
    vector<int> nums = {1,2,3,4};
    ListNode* head = new ListNode(nums[0]);
    ListNode* ptr = head; //创建指向head的ptr, 对ptr操作
    for(int i = 1; i < nums.size(); i++){
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }

    Solution solution;
    ListNode *result = solution.swapPairs(head);
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    
    cout << endl;
    return 0;
}