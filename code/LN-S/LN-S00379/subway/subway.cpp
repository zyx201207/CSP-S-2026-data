#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n, m, d, q, k[500005], a[505][500005];
ll ans = 0;
ll w[500005];
vector<pair<int, ll> > s[500005]; // s[车站号] = pair<线路, 站厅站台往返时间>
map<pair<int, int>, pair<ll, int> > mp; // 车站号, 线路 -> 往返时间, 线路内编号
//queue<pair<int, int> > g; // 车站号，线路
bool b[500005];

void dfs(int u, int v, ll dis, int line) {
    if (u == v) {
        ans = max(ans, dis + mp[{u, line}].first);
        return;
    }
    for (auto go : s[u]) {
        int gol = go.first;
        ll got = go.second;
        ll delta = 0;
        if (gol != line)
            delta = mp[{u, line}].first + mp[{u, gol}].first;
        int bh = mp[{u, gol}].second;
        if (bh != 1 && (!b[a[gol][bh - 1]])) {
            b[a[gol][bh - 1]] = true;
            //printf("%d %d->%d\n",gol,u,a[gol][bh-1]);
            fflush(stdout);
            dfs(a[gol][bh - 1], v, dis + delta, gol);
            b[a[gol][bh - 1]] = false;
        }
        if (bh != k[gol] && (!b[a[gol][bh + 1]])) {
            b[a[gol][bh + 1]] = true;
            //printf("%d %d->%d\n",gol,u,a[gol][bh+1]);
            fflush(stdout);
            dfs(a[gol][bh + 1], v, dis + delta, gol);
            b[a[gol][bh - 1]] = false;
        }
    }
}

ll solve(int u, int v) {
    for (int i = 1; i <= m; i++) b[i] = false;
    ans = 0;
    //printf("hi\n");
    dfs(u, v, w[u] + w[v], 0);
    return ans;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    for (int i = 1; i <= n; i++) {
        ll t;
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++) {
            scanf("%d%lld", &a[i][j], &t);
            s[a[i][j]].push_back({i, t});
            mp.insert({{a[i][j], i}, {t, j}});
        }
    //cout << "hi "<<i << endl;
    }
    for (int i = 1; i <= m; i++)
        mp.insert({{i, 0}, {0, 0}});
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", solve(x, y));
    }
    return 0;
}
