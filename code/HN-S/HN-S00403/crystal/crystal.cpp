#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N];
bool check (int x) {
    int sum = 0;
    for (int i = 1; i <= x; i++) sum += a[x] - a[i];
    if (sum <= m) return 1;
    for (int i = x + 1; i <= n; i++) {
        sum -= a[i - 1] - a[i - x];
        sum += (x - 1) * (a[i] - a[i - 1]);
        if (sum <= m) return 1;
    }
    return 0;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
