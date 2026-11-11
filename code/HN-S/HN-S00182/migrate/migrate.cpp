#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;
int n, L[N], LL[N], R[N], f[N][4];
long long d, a[N];

inline pair<int, int> jump(int o, int i) {
    int j = R[i];
    pair<int, int> res{0, 0};
    if (o == 1)
        if (L[j] == i) res = {min({j - i, j - LL[j] + 1, 2}), 0};
        else res = {0, 0};
    else if (o == 2)
        if (L[j] == i) {
            int x = max(i + 1, LL[j]);
            res.first = min(j - x + 1, 2);
            if (x > i + 1 && L[x - 1] == i - 1) res.second = x - max(i, LL[x - 1]);
        } else if (L[j] == i - 1) res = {3, j - max(i + 1, LL[j]) + 1};
        else res = {0, 0};
    else
        if (L[j] == i) res = {3, j - max(i + 1, LL[j]) + 1};
        else res = {0, 0};
    return res;
}
inline void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        R[i] = max(R[i - 1], i);
        while (R[i] < n && a[R[i] + 1] - a[i] <= d) ++R[i];
    }
    L[n + 1] = n + 1;
    for (int i = n; i >= 1; --i) {
        L[i] = min(L[i + 1], i);
        while (L[i] > 1 && a[i] - a[L[i] - 1] <= d) --L[i];
    }
    for (int i = 1; i <= n; ++i)
        if (L[i] == L[i - 1]) LL[i] = LL[i - 1];
        else LL[i] = i;
    long long ans = 0;
    for (int i = n; i; --i) {
        f[i][0] = f[i][1] = f[i][2] = 0;
        if (i == R[i]) continue;
        for (int o = 1; o <= 3; ++o) {
            auto res = jump(o, i);
            f[i][o - 1] = f[R[i]][res.first - 1] + res.second;
        }
        ans += f[R[i]][min(R[i] - i, 2) - 1];
    }
    cout << ans << '\n';
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    int c, T; cin >> c >> T;
    while (T--) solve();
    return 0;
}