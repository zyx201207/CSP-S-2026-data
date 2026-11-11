#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define llinf 0x3f3f3f3f3f3f3f3f
int c, n, m, d, q;
vector<ll> w;
vector<int> k;
vector<vector<pair<ll, int> > > g;
static inline void solve1()
{
    vector<vector<ll> > f;
    f.assign(n + m + 1, vector<ll> (n + m + 1, llinf));
    for (int u = 1; u <= n + m; u++) f[u][u] = 0;
    for (int u = 1; u <= n + m; u++)
    {
        for (auto tv : g[u])
        {
            ll t;
            int v;
            tie(t, v) = tv;
            f[u][v] = min(f[u][v], t);
        }
    }
    for (int i = 1; i <= n + m; i++)
    {
        for (int u = 1; u <= n + m; u++)
        {
            for (int v = 1; v <= n + m; v++)
            {
                if (u == v) continue;
                f[u][v] = min(f[u][v], f[u][i] + f[i][v]);
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << f[x][y] + w[x] + w[y] << '\n';
    }
}
static inline void solve2()
{
    vector<vector<ll> > f(n + 1, vector<ll> (n + 1, llinf));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int u = 1; u <= m; u++)
    {
        for (auto tj1 : g[u])
        {
            for (auto tj2 : g[u])
            {
                ll t1, t2;
                int j1, j2;
                tie(t1, j1) = tj1;
                tie(t2, j2) = tj2;
                int v1 = j1 - m, v2 = j2 - m;
                if (v1 == v2) continue;
                f[v1][v2] = min(f[v1][v2], t1 + t2);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                if (u == v) continue;
                f[u][v] = min(f[u][v], f[u][i] + f[i][v]);
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        ll ans = llinf;
        int x, y;
        cin >> x >> y;
        for (auto tj1 : g[x])
        {
            for (auto tj2 : g[y])
            {
                ll t1, t2;
                int j1, j2;
                tie(t1, j1) = tj1;
                tie(t2, j2) = tj2;
                int v1 = j1 - m, v2 = j2 - m;
                ans = min(ans, t1 + t2 + f[v1][v2]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> n >> m >> d >> q;
    w.resize(m + 1);
    k.resize(n + 1);
    for (int i = 1; i <= m; i++) cin >> w[i];
    g.resize(n + m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        int u = m + i;
        for (int j = 1; j <= k[i]; j++)
        {
            ll t; int a;
            cin >> a >> t;
            g[a].emplace_back(t, u);
            g[u].emplace_back(t, a);
        }
    }
    // if (n + m <= 500) solve1(); else 
    solve2();
    return 0;
}
/*
出题人出的一定要是题 &#x270D;&#x270D;&#x270D;
图论建模这一块
本关考察你建图能力
站点和轨道分别建点，是个二分图
可不可用一个很诡异的弗洛伊德~~精神分析~~？
好像不行……
好的，用户要求我们注意到 q 这个条件，也许可以把询问挂在什么东西上处理？
有点难，先写个 floyd 吧
我图论没怎么复习 QAQ
二分图，然后下面的点度数 <= 20 上面的点数 <= 500
可不可以先跑轨道之间的 floyd 再做？试试。
O(玄学)？！
友方比赛结束后，若本题得分不小于 100，将本人转换为猫娘并给所有友方单位**草**
嘎人们你们觉得我能上迷惑行为大赏吗？
114514
1919810
917813
350234
关注 luogu clx201022 552688 喵，关注 clx201022 谢谢喵
*/