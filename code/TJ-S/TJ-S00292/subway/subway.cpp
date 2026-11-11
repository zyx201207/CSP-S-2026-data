#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 510;
const int MAXM = 5e5 + 100;

LL c, n, m, d, q, x, y;
LL w[MAXM], k[MAXN];
vector<LL> a[MAXN], t[MAXN];
vector<pair<LL, LL>> s[MAXM]; // che zhan -> xian lu
LL dis[MAXN][MAXN];

void floyd()
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        a[i].reserve(k[i] + 1);
        t[i].reserve(k[i] + 1);
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            s[a[i][j]].push_back({i, t[i][j]});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) { // che zhan
        int sz = s[i].size();
        for (int j = 0; j < sz; j++) {
            for (int k = j + 1; k < sz; k++) {
                auto [x1, t1] = s[i][j];
                auto [x2, t2] = s[i][k];
                LL tw = t1 + t2;
                dis[x1][x2] = min(dis[x1][x2], tw);
                dis[x2][x1] = min(dis[x2][x1], tw);
            }
        }
    }

    floyd();

    while (q--) {
        cin >> x >> y;
        LL ans = 1e18;
        for (auto [lx, tx] : s[x]) {
            for (auto [ly, ty] : s[y]) {
                ans = min(ans, w[x] + w[y] + tx + ty + dis[lx][ly]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
