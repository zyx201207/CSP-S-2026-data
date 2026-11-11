#include<bits/stdc++.h>
using namespace std;
using itn = int;
using ll = int64_t;
#define endl '\n'
#define file "hub"
template<typename T> void read(T &d)
{
    T x = 0; char ch;
    do ch=getchar_unlocked(); while (isspace(ch));
    do x=x*10+ch-'0', ch=getchar_unlocked(); while (isdigit(ch));
    d = x;
}
template<typename T> void readneg(T &d)
{
    T x = 0; char ch; bool neg;
    do ch=getchar_unlocked(); while (isspace(ch));
    neg = ch == '-'; if (neg) ch = getchar();
    do x=x*10+ch-'0', ch=getchar_unlocked(); while (isdigit(ch));
    d = neg ? -x : x;
}
int C;
const int maxn = 1000083;
vector<int> G[maxn];
const int bfbfn = 15;
int dis[bfbfn][bfbfn], dep[maxn], fa[maxn];
void dfs_1(int pre, int now)
{
    dep[now] = dep[fa[now] = pre] + 1;
    for (auto nxt : G[now])
        if (nxt != pre)
            dfs_1(now, nxt);
}
int bfdis(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    int ans = dep[u] - dep[v];
    while (dep[u] > dep[v]) u = fa[u];
    while (u != v) ans += 2, u = fa[u], v = fa[v];
    return ans;
}
void dfs_msk(int pre, int now, int msk, bitset<bfbfn> &vis)
{
    vis.set(now);
    for (auto nxt : G[now])
    {
        if (nxt == pre or vis[nxt]) continue;
        if (msk & (1<<(nxt-1))) dfs_msk(now, nxt, msk, vis);
    }
}
int solve_bfbf(int n, int k)
{
    int i, j;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            dis[i][j] = bfdis(i, j);
    int ans = 998244353;
    for (i=0; i<(1<<n); i++)
    {
        if (__builtin_popcount(i) != k) continue;
        int dm = 0;
        vector<int> y, x;
        for (j=1; j<=n; j++)
            if (i & (1<<(j-1)))
                y.push_back(j);
            else x.push_back(j);
        bitset<bfbfn> vis; vis.reset();
        int cnt = 0;
        for (auto u : y)
        {
            if (vis[u]) continue;
            cnt++; dfs_msk(0, u, i, vis);
        }
        if (cnt > 2) continue;
        for (auto u : x)
        {
            int mn = 1e9+7;
            for (auto v : y) mn = min(mn, dis[u][v]);
            dm = max(dm, mn);
        }
        ans = min(ans, dm);
    }
    return ans;
}
int solve_prop(int n, int k)
{
    if (n == k) return 0;
    n /= 2;
    if (k >= n) return 1;
    return 1 + (n-k+3) / 4;
}
int solve(void)
{
    int n, k; read(n); read(k);
    int i, u, v;
    for (i=1; i<=n; i++) G[i].clear();
    for (i=1; i<n; i++)
    {
        read(u); read(v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs_1(0, 1);
    if (n <= 10) return solve_bfbf(n, k);
    else return solve_prop(n, k);
}
int main(void)
{
    #ifndef NO_FREOPEN
    (void)!freopen(file ".in", "r", stdin);
    (void)!freopen(file ".out", "w", stdout);
    #endif
    read(C); int t; read(t);
    while (t--) cout << solve() << endl;
}
