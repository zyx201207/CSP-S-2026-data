#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5e5 + 10;

int c, n, m, d, q, w[M];
bool vis[505];
struct nd {
    int p, rd;
    ll dis;
};
struct cmp {
    bool operator ()(const nd &a, const nd &b) const {
        a.dis > b.dis;
    }
};
priority_queue<nd, vector<nd>, cmp> hp;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    int nxt[n + 5][m + 5], t[n + 5][m + 5];
    for (int i = 0; i < n + 5; i++)
        for (int j = 0; j < m + 5; j++)
            nxt[i][j] = t[i][j] = -1;

    for (int i = 1; i <= m; i++) cin >> w[i];
    int k, a, ti, pa = -1;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a >> ti;
            t[i][a] = ti;
            if (pa != -1) nxt[i][pa] = a;
            pa = a;
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        memset(vis, 0, sizeof(vis));
        hp = priority_queue<nd, vector<nd>, cmp>();
        hp.push({x, -1, 0});
        while (!hp.empty()) {
            nd tp = hp.top();
            hp.pop();
            int a = tp.rd, u = tp.p;
            ll d = tp.dis;
            if (vis[u]) continue;
            if (u == y) {
                d += 1ll * t[a][y] + 1ll * w[y];
                cout << d << '\n';
                break;
            }
            vis[u] = 1;
            for (int b = 1; b <= n; b++) {
                if (b == a) {
                    hp.push({nxt[a][u], a, d});
                    continue;
                }
                if (u == x) {
                    hp.push({nxt[b][u], b, d + 1ll * w[x] + 1ll * t[b][u]});
                } else {
                    hp.push({nxt[b][u], b, d + 1ll * t[a][u] + 1ll * t[b][u]});
                }
            }
        }
    }

    return 0;
}

