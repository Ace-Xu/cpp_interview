#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x=0, ListNode* nxt = nullptr): val(x), next(nxt){}
};

ListNode* reverse(ListNode* head) {
	ListNode* pre = nullptr;
	ListNode* cur = head;
	while(cur) {
		ListNode* temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

ListNode* create(int n){
	ListNode* head = nullptr; 
	ListNode* tail = nullptr;

	for(int i=0; i<n; i++){
		int val;
		cin>>val;
		ListNode* newNode = new ListNode(val);
		if(i==0){
			head = newNode;
			tail = newNode;
		}else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	return head;
}

int main(){
	int n;
	cout<<"input n";
	cin >> n;
	ListNode* head = create(n);

	ListNode* ans = reverse(head);

	while(ans){
		cout<<ans->val <<" " ;
		ListNode* temp = ans;	//其实可以再用head当成临时指针，不过这样不便于理解
		ans = ans->next;
		delete temp;
	}
	return 0;
}

