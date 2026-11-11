#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a);i <= (b);i++)
typedef long long ll;
typedef pair<int, ll> pii;
const int N = 505, Max = 5e5+5;
int c, n, m, d, q, k[N];
ll w[Max], dis[N][N];
vector<pii> s[Max];
int main()
{
    //ka tsu zo.
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    rep(i, 1, m)cin >> w[i];
    rep(i, 1, n)
    {
        cin >> k[i];
        int a;ll t;
        rep(j, 1, k[i])
        {
            cin >> a >> t;
            s[a].push_back(make_pair(i, t));
        }
    }
    rep(i, 1, n)rep(j, 1, n)dis[i][j] = 5e17;
    rep(i, 1, n)dis[i][i] = 0;
    rep(i, 1, m)
    {
        int len = s[i].size();
        rep(x, 0, len-1)rep(y, x+1, len-1)
        {
            int u = s[i][x].first, v = s[i][y].first;
            ll tot = s[i][x].second+s[i][y].second;
            dis[u][v] = min(dis[u][v], tot);
            dis[v][u] = min(dis[v][u], tot);
        }
    }
    rep(i, 1, n)rep(k, 1, n)rep(j, 1, n)
        dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    while(q--)
    {
        int u, v;cin >> u >> v;
        ll ans = 1e18;
        for(pii x:s[u])for(pii y:s[v])
        {
            ll tmp = w[u]+w[v]+x.second+y.second+dis[x.first][y.first];
            ans = min(ans, tmp);
        }
        cout << ans << "\n";
    }
    return 0;
}
