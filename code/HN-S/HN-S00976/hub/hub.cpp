#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int M = 2e3 + 5;
const int N = 2e6 + 5;
int c, T, n, k, u, v, p1, p2, ans, maxn, fa[N], dep[N], col[N], res[N], dis[M][M];
bool vis[N];
vector<int> vex, g[N];

inline void dfs(int x, int last, int val) {
    col[x] = val;

    for(auto u : g[x]) {
        if(u == last || col[u] || ! vis[u]) continue ;
        dfs(u, x, val);
    }

    return ;
}

inline void DFS(int x, int cnt) {
    if(cnt > k) return ;

    if(x == n + 1) {
        if(cnt < k) return ;

        int tot = 0, asd = 0;

        fill(col + 1, col + 1 + n, 0);
        fill(res + 1, res + 1 + n, 1e18);

        for(int i = 1 ; i <= n ; ++ i) {
            if(vis[i] && ! col[i]) dfs(i, 0, ++ tot);
            if(tot > 2) return ;
        }

        for(int i = 1 ; i <= n ; ++ i) {
            for(int j = 1 ; j <= n ; ++ j) {
                if(vis[i] || ! vis[j]) continue ;
                res[i] = min(res[i], dis[i][j]);
            }
        }

        for(int i = 1 ; i <= n ; ++ i)
            if(! vis[i]) asd = max(asd, res[i]);

        ans = min(ans, asd);

        return ;
    }

    vis[x] = true;
    DFS(x + 1, cnt + 1);
    vis[x] = false;
    DFS(x + 1, cnt);

    return ;
}

inline void Dfs(int x, int last) {
    for(auto u : g[x]) {
        if(u == last) continue ;
        dep[u] = dep[x] + 1;
        Dfs(u, x);
    }

    return ;
}

inline void clear() {
    ans = 1e18;
    for(int i = 1 ; i <= n ; ++ i) {
        g[i].clear();
    }
    vex.clear();

    return ;
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> T;

    while(T --) {
        clear();
        
        cin >> n >> k;
        for(int i = 1 ; i < n ; ++ i) {
            cin >> u >> v;
            g[u].pb(v), g[v].pb(u);
        }

        for(int i = 1 ; i <= n ; ++ i) {
            dep[i] = 0;
            Dfs(i, 0);
            for(int j = 1 ; j <= n ; ++ j)
                dis[i][j] = dep[j];
        }

        DFS(1, 0);

        cout << ans << '\n';
    }

    return 0;
}