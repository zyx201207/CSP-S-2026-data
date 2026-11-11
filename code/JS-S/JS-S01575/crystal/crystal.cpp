#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n; ll m, a[N], s[N];
bool check(int x) {
    int l, r;
    ll now = 0;
    for (l = 1, r = x; r <= n; ++l, ++r) {
        now = a[r] * x - s[r] + s[l - 1];
        if (now <= m) return true;
    }
    return false;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
    return 0;
}
// 100
