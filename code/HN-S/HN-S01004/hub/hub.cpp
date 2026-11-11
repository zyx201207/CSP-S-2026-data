#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long 
#define sqr(x) ((x) * (x))
using namespace std;

constexpr unsigned int NR = 1e3 + 5;
int CID, n, m, fa[NR], dis[NR], ans;
bitset<NR> b[NR];
vector<int> g[NR], v;
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void un(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        fa[x] = y;
}
void dfs(int x, int cnt) {
    if (cnt == m || x > n) {
        for (int i = 1; i <= n; ++ i) {
            dis[i] = 1e9;
            fa[i] = i;
        }
        int k = v.size();
        for (int i = 0; i < k; ++ i)
            for (int j = i + 1; j < k; ++ j)
                if (b[v[i]][v[j]])
                    un(v[i], v[j]);
        int x1 = find(v[0]), x2 = -1;
        for (int i = 1; i < k; ++ i) {
            int x = find(v[i]);
            if (x != x1) {
                if (x2 == -1)
                    x2 = x;
                else
                    return;
            }
        }
        queue<int> q;
        for (int i = 0; i < k; ++ i) {
            dis[v[i]] = 0;
            q.emplace(v[i]);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (const int &i : g[x])
                if (dis[i] >= n) {
                    dis[i] = dis[x] + 1;
                    q.emplace(i);
                }
        }
        ans = min(ans, *max_element(dis + 1, dis + n + 1));
        return;
    }
    v.emplace_back(x);
    dfs(x + 1, cnt + 1);
    v.pop_back();
    dfs(x + 1, cnt); 
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j)
            b[i][j] = 0;
        g[i].clear();
    }
    for (int i = 1; i < n; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        b[u][v] = b[v][u] = 1;
    }
    ans = n - 1;
    dfs(1, 0);
    cout << ans << '\n'; 
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    cin >> CID >> oT_To;
    while (oT_To --)
        solve();
    return 0; 
}
