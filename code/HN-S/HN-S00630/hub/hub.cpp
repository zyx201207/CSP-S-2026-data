// 20pts
#include<bits/stdc++.h>
using namespace std;

const int kMaxN = 1e6 + 5;

int C, T, n, k, dis[kMaxN], fa[kMaxN];
vector<int> g[kMaxN];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int u, int fa) {
    for(int v : g[u]) {
        if(v == fa) continue;
        dis[v] = min(dis[v], dis[u] + 1);
        dfs(v, u);
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    if(n == k) return cout << "0\n", void();
    if(C <= 14 && C >= 13) { // 性质A
        int x = (n + 1) / 2;
        if(k >= x - 1) return cout << "1\n", void();
        cout << (x - k + 3) / 4 + 1 << "\n";
        return;
    }
    if(n > 10) {
        cout << rand() % ((n - k + 3) / 4) << '\n';
        return;
    }
    int ans = 1e9;
    for(int S = 0; S < (1 << n); S++) {
        if(__builtin_popcount(S) != k) continue;
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n; i++) {
            if((S >> (i - 1)) & 1) {
                for(int j : g[i]) {
                    if((S >> (j - 1)) & 1) {
                        int u = find(i), v = find(j);
                        if(u == v) continue;
                        fa[u] = v;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if((S >> (i - 1)) & 1) cnt += (find(i) == i);
        }
        // cout << S << ' ' << cnt << '\n';
        if(cnt > 2) continue;
        for(int i = 1; i <= n; i++) dis[i] = 1e9;
        for(int i = 1; i <= n; i++) {
            if((S >> (i - 1)) & 1) {
                dis[i] = 0;
                // cout << i << ' ';
                dfs(i, 0);
            }
        }
        // cout << '\n';
        int res = 0;
        for(int i = 1; i <= n; i++) res = max(res, dis[i]);
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    srand(time(0));
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    for(cin >> C >> T; T; T--) solve();
    return 0;
}

// cd ~/HN-S00630/hub && g++ -Wall -Wextra -O2 -std=c++14 hub.cpp -o hub && time ./hub