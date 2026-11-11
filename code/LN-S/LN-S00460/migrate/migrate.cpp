#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int N = 1e3 + 5;
int c, T;
ll n, d, x[N], f[N], dis[N];
bool st[N];
vector<int> g[N];
int calc(int s) {
    memset(f, 0, sizeof f);
    memset(st, false, sizeof st);
    memset(dis, 0x3f, sizeof dis);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({dis[s] = 0, s});
    f[s] = 1;
    while(q.size()) {
        pll now = q.top();
        q.pop();
        int u = now.second, ud = now.first;
        if (st[u])
            continue;
        st[u] = true;
        for (int v : g[u]) {
            int nd = dis[u] + 1;
            if (nd == dis[v])
                f[v] += f[u];
            else if (nd < dis[v]) {
                dis[v] = nd, f[v] = f[u];
                q.push({dis[v], v});
            }
        }
    }
    int res = 0;
    for (int i = s; i <= n; i++)
        res += (f[i] == 2);
    return res;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%lld%lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (x[j] - x[i] > d)
                    continue;
                g[i].push_back(j);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += calc(i);
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
            g[i].clear();
    }
    return 0;
}

// g++ migrate.cpp -o migrate

// RP++, and pray for a good score