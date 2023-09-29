#include <vector>
#include <algorithm>
#include <iostream>

#define INT_MAX 50001
using namespace std;

int minTotalWorkHours(vector<vector<int>>& tasks, int n) {
    int m = tasks.size(); // 项目数量
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

    // 初始化边界条件
    dp[0][0] = 0;

    for (int i = 1; i <= m; ++i) {
        int totalWorkHours = 0; // 当前项目总工时
        for (int j = 0; j < tasks[i-1].size(); ++j) {
            totalWorkHours += tasks[i-1][j];
        }
        
        for (int k = 1; k <= n; ++k) {
            for (int j = 0; j <= tasks[i-1].size(); ++j) {
                if (j <= k) {
                    dp[i][k] = min(dp[i][k], max(dp[i-1][k-j], totalWorkHours));
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<vector<int>> tasks = {{2, 3, 1}, {1,2,6,2}, {3,2}};
    int n = 2; // 员工数量
    int result = minTotalWorkHours(tasks, n);
    cout << "最小工作时长总和: " << result << endl;
    return 0;
}
