#include <bits/stdc++.h>
#define ONLINE(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
#define int long long
using namespace std;

namespace sub1_2 {
    int n, d;
    vector<int> a;

    inline int get_nxt(int u, int x) {
        int lim = a[u] + x;
        auto it = lower_bound(a.begin() + 1 + u, a.end(), lim);
        if (it == a.end()) return -1;
        if (*it > lim) it--;
        int v = it - a.begin();
        if (u == v) return -1;
        return v;
    }

    int cnt = 0, mn = -1;
    void dfs(int u, int ed, int step) {
        if (u == ed) {
            if (mn == -1) mn = step;
            if (mn == step) cnt++;
            return;
        }

        if (cnt > 2) return;
        if (mn != -1 && step >= mn) return;
        if (mn != -1 && (a[ed] - a[u] + d - 1) / d > mn - step) return;

        for (int i = min(d, a[ed] - a[u]); i >= 1; i--) {
            int v = get_nxt(u, i);
            if (v == -1) return;
//            cout << u << "->" << v << endl;
            dfs(v, ed, step + 1);
            i = a[v] - a[u];
            if (cnt > 2) return;
        }
    }

    inline void solve() {
        cin >> n >> d;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        if (d == 0) {
            cout << 0 << "\n";
            return;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cnt = 0, mn = -1;
//                cout << "dfs " << i << " " << j << endl;
                dfs(i, j, 0);
                if (cnt == 2) ans++;
            }
        }
        cout << ans << "\n";
//        cout << ans << endl;
    }
}

namespace sub11_12 {
    int n, d;
    vector<int> a;

    inline void solve() {
        cin >> n >> d;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        if (d == 1) cout << 0 << "\n";
        else cout << max(0LL, n - (2 * d - 1)) << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ONLINE(migrate);
    int c, t;
    cin >> c >> t;
    while (t--) {
        if (c == 11 || c == 12) sub11_12::solve();
        else sub1_2::solve();
    }
    return 0;
}
