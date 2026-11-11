#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5;

using i64 = int64_t;

i64 a[N], pr[N + 1], n, m;

bool ok(i64 cand) {
    for (int r = cand; r <= n; r++) {
        i64 tot = a[r - 1] * cand - (pr[r] - pr[r - cand]);
        if (tot <= m) return true;
    }
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) pr[i + 1] = pr[i] + a[i];
    i64 l = 1, r = n, ans = -1;
    while (l <= r) {
        i64 mid = (l + r) / 2;
        if (ok(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    assert(ans != -1);
    cout << ans << endl;
}