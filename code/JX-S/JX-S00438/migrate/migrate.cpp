#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 10;
int x[N];

bool vis[N];
int res[N];

int c, t;
int n, d;

void Dij(int u, int v, int dep = 0) {
    if (u == v) {
        res[dep]++;
        return;
    }
    vis[u] = true;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        if (abs(x[i] - x[u]) <= d) {
            vis[i] = true;
            Dij(i, v, dep + 1);
            vis[i] = false;
        }
    }
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    long long ans = 0;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                memset(vis, 0, sizeof vis);
                memset(res, 0, sizeof res);
                Dij(i, j);
                int tt = -1;
                for (int i = 1; i <= n; i++) {
                    if (res[i] != 0) {
                        tt = res[i];
                        break;
                    }
                }
                if (tt == 2) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
