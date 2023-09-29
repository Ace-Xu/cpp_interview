// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 10010;

// int n, q, ne[N];
// char s[N], p[N];

// int main() {
//     memset(p, '\0', sizeof p);
//     cin >> n >>q >> p+1;
//     for(int i = 2, j = 0; i <= n; ++i){
//         while(j && p[i] != p[j+1]) j = ne[j];
//         if(p[i] == p[j+1]) j++;
//         ne[i] = j;
//     }
//     while(q--) {
//         int res = 0;
//         memset(s, '\0', sizeof s);
//         cin >> s+1;
//         for( int i = 1, j = 0; s[i] != '\0'; ++i) {
//             while(j && s[i] != p[j +1]) j = ne[j];
//             if (s[i] = p[j + 1])j++;
//             if(s[j] == '\0'){
//                 res++;
//                 j = ne[j];
//             }
//         }
//         cout << res << endl;
//     }
// }
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100005; // 设置字符串最大长度

char S[MAX_N]; // 原始字符串
char p[MAX_N]; // 待匹配字符串
int ne[MAX_N]; // next数组

int main() {
    int n;
    cin >> n; // 输入原始字符串S的长度


    int m;
    cin >> m; // 输入待匹配字符串的数量

    cin >> (S + 1); // 输入原始字符串S
    
    while (m--) {
        cin >> (p + 1); // 输入待匹配的字符串
        int m_len = strlen(p + 1); // 计算待匹配字符串的长度

        // KMP算法构建next数组
        for (int i = 2, j = 0; i <= m_len; ++i) {
            while (j && p[i] != p[j + 1]) j = ne[j];
            if (p[i] == p[j + 1]) j++;
            ne[i] = j;
        }

        int res = 0;
        int j = 0;
        int n_len = strlen(S + 1); // 原始字符串S的长度
        for (int i = 1; i <= n_len; ++i) {
            while (j && S[i] != p[j + 1]) j = ne[j];
            if (S[i] == p[j + 1]) j++;
            if (j == m_len) {
                res++;
                j = ne[j];
            }
        }
        cout << res << endl;
    }

    return 0;
}
