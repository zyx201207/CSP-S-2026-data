#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define intinf 0x3f3f3f3f
int c, t;
int n, k;
vector<vector<int> > g;
vector<int> dep, mxdep, fa, siz, dfn, nfd, sedep, thdep;
vector<vector<int> > dtd; // dep to dfn
int dfncnt;
vector<array<int, 2> > f; // 0 1 个连通块 2 两个连通块
vector<vector<int> > st; // dfn -> dfn
int d;
int LCA(int u, int v)
{
    u = dfn[u], v = dfn[v];
    if (u == v) return u;
    if (u > v) swap(u, v);
    int dl = __lg(v - u + 1);
    return nfd[min(st[dl][u], st[dl][v - (1 << dl) + 1])];
} // dfs 序求 LCA
void dfs(int u)
{
    f[u][0] = 1, f[u][1] = intinf; // 每次不断合并子树
    int delta = intinf;
    for (auto v : g[u])
    {
        if (v == fa[u]) continue;
        dfs(v);
        if (mxdep[v] <= dep[u] + d) continue; // 不用管
        int sdep = dep[u] + d + 1; // 从这一层开始就必须要放了
        auto bg = upper_bound(dtd[sdep].begin(), dtd[sdep].end(), dfn[u]);
        auto ed = upper_bound(dtd[sdep].begin(), dtd[sdep].end(), dfn[u] + siz[u] - 1);
        if (bg != ed)
        {
            int p1 = *bg, p2 = *--ed;
            int lca = LCA(p1, p2);
            delta = min(delta, f[lca][0] - f[v][0]);
        }
        f[u][1] = min(f[u][1] + f[v][0], f[u][0] + f[v][1]); // 新的多了一个连通块或者旧的有两个连通块
        f[u][0] += f[v][0]; // 下面必须也是单个连通块
    }
    f[u][1] = min(f[u][1], f[u][0] + delta); // 选一个换成第二个连通块
} // 直接先钦定选择 u 作为一个基地
static inline bool chk(int d_)
{
    d = d_;
    f.assign(n + 1, {intinf, intinf});
    dfs(1);
    if (min(f[1][0], f[1][1]) <= k) return 1; // 直接用根这一块就可以
    for (int u = 2; u <= n; u++)
    {
        int ep = (mxdep[1] == mxdep[u] ? sedep[1] : mxdep[1]);
        if (dep[u] - dep[1] + ep - dep[1] > d) continue; // 距离过大
        if (min(f[u][0], f[u][1]) <= k) return 1; // 用这一块即可
    } // 钦定一个非根的一块
    if (n < 1000)
    {
        for (int u = 2; u <= n; u++)
        {
            for (int v = u + 1; v <= n; v++)
            {
                int ep = mxdep[1];
                if (ep == mxdep[u] || ep == mxdep[v]) ep = sedep[1];
                if (ep == mxdep[u] || ep == mxdep[v]) ep = thdep[1];
                if (dep[u] - dep[1] + ep - dep[1] > d && dep[v] - dep[1] + ep - dep[1] > d) continue;
                if (f[u][0] + f[v][0] <= k) return 1;
            }
        }
    }
    return 0;
} // 能不能做到通勤半径不超过 d？
void dfs_init(int u)
{
    nfd[dfn[u] = ++dfncnt] = u;
    mxdep[u] = dep[u];
    siz[u] = 1;
    for (auto v : g[u])
    {
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs_init(v);
        auto upd = [&](int ep)
        {
            if (ep > mxdep[u]) swap(ep, mxdep[u]);
            if (ep > sedep[u]) swap(ep, sedep[u]);
            if (ep > thdep[u]) swap(ep, thdep[u]);
        };
        upd(mxdep[v]);
        upd(sedep[v]);
        upd(thdep[v]);
        siz[u] += siz[v];
    }
} // 维护每个点深度和往下最多有多深
static inline void init()
{
    cin >> n >> k;
    g.assign(n + 1, vector<int> ());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep.assign(n + 1, 1); // dep[1] = 1
    mxdep.assign(n + 1, 0);
    sedep.assign(n + 1, 0);
    thdep.assign(n + 1, 0);
    fa.assign(n + 1, 0);
    siz.assign(n + 1, 0);
    dfn.assign(n + 1, 0);
    nfd.assign(n + 1, 0);
    dfncnt = 0;
    dfs_init(1);
    dtd.assign(n + 2, vector<int> ());
    for (int i = 1; i <= n; i++) dtd[dep[i]].push_back(dfn[i]);
    for (int i = 1; i <= n; i++) sort(dtd[i].begin(), dtd[i].end());
    st.assign(30, vector<int> (n + 1));
    for (int u = 1; u <= n; u++) st[0][dfn[u]] = dfn[fa[u]];
    for (int i = 1; i <= 30; i++)
    {
        for (int u = 1; u + (1 << i) - 1 <= n; u++)
        {
            st[i][u] = min(st[i - 1][u], st[i - 1][u + (1 << (i - 1))]);
        }
    }
}
static inline void solve()
{
    init();
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (chk(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}
/*
我说没有交互题算出题人数了
// freopen("hub.in", "r", stdin);
// freopen("hub.out", "w", stdout);
//freopen("hub.in", "r", stdin);
//freopen("hub.out", "w", stdout);
严肃蹭注释 freopen 计数
苏研发，，强。无敌！
传送门？！（没有三）
树？！
半径？！
jzc844保佑！
二阶堂希罗保佑！
WorldMachine保佑！
MornStar保佑！
WZY保佑！
tourist保佑！
AmaoFox保佑！
请来各洞诸神仙～
感觉长得像个 DP？
10 的 6 次方能做马。。。
为什么我说话要带？！
不知道？！
最大值最小，想到二分，公式做题就是快。
写了个很诡异的东西
似乎不好换根，只能试着用一种很诡异的方式表达贡献
关注 luogu clx201022 552688 喵，关注 clx201022 谢谢喵
*/