#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500100;
int n, m;
int a[N];
signed main() {
    freopen("and.in", "a+", stdin);
    freopen("and.out", "w+", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int pre = 0;
    for (int bit = 30; bit >= 0; bit--) {
        int t = (1 << bit) | pre;
        int has = 0;
        for (int j = 1; j <= n; ++j) {
            if ((t & a[j]) == t) {
                has++;
            }
        }
        if (has >= m) {
            pre |= (1 << bit);
        }
    }
    cout << pre << "\n";
}