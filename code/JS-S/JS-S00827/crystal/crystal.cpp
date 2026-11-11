#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005];
bool check(int x) {
    int res = 0;
    for (int i=1;i<x;i++) res += a[x-1]-a[i];
    for (int i=x;i<=n;i++) {
        res += (x-1)*(a[i]-a[i-1]);
        if (res <= m) return 1;
        res -= a[i]-a[i-x+1];
    }
    return 0;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = n, res = 1;
    while (l <= r) {
        int mid = l+r >> 1;
        if (check(mid)) res = mid, l = mid+1;
        else r = mid-1;
    }
    cout << res << "\n";
    return 0;
}