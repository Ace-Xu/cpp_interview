/*
第1行输入节点数 n
第2行输入节点里的数字
输翻转后的节点
*/
#include <iostream>
const int N = 100;
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* next = nullptr):val(x), next(next){}
};

// ListNode* reverse(ListNode* head) {
//     ListNode* pre = head;
//     ListNode* cur = head->next;
//     ListNode* temp;
//     while(cur){
//         temp = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = temp;
//     }
//     head->next = nullptr;
//     return head;
// }

ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* temp;
    while (cur) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre; // 返回新的链表头
}

int main() {
    int n = 0;
    cin >> n;
    if(n<=0)return 0;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if(i==0) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    ListNode* ans = reverse(head);
    while(ans){
        cout << ans->val << " " ;
        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
    }
    return 0;
}