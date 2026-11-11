#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], a[505][50005], t[505][50005], vis[500005];
vector<pair<int, int> > mp[500005];
int bfs(int x, int y)
{
    memset(vis, 0x3f, sizeof(vis));
    queue<pair<int, int> > q;
    q.push({x, 0});
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        vis[f.first] = min(1 * vis[f.first], f.second);
        for (auto v : mp[f.first])
        {
            if (f.second + v.second < vis[v.first]) q.push({v.first, f.second + v.second});
        } 
    } 
    return vis[y];
} 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    } 
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a[i][j] >> t[i][j];
        } 
        for (int j = 1; j < k; j++)
        {
            for (int l = j + 1; l <= k; l++)
            {
                mp[a[i][j]].push_back({a[i][l], t[i][j] + t[i][l]});
                mp[a[i][l]].push_back({a[i][j], t[i][j] + t[i][l]});
            } 
        } 
    } //////////////
    for (int i = 1; i <= q; i++)//////////////////////////////////////////////
    {/////////////////////////////////////////////////////////////////////////
        int x, y;/////////////////////////////////////////////////////////////
        cin >> x >> y;////////////////////////////////////////////////////////
        cout << bfs(x, y) + w[x] + w[y] << "\n";//////////////////////////////
    } ////////////////////////////////////////////////////////////////////////
    return 0;/////////////////////////////////////////////////////////////////
} ////////////////////////////////////////////////////////////////////////////