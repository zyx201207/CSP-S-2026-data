#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
int n, ans;
ll m;
ll a[N], sum[N];
bool check (int len) {
    for (int l = 1; l <= n - len + 1; l++) {
        int r = l + len - 1;
        ll c = 1ll * a[r] * len - sum[r] + sum[l - 1];
        if (c <= m) return 1;
    }
    return 0;
}
int main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check (mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
