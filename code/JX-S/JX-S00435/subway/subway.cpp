#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
using pi = pair<int, int>;
const int N = 505, M = 5e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll n, m, MXD, q;
ll dp[N][N], QW[M];
vector<pi> bel[M];

void upd(ll &x, ll val) {
    x = min(x, val);
}

void Floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                upd(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

void solve(int x, int y) {
    ll ans = inf;
    for(auto xu : bel[x]) {
        for(auto yu : bel[y]) {
            ll res = xu.se + yu.se;
            res += dp[xu.fi][yu.fi];
            upd(ans, res);
        }
    }
    ans += QW[x] + QW[y];
    cout << ans << "\n";
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cid; cin >> cid;
    cin >> n >> m >> MXD >> q;
    for(int i = 1; i <= m; i++) cin >> QW[i];
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int id, t; cin >> id >> t;
            bel[id].push_back({i, t});
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int id = 1; id <= m; id++) {
        int d = bel[id].size();
        for(int i = 0; i < d; i++) {
            for(int j = i + 1; j < d; j++) {
                int u = bel[id][i].fi, v = bel[id][j].fi;
                ll cst = bel[id][i].se + bel[id][j].se;
                upd(dp[u][v], cst);
                upd(dp[v][u], cst);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    Floyd();
    while(q--) {
        int x, y; cin >> x >> y;
        solve(x, y);
    }
    return 0;
}