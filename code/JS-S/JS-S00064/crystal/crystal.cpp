#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int m;
const int N = 500010;
int a[N];
int pre[N];
signed main() {
    freopen("crystal.in", "a+",stdin);
    freopen("crystal.out", "w+", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (mid * a[i] - (pre[i] - pre[i - mid]) <= m) {
                l = mid;
            } else r = mid - 1;
        }
        ans = max(ans, l);
    }
    cout << ans << "\n";
    return 0;
}