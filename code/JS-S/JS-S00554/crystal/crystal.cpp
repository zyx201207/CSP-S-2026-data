#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], ans = 1, pre[500005];

bool check(int i, int pos) {
    int s = (pos - i) * a[pos] - (pre[pos - 1] - pre[i - 1]);
    if (s <= m) return true;
    else return false;
}
int mfind(int pos) {
    int l = 0, r = pos;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid, pos)) r = mid;
        else l = mid;
    }
    return r;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int pos = 1; pos <= n; pos++) {
        int cnt = 1;
        cnt = pos - mfind(pos) + 1;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}
