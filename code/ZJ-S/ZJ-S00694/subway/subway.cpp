#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 505;

int cas, m, n, d, Q;
int a[N];
vector < pair <int, int> > g[N];
pair < int, int > qid[N];

int lsa[405], lst[405], l[405][405];
void tp8() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            l[i][j] = 2e18;
    for (int o = 1; o <= m; o++) {
        int k; cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> lsa[i] >> lst[i];
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j <= k; j++) {
                int x = lsa[i], y = lsa[j];
                l[x][y] = l[y][x] = min(lst[i] + lst[j], l[x][y]);
            }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (j == i || j == k) continue;
                l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
            }
        }
    while (Q--) {
        int st, ed;
        cin >> st >> ed;
        cout << l[st][ed] + a[st] + a[ed] << "\n";
    }
    exit(0);
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> cas >> m >> n >> d >> Q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (cas <= 8) tp8(); 
    return 0;
}
/*
int lsq[2005];
void tpb1() {
    for (int o = 1; o <= m; o++) {
        int k; cin >> k;
        for (int i = 1; i <= k; i++) {
            int x, t; cin >> x >> t;
            g[x].push_back({n+o, t});
            g[n+o].push_back({x, t});
        }
        for (int i = 1; i <= )
    }
}*/
/*
int dis[405];
struct node {
    int y, z;
    bool operator < (const node &b) const {
        return z < b.z; //!!!
    }
};
priority_queue < node > q;
void tp78() {
    for (int i = 1; i <= m; i++) {
        int k, x, y, v, w; 
        cin >> x >> v >> y >> w;
        g[x].push_back({y, v + w}), g[y].push_back({x, v + w});
    }
    while (Q--) {
        int st, ed; cin >> st >> ed;
        for (int i = 0; i <= n; i++)
            dis[i] = 2e18;
        dis[st] = 0; q.push({st, 0});
        while (q.size()) {
            int x = q.top().y; q.pop();
            for (auto i : g[x]) {
                int y = i.first, z = i.second;
                if (dis[x] + z < dis[y]) {
                    dis[y] = dis[x] + z;
                    q.push({y, z});
                }
            }
        }
        // cout << dis[ed] << '\n';
    }
    // exit(0);
}*/