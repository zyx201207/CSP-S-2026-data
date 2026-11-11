#include <bits/stdc++.h>
using namespace std;

const int N = 5E5 + 5;
typedef long long ll;
int c, n, m, d, q;
ll ed[505][505];
vector<pair<int, ll> > zt[505];
vector<pair<int, ll> > stpas[N];
ll w[N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        ed[i][i] = 0;
        for (int j = 1; j <= n; j++)
            if (i != j) 
                ed[i][j] = 1e18;
    }
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int ki;
        cin >> ki;
        for (int j = 1; j <= ki; j++) {
            int a; ll t;
            cin >> a >> t;
            zt[i].push_back({a, t});
            for (auto tmp : stpas[a]) {
                int v = tmp.first; ll cos = t + tmp.second;
                ed[i][v] = ed[v][i] = min(ed[i][v], cos);
                // cnt++;
            }
            stpas[a].push_back({i, t});
        }
        sort(zt[i].begin(), zt[i].end());
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ed[i][j] > ed[k][i] + ed[k][j]) {
                    ed[i][j] = ed[k][i] + ed[k][j];
                }
            }
        }
    }
    int mx = 0;
    double t1 = (double)clock() / CLOCKS_PER_SEC;
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        mx = max(stpas[x].size(), stpas[y].size());
        for (auto tmp1: stpas[x]) {
            int fr = tmp1.first; ll cos1 = tmp1.second;
            for (auto tmp2 : stpas[y]) {
                int edd = tmp2.first; ll cos2 = tmp2.second;
                ans = min(ans, cos1 + cos2 + w[x] + w[y] + ed[fr][edd]);
            }
        }
        cout << ans << '\n';
    }
    double t2 = (double)clock() / CLOCKS_PER_SEC;
    // cerr << t2 - t1 << ' ' << mx << '\n';
}