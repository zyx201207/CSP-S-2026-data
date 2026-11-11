#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[500010], sum[500010];

bool check(int x) {
    for (int i = x; i <= n; i++) {
        if ((a[i] * (x - 1) - (sum[i - 1] - sum[i - x])) <= m)
            return true;
    }
    return false;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}