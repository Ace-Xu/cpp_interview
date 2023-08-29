#include <vector>
#include <iostream>
#include <stack>
#include <unordered_set>

//先写一个快排

int get_pivot(std::vector<int> &vec, int left, int right){
    
    int flag = vec[left];

    while(left<right) {
        while(left<right && vec[right]>=flag) {
            right--;
        }
        vec[left] = vec[right];
        while(left<right && vec[left]<=flag) {
            left++;
        }
        vec[right] = vec[left];
    }
    vec[left] = flag;
    return left;
}

void quick_sort(std::vector<int> &vec, int left, int right) {
    if(left>=right) {
        return ;
    }
    int pivot = get_pivot(vec, left, right);
    quick_sort(vec, left, pivot-1);
    quick_sort(vec, pivot+1, right);
}

//写个二叉树
struct BNode
{
    uint32_t value;
    BNode* lchild;
    BNode* rchild;
    BNode(int v):value(v), lchild(nullptr), rchild(nullptr) {}
};

//写一个构造二叉树的函数 ,返回一个根节点.  构造多少个节点由传入数组大小决定. 
BNode* create_Btree(const std::vector<int>& node, int index = 0) {
    int len = node.size();  //每一次调用都要计算，感觉可以优化一下
    if(len == 0 ){return nullptr;}
    //
    if(node[index] == 0) {return nullptr;}
    BNode* bn = new BNode(node[index]);
    int lchild = 2*index +1;
    int rchild = 2*index +2;
    if(lchild < len-1) {
        bn->lchild = create_Btree(node, lchild);
    }
    else {
        bn->lchild = nullptr;
    }
    if(rchild < len-1) {
        bn->rchild = create_Btree(node, rchild);
    }else {
        bn->rchild = nullptr;
    }
    return bn;
}

//后续遍历用递推实现 unordered_set --> 存放不重复的值， 底层hash，查找很快
void back_traverse3(/*const*/ BNode& root) {
    std::stack<BNode*> st;          //存放没有遍历过的节点
    std::unordered_set<BNode*> set; //存放是否遍历过
    //BNode* cur = const_cast<BNode*>(&root); //如果传参没有const ，那么直接 BNode* cur = &root;
    BNode* cur = &root;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->lchild;
        }
        if(!st.empty()){
            cur = st.top();
            st.pop();       //正在遍历cur的右边
            if(set.find(cur) == set.end()){     //cur没有遍历过右边
                st.push(cur);
                set.insert(cur);
                cur = cur->rchild;
            }else {
                std::cout<<"val = " <<cur->value << "\n";
                cur = nullptr;
            }
        }   
    }
}

void back_traverse_recurrence(BNode& root){
    if(!root) { return ; }
    std::stack<BNode*> st;
    std::unordered_set<BNode*> res;
    BNode* cur = &root;
    while(cur || !st.empty()) {
        while(cur) {
            st.push(cur);
            cur = cur->lchild;
        }
        if(!st.empty()){
            cur = st.top();
            st.pop();
            if(res.find(cur) == res.end()) {
                st.push(cur);
                res.insert(cur);
                cur = cur->rchild;
            }else {
                std::cout<<"value = " <<cur->value << "\n";
                cur = nullptr;
            }
        }
    }
}

void mid_traverse_recurrence(BNode* root) {     //左 根 右
    if(!root) { return ;}
    std::stack<BNode*> st;
    BNode* cur = root;
    while(cur || !st.empty()) {
        while(cur) {
            st.push(cur);
            cur = cur->lchild;
        }   //当前的左子为空，相当于已经遍历过左，那么遍历cur，再遍历cur->rchild
        if(!st.empty()) {
            cur = st.top();
            std::cout << "value = " << cur->value << "\n";
            st.pop();
            cur = cur->rchild;
        }
    }
}

void pre_traverse_recurrence(BNode* root) {     //根 左  右
    if(!root){ return ;}
    std::stack<BNode*> st;
    BNode* cur = root;
    while(cur || !st.empty()) {
        while(cur) {
            std::cout<<"value = " <<cur->value <<"\n";
            st.push(cur);
            cur = cur->lchild;
        }       //栈的最顶端，是当前已经遍历的最深的左子树
        if(!st.empty()) {
            cur = st.top()->rchild;
            st.pop();
        }
    }
}

