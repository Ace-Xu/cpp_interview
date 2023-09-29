#include <iostream>
#include <vector>
#include <vector>

using namespace std;
std::string input_str;
std::string path;
std::vector<std::string> res;

void backtracing(const string& str, vector<bool>& used){
    if(path.size() == str.size()){
        res.push_back(path);
        return;
    }
    for(int i=0 ; i<str.size(); ++i){
        if(used[i] == true)continue;
        used[i] = true;
        path.push_back(str[i]);
        backtracing(str, used);
        path.pop_back();
        used[i] = false;
    }
}

int main() {
    std::cout<<"输入str:\n";
    std::cin>>input_str;
    path.clear();
    res.clear();
    std::vector<bool>used(input_str.size(), false);
    backtracing(input_str, used);
    for(auto s:res){
        cout<<s<<"\n";
    }
    return 0;
}

/*回溯算法，以全排列为例，有几点。
1.一个res数组，存放所有可能的结果
2.一个path数组，用于深度优先存储满足条件的结果。切记，需要用它来回溯
3.一个used数组，用来判断当前是否遍历过
4.把整个输入的数组看成一个n叉树，因此整个回溯的函数就很明了：
    首先判断path长度是否满足要求；
    没进入一次回溯函数，相当于进入下一层n叉树，同样有n个子节点，结合uesd数组
    递归之后要回溯，也就是归还path、used数组原来的样子
*/

void bt(vector<int>nums, vector<bool>& used){
    if(path.size() == nums.size()){
        res.push_back(path);
        return ;
    }
    for(int i=0; i<nums.size();++i){
        if(used[i] == true)continue;
        used[i] = true;
        path.push_back(nums[i]);
        bt(nums, used);
        used[i] = false;
        path.pop();
    }
}