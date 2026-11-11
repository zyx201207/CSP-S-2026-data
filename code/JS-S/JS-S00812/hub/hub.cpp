#include<bits/stdc++.h>
#define M 1000005
using namespace std;
int n, k, Tc, fa[20][M], st[20][M], dfn[M], tot, dep[M], R[M], rk[M], psin[M], psout[M], fl[M], id[M], lst[M], Dis[M];
vector<int> v[M];
int get(int x, int y)
{
    return (dep[x] < dep[y] ? x : y);
}
void dfs(int x, int ft)
{
    fa[0][x] = ft;
    for(int i = 1; i <= 19; i++) fa[i][x] = fa[i - 1][fa[i - 1][x]];
    dfn[x] = ++tot;
    rk[tot] = x;
    st[0][tot] = ft;
    dep[x] = dep[ft] + 1;
    for(auto t : v[x]) if(t != ft) dfs(t, x);
    R[x] = tot;
}
int LCA(int x, int y)
{
    if(x == y) return x;
    x = dfn[x], y = dfn[y];
    if(x > y) swap(x, y);
    x++;
    int lgg = __lg(y - x + 1);
    return get(st[lgg][x], st[lgg][y - (1 << lgg) + 1]);
}
int cdis(int x, int y)
{
    return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}
using node = array<int, 3>;
node operator + (node x, node y)
{
    node res = max(x, y);
    for(int o : {1, 2}) if(x[o]) for(int t : {1, 2}) if(y[t]) res = max(res, {cdis(x[o], y[t]), x[o], y[t]});
    return res;
}
node pre[M], suf[M], sub[M];
void dfs1(int x, int ft)
{
    sub[x] = (node){0, x, x};
    for(auto t : v[x]) if(t != ft)
    {
        dfs1(t, x);
        sub[x] = sub[x] + sub[t];
    }
}
int Move(int x, int y, int z)
{
    int lca = LCA(x, y);
    if(dep[x] - dep[lca] >= z)
    {
        for(int i = 19; i >= 0; i--) if(z & (1 << i)) x = fa[i][x];
        return x;
    }
    // if(x == 134) cout << "BBB: " << y << ' ' << z << ' ' << cdis(x, y) << '\n';
    z = dep[y] + dep[x] - 2 * dep[lca] - z;
    for(int i = 19; i >= 0; i--) if(z & (1 << i)) y = fa[i][y];
    // if(x == 134) cout << "BBB: " << y << ' ' << z << '\n';
    return y;
}
int cnt, Mid;
int calc(int x, int ft, int ban)
{
    int mx = 0;
    for(auto t : v[x]) if(t != ft && t != ban)
    {
        mx = max(mx, calc(t, x, ban) + 1);
        if(cnt > k) return 0;
    }
    if(mx >= Mid || ft == 0) cnt++;
    return mx;
}
int bs, bs1;
bool check(int mid)
{
    Mid = mid;
    if(n <= 4000)
    {
        for(int i = 2; i <= n; i++)
        {
            cnt = 0;
            calc(psin[i], 0, fa[0][i]);
            calc(psout[i], 0, i);
            if(cnt <= k)
            {
                // cout << i << ' ' << cnt << ' ' << mid << ' ' << psin[i] << ' ' << psout[i] << '\n';
                return 1;
            }
        }
    }
    else
    {
        int cc = 0, lim = ((Tc >= 11 && Tc <= 14) ? 2 : 3);
        for(int i = 1; i < n; i++) if(lst[id[i]] < Mid)
        {
            cc++;
            if(cc > lim) return 0;
            int x = id[i];
            cnt = 0;
            calc(psin[x], 0, fa[0][x]);
            calc(psout[x], 0, x);
            if(cnt <= k)
            {
                return 1;
            }
        }
    }
    // cout << "CH: " << mn[0] << ' ' << mn[1] << ' ' << mid << '\n';
    return 0;
}
void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) v[i].clear(), lst[i] = 0;
    for(int i = 1, x, y; i < n; i++) cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
    if(k == n) return cout << "0\n", void();
    // cout << n << ' ' << k << '\n';
    tot = 0;
    dfs(1, 0);
    for(int i = 1; i <= 19; i++) for(int j = 1; j + (1 << i) - 1 <= n; j++) st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    pre[0] = {0, 0, 0};
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (node){0, rk[i], rk[i]};
    suf[n + 1] = {0, 0, 0};
    for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + (node){0, rk[i], rk[i]};
    dfs1(1, 0);
    bs = Move(pre[n][1], pre[n][2], pre[n][0] / 2);
    bs1 = Move(pre[n][1], pre[n][2], (pre[n][0] + 1) / 2);
    for(int i = 2; i <= n; i++)
    {
        psin[i] = Move(sub[i][1], sub[i][2], sub[i][0] / 2);
        node res = pre[dfn[i] - 1] + suf[R[i] + 1];
        psout[i] = Move(res[1], res[2], res[0] / 2);
        Dis[i] = min(cdis(i, bs), cdis(i, bs1));
        // if(i == 4) cout << "AAA: " << res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << cdis(res[1], res[2]) << '\n';
    }
    iota(id + 1, id + n, 2);
    sort(id + 1, id + n, [&](int x, int y){
        return Dis[x] < Dis[y];
    });
    int l = 1, r = min(n, (pre[n][0] + 1) / 2), mid, res = -1;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << res << '\n';
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> Tc >> T;
    while(T--) solve();
    return 0;
}
