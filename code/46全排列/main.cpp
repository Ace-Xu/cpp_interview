/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。
你可以 按任意顺序 返回答案。
*/
#include <iostream>
#include <vector>

vector<vector<int> > res;
vector<int>path;

void backtracing(vector<int>& nums, vector<bool>& used) {
    if(path.size() == nums.size()){
        res.push_back(path);
        return ;
    }
    for(int i=0; i<nums.size(); ++i){
        if(used[i]==true)continue;
        path.push_back(nums[i]);
        backtracing(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int> > func(vector<int>& nums){
    vector<bool> used(nums.size(), false);
    backtracing(nums, used);
    return res;
}

int main() {

    return 0;
}