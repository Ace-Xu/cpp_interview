#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x=0, ListNode* nxt = nullptr): val(x), next(nxt) {}
};
ListNode* reverse(ListNode* head){
	ListNode* pre = nullptr;
	ListNode* cur = head;
	while(cur){
		ListNode* temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

int main() {
	int n;
	cin >> n;	//输入n的大小
			//
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	for(int i=0; i<n; i++){
		int val ;
		cin >> val;	//创造节点
		ListNode* newNode = new ListNode(val);
		if(i==0){
			head = newNode;
			tail = newNode;
		}else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	//构造完毕
	ListNode* ans = reverse(head);

	while(ans){
		cout<<ans->val<<" " ;
		ListNode* temp = ans;
		ans = ans->next;
		delete temp;
	}	
	return 0;
}
