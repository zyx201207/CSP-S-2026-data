#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 5e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;

int c, n, m, d, q;

struct node {
    int u, v, t;
} a[510][N];

int w[N], k[510];

int dis[510][510];

void solve() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j) {
            int x, t; cin >> x >> t;
            a[i][j] = {j, x, t};
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k[i]; ++j) {
                if (a[i][j].u == l && a[i][j].v == r || a[i][j].u == r && a[i][j].v == l) {
                    ans += a[i][j].t;
                }
            }
        }
        cout << w[l] + w[r] + ans << endl;
    }
    return ;
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 5e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;

int c, n, m, d, q;

struct node {
    int u, v, t;
} a[510][N];

vector<pair<int, int> > vec[N];

int getid(int k, int j) {
    return (k - 1) * n + j;
}

int w[N], k[510];

int dis[N];

bool vis[N];

int MX;

int dij(int s, int t) {
    for (int i = 1; i <= n * MX; ++i) {
        dis[i] = inf;
        vis[i] = 0;
    }
    priority_queue<pair<int, int> > q;
    q.push({0, s});
    dis[s] = 0;
    while (!q.empty()) {
        auto u = q.top().second;
        q.pop();
        if (vis[u]) continue ;
        vis[u] = 1;
        for (auto v : vec[u]) {
            if (dis[v.first] > dis[u] + v.second) {
                dis[v.first] = dis[u] + v.second;
                q.push({-dis[v.first], v.first});
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k[i]; ++j) {
            if (dis[(i - 1) * n + j] == inf) continue;
            ans = min(ans, dis[(i - 1) * n + j]);
        }
    }
    return ans;
}

void solve() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        MX = max(MX, k[i]);
        for (int j = 1; j <= k[i]; ++j) {
            int a, t;
            cin >> a >> t;
            vec[(int)getid(i, j)].push_back({getid(i, a), t});
            vec[(int)getid(i, a)].push_back({getid(i, j), t});
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dij(l, r) + w[l] + w[r] << endl;
    }
    return ;
}

signed main() {
    // freopen("user.in", "r", stdin);
    // freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}

*/