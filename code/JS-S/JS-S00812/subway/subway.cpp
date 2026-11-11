#include<bits/stdc++.h>
#define M 500005
#define N 505
#define int long long
using namespace std;
int c, n, m, d, q, w[M], dis[N][N];
vector<pair<int, int> > v[M];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1, k; i <= n; i++)
    {
        cin >> k;
        for(int j = 1, x, y; j <= k; j++) cin >> x >> y, v[x].push_back({i, y});
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int i = 1; i <= m; i++) for(auto t : v[i]) for(auto t1 : v[i]) if(t.first != t1.first) dis[t.first][t1.first] = dis[t1.first][t.first] = min(dis[t.first][t1.first], t.second + t1.second);
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for(int i = 1, x, y; i <= q; i++)
    {
        cin >> x >> y;
        int ans = (int)(1e18);
        for(auto t : v[x]) for(auto t1 : v[y]) ans = min(ans, dis[t.first][t1.first] + t.second + t1.second);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
