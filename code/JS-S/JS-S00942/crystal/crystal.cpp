#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], sum[500005];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, ans2 = i;
        while (l <= r) {
            int mid = l + r >> 1;
            int res = (i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]);
            if (res <= m) {
                ans2 = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, i - ans2 + 1);
    }
    cout << ans;
    return 0;
}