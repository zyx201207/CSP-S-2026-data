// Arknighs Endfield
// rossi i love you

#include <bits/stdc++.h>
using namespace std;

#define range(v, l, r) next(begin(v), l), next(begin(v), r+1)
#define range_full(v) begin(v), end(v)

int64_t n, m;
array<int64_t, size_t(5e5+5)> c;
array<int64_t, size_t(5e5+5)> u;
array<int64_t, size_t(5e5+5)> p;

int64_t calc(int64_t l, int64_t r) {
    return u[r]-u[l]-(l-1)*(c[r]-c[l]);
}

int32_t main() {
    ignore = freopen("crystal.in", "r", stdin);
    ignore = freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int64_t i=1; i<=n; i++) {
        cin >> c[i];
    }
    sort(range(c, 1, n));
    for (int64_t i=2; i<=n; i++) {
        if (c[i] == c[i-1]) {
            u[i] = u[i-1];
        }
        else {
            u[i] = u[i-1]+(c[i]-c[i-1])*(i-1);
        }
    }
    // partial_sum(range(c, 1, n), next(begin(p)));
    // int64_t l{-1e18}, r{1e18};
    // int64_t ans{};
    // while (l <= r) {
    //     int64_t mid = l+((r-l)>>1);

    // }

    int64_t ans{};
    int64_t l = 1, r = 1;
    while (r <= n) {
        while (r+1 <= n && calc(l, r+1) <= m) {
            ++r;
        }
        if (r+1 > n) {
            break;
        }
        ans = max(ans, r-l+1);
        ++l;
    }
    cout << ans;


    return 0;
}