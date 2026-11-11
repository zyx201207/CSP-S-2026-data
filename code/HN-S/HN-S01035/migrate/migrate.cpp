#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MaxN = 2e6 + 5;

int ca, T, n, nex[MaxN], w[MaxN], down[MaxN];
long long d, x[MaxN], ans, f[MaxN], a[MaxN], b[MaxN], c[MaxN];
vector<int> g[MaxN];

void Dfs(int u) {
    for (int v : g[u]) {
        Dfs(v);
        if (w[v] == 0) {
            down[u] += down[v];
        }
    }
    down[u]++;
}

void Clear() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        down[i] = b[i] = c[i] = f[i] = 0;
    }
    ans = 0;
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    // freopen("migrate3.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    for (cin >> ca >> T; T; T--, Clear()) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            // cout << 1. * (x[i] - x[1]) / d << ' ';
        }
        x[n + 1] = 6e18;
        for (int i = 1; i <= n; i++) {
            nex[i] = nex[i - 1];
            while (nex[i] <= n && x[nex[i] + 1] - x[i] <= d) nex[i]++;
            if (nex[i] != i) g[nex[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            a[i] = b[i] = c[i] = -4e18;
            int ni = nex[i], nni = nex[ni];
            w[i] = 0;
            a[i] = x[nex[i]];
            if (i != ni && ni != nni) {
                int cnt = 0;
                if (i < ni - 1) cnt += x[nni] - (b[i] = x[ni - 1]) <= d;
                if (i < ni - 2) cnt += x[nni] - (c[i] = x[ni - 2]) <= d;
                w[i] = cnt;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << w[i] << ' ';
        // }
        // cout << '\n';
        for (int i = 1; i <= n; i++) {
            if (nex[i] == i) {
                Dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (w[i] == 1) {
                assert(i != nex[i]);
                int j = nex[i];
                if (w[j] != 0) continue;
                while (j != nex[j]) {
                    j = nex[j];
                    f[j] += down[i];
                    if (w[j] != 0) break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (j != nex[j] && a[j] < x[i] && b[j] >= x[i] - d && c[j] < x[i] - d) {
                    ans += down[j];
                    // if (down[j]) {
                    //     cout << i << ' ' << j << ' ' << b[j] << ' ' << a[j] << ' ' << down[j] << '\n';
                    // }
                }
                if (j != nex[j] && a[j] >= x[i] && x[j] >= x[i] - d && x[j] < x[i]) {
                    // if (a[j] != x[i] || x[j] != x[i] - d)
                    ans += f[j];
                    // if (a[j] == x[i] && x[j] == x[i] - d) {
                    //     cout << a[j] << ' ' << b[j] << ' ' << c[j] << '\n';
                    // }
                    // if (f[j]) {
                    //     cout << i << ' ' << j << ' ' << b[j] << ' ' << a[j] << ' ' << f[j] << "!\n";
                    // }
                }
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << up[i] << ' ' << down[i] << '\n';
        // }
        cout << ans << '\n';
    }
    return 0;
}
/*
0 1
6 12
-10 -6 -2 2 6 10

0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/