/*
题目：实验室每周开组会，有一个讲论文环节，讲论文人数1~2人不等，这学期总共有19周
研一有2人，研二有3人，研三有5人，博士有2人，分别对应id 1~12 .
要求每个博士生讲4次，研二学生讲3次，研一和研三学生讲1次。请问有哪些安排方式
请编写c++代码解决以上问题
*/
#include <iostream>
#include <vector>

using namespace std;

enum StudentType {
    Y1, // 研一
    Y2, // 研二
    Y3, // 研三
    PhD // 博士
};

const int NUM_STUDENTS = 12;
const int NUM_WEEKS = 19;

int arrangements[NUM_WEEKS]; // 记录每周的安排
vector<vector<int>> validArrangements;

bool isValid() {
    int countY1 = 0, countY2 = 0, countY3 = 0, countPhD = 0;
    for (int i = 0; i < NUM_WEEKS; ++i) {
        switch (arrangements[i]) {
            case Y1: countY1++; break;
            case Y2: countY2++; break;
            case Y3: countY3++; break;
            case PhD: countPhD++; break;
        }
    }
    return (countY1 == 1 && countY2 == 3 && countY3 == 5 && countPhD == 2);
}

void generateArrangements(int week) {
    if (week == NUM_WEEKS) {
        if (isValid()) {
            vector<int> validArrangement(arrangements, arrangements + NUM_WEEKS);
            validArrangements.push_back(validArrangement);
        }
        return;
    }

    for (int student = Y1; student <= PhD; ++student) {
        if (week >= 4 && student == PhD) continue; // 博士生讲4次的限制
        if (week >= 7 && student == Y2) continue; // 研二学生讲3次的限制
        if (week >= 12 && (student == Y1 || student == Y3)) continue; // 研一和研三学生讲1次的限制

        arrangements[week] = student;
        generateArrangements(week + 1);
    }
}

int main() {
    for (int i = 0; i < NUM_WEEKS; ++i) {
        arrangements[i] = -1;
    }

    generateArrangements(0);

    for (const vector<int>& arrangement : validArrangements) {
        for (int i = 0; i < NUM_WEEKS; ++i) {
            cout << "Week " << i + 1 << ": 学生" << arrangement[i] + 1 << " 讲论文\t";
        }
        cout << endl;
    }

    return 0;
}
