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
        ListNode* removeElements(ListNode* head, int val) {
            ListNode* dummyNode = new ListNode(0);
            dummyNode->next = head;
            ListNode* cur = dummyNode;
            while (cur->next != NULL) {
                if (cur->next->val == val) {
                    ListNode *tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                } else {
                    cur = cur->next;
                }
            }
            head = dummyNode->next;
            delete dummyNode;
            return head;
        }
};

int main() {
    vector<int> nums = {1,2,6,3,4,5,6};
    ListNode* head = new ListNode(nums[0]);
    ListNode* ptr = head; //创建指向head的ptr, 对ptr操作
    for(int i = 1; i < nums.size(); i++){
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }

    Solution solution;
    int val = 6;
    // 返回一个指向新链表头节点的指针变量 res
    ListNode *res = solution.removeElements(head, val);

    // 指针变量 res 被不断更新，以指向链表中的每个节点，从而实现对链表的遍历
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next; // 将 res 指向下一个节点
    }
    cout << endl;

    return 0;
}