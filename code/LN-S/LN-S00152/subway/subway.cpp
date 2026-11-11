#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define ll long long

#define readT int
#define gc getchar_unlocked

inline readT rd() {
    readT x = 0; int f = 1, ch = gc();
    for (; !isdigit(ch); ch = gc()) {if (ch == '-') f = -1;}
    for (; isdigit(ch); ch = gc()) {x = (x << 3) + (x << 1) + (ch ^ 48);}
    return x * f;
}

constexpr int N = 5e5 + 10;

int c, n, m, d, q;
int w[N];

vector<pii> e[N + 505];
priority_queue<pii, vector<pii>, greater<pii>> qu;
queue<pii> quu;
ll dis[N + 505];
int vis[N + 505];

inline void sol() {
    c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    if (c >= 12 && c <= 19) {
        for (int i = 1; i <= m; i++) {
            w[i] = rd();
        }
        for (int i = 1; i <= n; i++) {
            int k = rd();
            for (int j = 1; j <= k; j++) {
                int a = rd(), t = rd();
                if (k > 1) {
                    e[m + i].push_back({a, t});
                    e[a].push_back({m + i, t});
                }
            }
        }

        while (q --) {
            int x = rd(), y = rd();
            ll res = w[x] + w[y];

            memset(dis, 0x3f, sizeof dis);
            memset(vis, 0, sizeof vis);
            dis[x] = 0;
            quu.push({0, x});

            while (quu.size()) {
                int u = quu.front().se;
                quu.pop();

                if (vis[u]) continue;
                vis[u] = 1;

                for (auto it : e[u]) {
                    int v = it.fi, w = it.se;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        quu.push({dis[v], v});
                    }
                }
            }

            cout << res + dis[y] << '\n';
        }
        return;
    }
    else if (c <= 11 && c >= 9) {
        for (int i = 1; i <= m; i++) {
            w[i] = rd();
        }
        for (int i = 1; i <= n; i++) {
            int k = rd();
            if (k == 1) rd(), rd();
            else {
                int u = rd(), w = rd(), v = rd();
                w += rd();
                e[u].push_back({v, w});
                e[v].push_back({u, w});
            }
        }
        
        while (q --) {
            int x = rd(), y = rd();
            ll res = w[x] + w[y];

            memset(dis, 0x3f, sizeof dis);
            memset(vis, 0, sizeof vis);
            dis[x] = 0;
            qu.push({0, x});

            while (qu.size()) {
                int u = qu.top().se;
                qu.pop();

                if (vis[u]) continue;
                vis[u] = 1;

                for (auto it : e[u]) {
                    int v = it.fi, w = it.se;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        qu.push({dis[v], v});
                    }
                }
            }

            cout << res + dis[y] << '\n';
        }

        return;
    }
    else {
        for (int i = 1; i <= m; i++) {
            w[i] = rd();
        }
        for (int i = 1; i <= n; i++) {
            int k = rd();
            for (int j = 1; j <= k; j++) {
                int a = rd(), t = rd();
                if (k > 1) {
                    e[m + i].push_back({a, t});
                    e[a].push_back({m + i, t});
                }
            }
        }

        while (q --) {
            int x = rd(), y = rd();
            ll res = w[x] + w[y];

            memset(dis, 0x3f, sizeof dis);
            memset(vis, 0, sizeof vis);
            dis[x] = 0;
            qu.push({0, x});

            while (qu.size()) {
                int u = qu.top().se;
                qu.pop();

                if (vis[u]) continue;
                vis[u] = 1;

                for (auto it : e[u]) {
                    int v = it.fi, w = it.se;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        qu.push({dis[v], v});
                    }
                }
            }

            cout << res + dis[y] << '\n';
        }
        return;
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int awa = 1;
    // awa = rd();

    while (awa --) {
        sol();
    }

    return 0;
}