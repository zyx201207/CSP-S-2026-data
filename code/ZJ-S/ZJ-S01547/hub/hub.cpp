#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int c, t, n, k, dis[N][N], fl[N];
vector <int> e[N];
bool vis[N];
queue <int> q;
void dfs(int u) {
    vis[u] = 1;
    for(int v : e[u]) if(!vis[v] && fl[v]) dfs(v);
}
bool check() {
    for(int i = 1; i <= n; i++) vis[i] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(!vis[i] && fl[i]) {
        cnt++;
        if(cnt > 2) return 0;
        dfs(i);
    }
    return 1;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) e[i].clear();
        for(int i = 1, u, v; i < n; i++) {
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) vis[j] = 0;
            vis[i] = 1, dis[i][i] = 0;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : e[u]) if(!vis[v]) {
                    vis[v] = 1, dis[i][v] = dis[i][u] + 1;
                    q.push(v);
                }
            }
        }
        int ans = 1e9;
        for(int i = 0; i < (1 << n); i++) if(__builtin_popcount(i) == k) {
            for(int j = 1; j <= n; j++) fl[j] = ((i >> j - 1) & 1);
            if(check()) {
                int maxn = 0;
                for(int i = 1; i <= n; i++) {
                    int minn = 1e9;
                    for(int j = 1; j <= n; j++) if(fl[j]) minn = min(minn, dis[i][j]);
                    maxn = max(maxn, minn);
                }
                ans = min(ans, maxn);
            }
        }
        printf("%d\n", ans);
    }
}
