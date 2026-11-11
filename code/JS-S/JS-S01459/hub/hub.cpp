#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k;
int h[N], ne[N << 1], e[N << 1], idx;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool vis[N], f[N];
void dfs(int u) {
    f[u] = true;
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if(f[j] || !vis[j]) continue;
        dfs(j);
    }
}
bool check() {
    memset(f, 0, sizeof f);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) continue;
        if(!f[i]) {
            dfs(i);
            cnt++;
            if(cnt > 2) return false;
        }
    }
    return true;
}
bool flag[N];
int d(int st) {
    memset(flag, 0, sizeof flag);
    queue<pair<int, int> > q;
    q.push(make_pair(st, 0));
    flag[st] = true;
    while(q.size()) {
        int u = q.front().first, dist = q.front().second;
        if(vis[u]) return dist;
        q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if(flag[j]) continue;
            flag[j] = true;
            q.push(make_pair(j, dist + 1));
        }
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t--) {
        idx = 0;
        memset(h, -1, sizeof h);
        scanf("%d%d", &n, &k);
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        int ans = 1e9 + 7;
        for(int i = 0; i < (1 << n); i++) {
            vector<int> s;
            for(int j = 1; j <= n; j++) {
                if(1 << (j - 1) & i) vis[j] = true, s.push_back(j);
                else vis[j] = false;
            }
            if(s.size() != k || !check()) continue;
            int res = -1;
            for(int j = 1; j <= n; j++) {
                res = max(res, d(j));
            }
            ans = min(ans, res);
        }
        printf("%d\n", ans);
    }
    return 0;
}
