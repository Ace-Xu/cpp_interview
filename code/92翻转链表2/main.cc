#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x = 0, ListNode* nxt = nullptr): val(x), next(nxt){}
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

ListNode* reverseBtween(ListNode* head, int left, int right){
	ListNode* dummyNode = new ListNode(-1);
	dummyNode->next = head;

	//1.找到left的左边
	ListNode* preNode = dummyNode;
	for(int i=1; i<left; i++){
		preNode = preNode->next;
	}	
	ListNode* leftNode = preNode->next;
	preNode->next = nullptr;//切断左边
	
	//2.找到right 和right的右边
	ListNode* rightNode = leftNode;
	for(int i=left; i<right; i++){
		rightNode = rightNode->next;
	}
	ListNode* tail = rightNode->next;

	//3.切断
	preNode->next = nullptr;
	rightNode->next = nullptr;

	//4.翻转
	reverse(leftNode);	//不用管返回值?
	
	//5.拼接
	preNode->next = rightNode;
	leftNode->next = tail;

	//6.内存管理
	delete dummyNode;
	return head;
}

ListNode* create(int n){
	
	//创建n个节点
	if(n<=0) return nullptr;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;

	cout<<"input values \n";
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
	int size;
	cout<<"input size : \n" ;
	cin >> size;

	ListNode* head = create(size);

	cout<< "input left right \n";
	int left, right;
	cin >> left >> right;
	ListNode* ans = reverseBtween(head, left, right);
	while(ans){
		cout<< ans->val <<" " ;
		ListNode* temp = ans;
		ans = ans->next;
		delete temp;
	}

	return 0;
}

#define SQR(X) X*X
void fun(void){
	int a=0;
	int b=2;
	int c=1;
	a = SQR(b+c)/SQR(b+c);
	printf("%d\n", a);
	return 0;
}

const int WIDTH = 5;
const int HEIGHT = 3; 下列正确的是：
A void foo(int arr[HEIGHT][WIDTH]);
B void foo(int arr[][WIDTH]);
C void foo(int arr[][])
D void foo(int arr[HEIGHT][]):

22.属于RuntimeException的有哪些？   ABC
A ClassCastException
B NullPointerException
C ArraylndexOutOfBoundsException
D IOException

21.已知如下程序片段，下面选项说法正确的是: AD
public static void main(String[] args){
	Integer a[] = new Integer[2];
	int b[] = new int[2]:
	System.outprintln(a.length):
	System.out.println(b):
	System.out.println(a[0]):
	System.out.printIn(b[0]):
}
A 第一行输出为2 ；
B 第二行输出为[0,0];
C 第三行输出为0；
D 第四行输出为0；

20 已知存在Test类如下   BD
	public class Test {
		private int i = 0;
		public void add(){

			i++;
		}
		// ...
	}
	调用add 方法100次， 如果要保证最终i的值为100，以下说法正确的是：
A 保证程序在单线程中执行即可
B 给add方法添加synchronized修符
C 给变量i增加volatile修饰符
D 将变量改成Atomicinteger类型，并将add方法的方法体改为i.set(i.get()+1);

19 以下方法属于Object类的有: ACD
A clone
B sleep
C finalize
D notify

18 已知如下字符串定义,String s1 ="123";String s2 = "123";String s3 = new String("123");
下面表达式为true的有： ACD
A s1==s2
B s1==s3
C s1.equals(s2)
D s1.equals(s3)

17 Linux中文件的权限为d-rwxrw-r--,以下描述中正确的是  AD
A 该文件类型是目录
B 文件的所属组成员的权限为可读、可写，可以通过cd命令进入目录
C 文件所有者权限为可读、可写和可执行
D 文件的非本组成员的权限为只读
