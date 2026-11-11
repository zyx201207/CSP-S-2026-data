#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500005];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n);

    for (int i = 2; i <= n; i ++) {
        if (m == 0) {
            break;
        }
        if (a[i - 1] != a[i]) {
            if (m - (a[i] - a[i - 1]) * (i - 1) >= 0){
                m = m - (a[i] - a[i - 1]) * (i - 1);
                for (int j = 1; j < i; j ++) {
                    a[j] = a[i];
                }
            }
        }
    }

    int ans = 1;
    int maxn = -0x3f3f3f3f;
    for (int i = 2; i <= n; i ++) {
        if (a[i - 1] == a[i]) {
            ans ++;
        } else {
            maxn = max(maxn, ans);
            ans = 1;
        }
    }
    cout << maxn << "\n";

    return 0;
}