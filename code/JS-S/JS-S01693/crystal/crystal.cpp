#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500005];
bool check(int mid) {
    int need = 0;
    for (int i = 1; i < mid; i++) need += a[i];
    for (int i = mid; i <= n; i++) {
        if (a[i] * mid - need < m) return 1;
        need -= a[i - mid + 1];
        need += a[i];
    }
    if (a[n] * mid - need < m) return 1;
    return 0;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l;
}