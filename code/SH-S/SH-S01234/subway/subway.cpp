#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int M = 5e5 + 5;
const ll INF_LL = 0x3F3F'3F3F'3F3F'3F3F;
int c, n, m, d, q, w[M];
vector<pair<int, ll>> s[M];
ll dis[N][N];
void tarjan() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    iostream::sync_with_stdio(false);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1, a, t; j <= k; j++) {
            cin >> a >> t;
            s[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = i == j ? 0 : INF_LL;
    for (int i = 1; i <= m; i++)
        for (size_t j = 0; j < s[i].size(); j++)
            for (size_t k = j + 1; k < s[i].size(); k++) {
                int u = s[i][j].first;
                int v = s[i][k].first;
                dis[u][v] = dis[v][u] = s[i][j].second + s[i][k].second;
            }
    tarjan();
    for (int i = 1, x, y; i <= q; i++)
    {
        cin >> x >> y;
        ll ans = INF_LL;
        for (size_t j = 0; j < s[x].size(); j++)
            for (size_t k = 0; k < s[y].size(); k++)
                ans = min(ans, dis[s[x][j].first][s[y][k].first] + s[x][j].second + s[y][k].second);
        cout << w[x] + w[y] + ans << endl;
    }
    return 0;
}
