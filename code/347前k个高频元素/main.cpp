// //😁😁👍✌👀
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// //重载 () 运算符 
// class myComperation {
// public:
//     bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) {
//         return lhs.second > rhs.second;
//     }
// };
// vector<int>  topKFrequent(vector<int>& nums, int k) {
//     unordered_map<int, int>mp;
//     for(int i=0; i<nums.size(); ++i){
//         mp[nums[i]]++;
//     }

//     priority_queue<pair<int,int>, vector<pair<int, int> >, myComperation> pri_que;

//     for(auto it : mp){
//         pri_que.push(it);
//         if(pri_que.size() > k) pri_que.pop();
//     }
//     vector<int>result(k);
//     for(int i=k-1; i>=0; --i){
//         result[i] = pri_que.top().first;
//         pri_que.pop();
//     }
//     return result;
// }

// int main() {
//     int temp;
//     int k;
//     cout<<"k = :\n" ;
//     cin>>k;
//     vector<int>input;
//     while(cin>>temp){
//         input.push_back(k);
//     }
//     vector<int> res = topKFrequent(input, k);
//     for(auto it:res){
//         cout<<it<<"\t";
//     }
//     return 0;
// }
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// 重载 () 运算符
class myComparison {
public:
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    //构建哈希map
    for (int i = 0; i < nums.size(); ++i) {
        mp[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;
    //构建大小为k的小根堆(把小的都移动到堆顶，然后放到最后，遍历完所有的，堆里剩下k个最大的)
    for (auto it : mp) {
        pri_que.push(it);
        if (pri_que.size() > k) pri_que.pop();
    }

    //
    vector<int> result(k);
    for (int i = k - 1; i >= 0; --i) {
        result[i] = pri_que.top().first;
        pri_que.pop();
    }
    return result;
}

int main() {
    int n; // 输入的数字数量
    int k; // 前 k 个频率最高的数字
    cout << "请输入 k 值: ";
    cin >> k;

    cout << "请输入数字数量: ";
    cin >> n;
    
    vector<int> input(n);
    cout << "请输入 " << n << " 个数字:\n";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    vector<int> res = topKFrequent(input, k);
    cout << "前 " << k << " 个频率最高的数字是: ";
    for (auto it : res) {
        cout << it << "\t";
    }
    return 0;
}
