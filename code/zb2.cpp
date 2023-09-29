#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int maxZeros = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            maxZeros = max(maxZeros, n - i);
        } else {
            double mul = -b[i] / static_cast<double>(a[i]);
            vector<double> c(n);

            for (int j = 0; j < n; ++j) {
                c[j] = mul * a[j] + b[j];
            }

            sort(c.begin(), c.end());

            int zeros = 0;
            for (int j = 0; j < n; ++j) {
                if (c[j] == 0) {
                    zeros = n - j;
                    break;
                }
            }

            maxZeros = max(maxZeros, zeros);
        }
    }

    cout << maxZeros << endl;

    return 0;
}
