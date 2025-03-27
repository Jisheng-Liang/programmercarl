#include <iostream>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
    public:
        ListNode* removefromend(ListNode* head, int val) {
            ListNode* dummyhead = new ListNode(0);
            dummyhead->next = head;
            ListNode* slow = dummyhead;
            ListNode* fast = dummyhead;
            while(val-- && fast != NULL){
                fast = fast->next;
            }
            fast = fast->next;
            while(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            
            ListNode *tmp = slow->next;
            slow->next = tmp->next;
            delete tmp;

            return dummyhead->next;
        }
};

int main() {
    int nums[] = {1,2,3,4,5};
    ListNode* head = new ListNode(nums[0]);
    ListNode* ptr = head; //创建指向head的ptr, 对ptr操作
    for(int i = 1; i < sizeof(nums)/sizeof(nums[0]); i++){
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }

    Solution solution;
    int val = 2;
    ListNode *result = solution.removefromend(head,val);
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    
    cout << endl;
    return 0;
}