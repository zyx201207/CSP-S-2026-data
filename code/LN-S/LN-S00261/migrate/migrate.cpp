#include <bits/stdc++.h>
#define sfr return cerr << "safe\n", 0;
#define sfv return cerr << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
using pr = pair<int, int>;
using prt = tuple<int, int>;
using tpt = tuple<int, int, int>;
#define FILEIO "migrate"
const int N = 2e6 + 10;

int c, t, n; ll x[N], d;
int dis[N], gx[N];
vector<int> E[N];
priority_queue<pr, vector<pr>, greater<pr> > Q;

auto dij(int st) -> int {
    ll ret = 0;
    fill(dis + 1, dis + n + 1, 1e9);
    fill(gx + 1, gx + n + 1, 0);
    Q.emplace(0, st), dis[st] = 0;
    while (!Q.empty()) {
        auto [val, u] = Q.top(); Q.pop();
        if (val != dis[u]) continue;
        for (auto &v : E[u]) {
            int w = 1;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                Q.emplace(dis[v], v);
                gx[v] = 1;
            } else if (dis[v] == dis[u] + w) {
                gx[v]++;
            }
        }
    }
    for (int i = st + 1; i <= n; ++i) ret += (gx[i] == 2);
    // for (int i = 1; i <= n; ++i) ret += (gx[i] == 2);
    return ret;
}

auto sol6() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (x[j] - x[i] > d) break;
            E[i].emplace_back(j); // E[j].emplace_back(i);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dij(i);
        // cerr << i << ": \n";
        // for (int j = i + 1; j <= n; ++j) cerr << gx[j] << " \n"[j == n];
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i) E[i].clear();
}

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> t;
    if (c <= 6) {
        while (t--) sol6();
    }
}