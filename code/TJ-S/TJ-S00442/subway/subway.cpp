#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int N = 500 + 10;
const int M = 5e5 + 10;
const ll inf = 1e16;
int c, n, m, d, q, w[M];
ll dis[N][N];
vector<pii> sta[M];
inline void ckmin(ll & x, ll y) {
    if (y < x) x = y;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int s, t;
            cin >> s >> t;
            //assert(1 <= s && s <= m);
            sta[s].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = (i == j ? (ll)0 : inf);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < sta[i].size(); j++)
            for (int k = j + 1; k < sta[i].size(); k++) {
                int r = sta[i][j].first, t = sta[i][k].first, val = sta[i][j].second + sta[i][k].second;
                ckmin(dis[r][t], val);
                dis[t][r] = dis[r][t];
            }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ckmin(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = inf;
        for (auto s : sta[x])
            for (auto t : sta[y])
                ckmin(ans, dis[s.first][t.first] + s.second + t.second);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
