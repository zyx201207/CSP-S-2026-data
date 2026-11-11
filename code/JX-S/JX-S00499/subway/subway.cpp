#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 505, M = 5e5 + 5;
int n, m, d, q;
ll w[N], sk[N], f[N];
struct node {
    int x; ll t;
}ln[M];
int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        sk[i] = sk[i - 1] + k;
        for (int j = sk[i - 1] + 1; j <= sk[i]; j++) {
            cin >> ln[j].x >> ln[j].t;
        }
    }
    while (q--) {
        int u, v; cin >> u >> v;
        fill(f + 1, f + m + 1, 1e18);
        f[u] = w[u];
        for (int i = 1; i <= n; i++) {
            ll mn = 1e18;
            for (int j = sk[i - 1] + 1; j <= sk[i]; j++) {
                int x = ln[j].x; ll t = ln[j].t;
                f[x] = min(f[x], mn + t);
                mn = min(mn, f[x] + t);
            }
        }
        cout << f[v] + w[v] << endl;
    }
    return 0;
}