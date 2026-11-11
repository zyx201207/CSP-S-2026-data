#include<bits/stdc++.h>
#define int long long
#define lb(x) (x & -x)
using namespace std;
const int N = 2e6 + 10;
int n, d, x[N];
int lsh[N];
void init() {
    for (int i = 1; i <= n; ++i) {
        lsh[i] = x[i] = 0;
    }
}
int get(int id) {
    return lsh[x[id]];
}
int tr[N];
void upd(int x, int k) {
    for (int i = x; i <= n; i += lb(i)) {
        tr[i] += k;
    }
}
int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lb(i)) {
        ans += tr[i];
    }
    return ans;
}
void solve() {
    cin >> n >> d;
    // init();
    // int fl = 0;
    // for (int i = 1; i <= n; ++i) {
    //     cin >> x[i];
    //     lsh[i] = x[i];
    // }
    // sort(lsh + 1, lsh + n + 1);
    // int m = unique(lsh + 1, lsh + n + 1) - lsh - 1;
    // for (int i = 1; i <= n; ++i) {
    //     x[i] = lower_bound(lsh + 1, lsh + m + 1, x[i]) - lsh;
    //     upd(x[i], 1);
    // }
    cout << n << '\n';
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int C, T;
    cin >> C >> T;
    while (T--) {
        solve();
    }
}
