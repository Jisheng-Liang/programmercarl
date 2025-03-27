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
        ListNode* intersectnode(ListNode* head1, ListNode* head2) {
            ListNode* curA = head1;
            ListNode* curB = head2;
            int lenA = 0, lenB = 0;
            while (curA != NULL){
                lenA++;
                curA = curA->next;
            }
            while (curB != NULL) { // 求链表B的长度
                lenB++;
                curB = curB->next;
            }
            curA = head1;
            curB = head2;

            if(lenB > lenA){
                swap(lenA, lenB);
                swap(curA, curB);
            }
            int gap = lenA - lenB;
            while(gap--){
                curA = curA->next;
            }
            while (curA != NULL) {
                if (curA == curB) {
                    return curA;
                }
                curA = curA->next;
                curB = curB->next;
            }
            return NULL;
        }
};

int main() {
    int intersectVal = 2;
    int arr1[] = {0,9,1,2,4};
    int arr2[] = {3,2,4};
    int skipA = 3;
    int skipB = 1;

    ListNode* head1 = new ListNode(arr1[0]);
    ListNode* ptr = head1; //创建指向head的ptr, 对ptr操作
    for(int i = 1; i < sizeof(arr1)/sizeof(arr1[0]); i++){
        ptr->next = new ListNode(arr1[i]);
        ptr = ptr->next;
    }

    ListNode* head2 = new ListNode(arr2[0]);
    ListNode* ptr2 = head2; //创建指向head的ptr, 对ptr操作
    for(int i = 1; i < sizeof(arr2)/sizeof(arr2[0]); i++){
        ptr2->next = new ListNode(arr2[i]);
        ptr2 = ptr2->next;
    }

    Solution solution;
    ListNode* result = solution.intersectnode(head1, head2);
    if (result != NULL){
        return result->val;
    }
    return 0;
}