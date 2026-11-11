#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int c, t, n, k;
vector <int> G[N];
int f[N];

int popcount(int x) {
    int cnt = 0;
    while(x) {
        cnt++;
        x &= x - 1;
    }
    return cnt;
}

void dfs(int x) {
    f[x] = 2;
    for(int y : G[x])
        if(f[y] == 1)
            dfs(y);
}

int dis[N];

int bfs() {
    queue <int> Q;
    for(int i = 1; i <= n; i++) {
        dis[i] = 1e9;
        if(f[i] == 2) {
            Q.push(i);
            dis[i] = 0;
        }
    }
    int ret = 0;
    while(Q.size()) {
        int u = Q.front();
        Q.pop();
        ret = max(ret, dis[u]);
        for(int v : G[u]) {
            if(dis[v] <= n) continue;
            dis[v] = dis[u] + 1;
            Q.push(v);
        }
    }
    return ret;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(c <= 3) {
            int ans = 1e9;
            for(int S = 0; S < (1 << n); S++) {
                if(popcount(S) != k) continue;
                for(int i = 1; i <= n; i++) f[i] = S >> (i - 1) & 1;
                int block = 0;
                for(int i = 1; i <= n; i++) {
                    if(f[i] == 1) {
                        block++;
                        dfs(i);
                    }
                }
                if(block > 2) continue;
                ans = min(ans, bfs());
            }
            cout << ans << '\n';
        }
        else if(c == 13 || c == 14) {
            int m = (n + 3) / 2;
            if(k == n) cout << 0;
            else cout << max(1, (m - k + 3) / 4);
            cout << '\n';
        }
    }
    return 0;
}
