#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define sc if(DEBUG) cerr
const bool DEBUG = false;

const int N = 1e6 + 5, inf = 1 << 30;

int n, k;
vector<int> edge[N];

namespace BF {
    int dep[N], f[20][N], flg[N];

    void dfs(int u, int fa) {
        dep[u] = dep[fa] + 1;
        f[0][u] = fa;
        for(int i = 1; i <= 19; ++i) f[i][u] = f[i - 1][f[i - 1][u]];
        for(int v : edge[u]) {
            if(v == fa) continue;
            dfs(v, u);
        }
    }

    int lca(int u, int v) {
        if(dep[u] < dep[v]) swap(u, v);
        for(int i = 19; i >= 0; --i)
            if(dep[f[i][u]] >= dep[v])
                u = f[i][u];
        if(u == v) return u;
        for(int i = 19; i >= 0; --i)
            if(f[i][u] != f[i][v]) {
                u = f[i][u];
                v = f[i][v];
            }
        return f[0][u];
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    void dfs1(int u, int fa, int mask, int type) {
        flg[u] = type;
        for(int v : edge[u]) {
            if(v == fa || flg[v] != 0 || !((mask >> (v - 1)) & 1)) continue;
            dfs1(v, u, mask, type);
        }
    }

    bool check(int mask) {
        memset(flg, 0, sizeof flg);
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
            if(((mask >> (i - 1)) & 1) && flg[i] == 0)
                dfs1(i, 0, mask, ++cnt);
        return cnt <= 2;
    }
    
    int solve() {
        dfs(1, 0);

        int res = inf;
        for(int mask = 0; mask < (1 << n); ++mask) {
            if(__builtin_popcount(mask) != k) continue;
            if(!check(mask)) continue;
            
            int maxd = 0;
            for(int i = 1; i <= n; ++i) {
                int mind = inf;
                for(int j = 1; j <= n; ++j)
                    if((mask >> (j - 1)) & 1)
                        mind = min(mind, dist(i, j));
                maxd = max(maxd, mind);
            }

            if(maxd < res) {
                sc << "maxd: " << maxd << "\n";
                for(int i = 1; i <= n; ++i)
                    if((mask >> (i - 1)) & 1)
                        sc << i << " ";
                sc << "\n";
            }

            res = min(res, maxd);
        }

        return res;
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    if(n <= 10) cout << BF::solve() << "\n";

    for(int i = 1; i <= n; ++i) edge[i].clear();
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);

    int c, T; cin >> c >> T;
    while(T--) solve();

    return 0;
}
