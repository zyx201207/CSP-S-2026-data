#include <bits/stdc++.h>
#define int long long
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) ^ 1)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int task, n, m, d, q, w[500005], a[500005], t[500005], e[505][505];
vector<pii> g[500005];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> task >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        int cnt; cin >> cnt;
        for (int j = 1; j <= cnt; j++){
            cin >> a[j] >> t[j];
            g[a[j]].push_back({i, t[j]});
        }
    }
    memset(e, 0x3f, sizeof(e));
    for (int i = 1; i <= n; i++) e[i][i] = 0;
    for (int i = 1; i <= m; i++){
        for (pii u: g[i]) for (pii v: g[i]){
            if (u.first == v.first) continue;
            e[u.first][v.first] = e[v.first][u.first] = min(e[u.first][v.first], u.second + v.second);
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
            if (i == j || j == k || i == k) continue;
            e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
        }
    }
    while (q--){
        int u, v; cin >> u >> v;
        int ans = 1e18;
        for (pii i: g[u]) for (pii j: g[v]){
            ans = min(ans, e[i.first][j.first] + w[u] + i.second + w[v] + j.second);
        }
        cout << ans << "\n";
    }
    return 0;
}
