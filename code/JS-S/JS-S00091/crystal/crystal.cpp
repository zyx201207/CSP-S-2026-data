#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], sum[N], ans = 1;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, mid, maxl;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (a[i] * mid - (sum[i] - sum[i - mid]) <= m) {
                maxl = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        ans = max(ans, maxl);
    }
    cout << ans << '\n';
    return 0;
}