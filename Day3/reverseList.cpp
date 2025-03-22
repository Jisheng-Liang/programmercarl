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
        ListNode* reverseList(ListNode* head) {
            ListNode* pre = NULL;
            ListNode* cur = head;
            ListNode* temp;
            while(cur){
                temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            delete temp;
            return pre;
        }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = new ListNode(nums[0]);
    ListNode* ptr = head; //创建指向head的ptr, 对ptr操作
    for(int i = 1; i < nums.size(); i++){
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }

    Solution solution;
    int val = 6;
    // 返回一个指向新链表头节点的指针变量 res
    ListNode *res = solution.reverseList(head);

    // 指针变量 res 被不断更新，以指向链表中的每个节点，从而实现对链表的遍历
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next; // 将 res 指向下一个节点
    }
    cout << endl;

    return 0;
}