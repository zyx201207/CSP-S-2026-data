#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 5e2 + 5, M = 5e5 + 5, inf = 0x3f3f3f3f;
int C, n, m, d, q, ans, s, t;
int w[M], a[M][25], dis[M][25];
vector<pair<int, int> > g[M]; // first: to, second: line
void dfs(int u, int fa, int l, int sum)
{
    // cout << u << ' ' << l << ' ' << sum << '\n';
    if(u == t)
    {
        ans = min(ans, sum + a[u][l]);
        return;
    }
    // cout << "here " << ans << ' ' << dis[u] << '\n';
    if(ans <= sum || dis[u][l] <= sum) return;
    // cout << "Here\n";
    if(sum < dis[u][l]) dis[u][l] = sum;
    for(auto v : g[u])
    {
        if(v.fi == fa) continue;
        if(v.se != l) sum += (a[u][l] + a[u][v.se]);
        dfs(v.fi, u, v.se, sum);
        if(v.se != l) sum -= (a[u][l] + a[u][v.se]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> C >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1, k; i <= n; i++)
    {
        cin >> k;
        for(int j = 1, lst, x; j <= k; j++)
        {
            cin >> x;
            cin >> a[x][i];
            if(j > 1) g[x].push_back({lst, i}), g[lst].push_back({x, i});
            lst = x;
        }
    }
    while(q--)
    {
        ans = inf;
        memset(dis, inf, sizeof(dis));
        cin >> s >> t;
        dfs(s, -1, 0, 0);
        cout << ans + w[s] + w[t] << '\n';
    }
    return 0;
}
