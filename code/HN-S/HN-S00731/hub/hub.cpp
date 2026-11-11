#include <bits/stdc++.h>
#define N 1000005
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmax(T &x, T y) {return x < y && (x = y, true);}
template <typename T> inline bool ckmin(T &x, T y) {return y < x && (x = y, true);}
struct {int to, next;} e[N << 1];
int cas, T, n, k, tot, head[N], rt, fa[N], dis[N], dep[N], siz[N], mid, mn, buc[N], w[N], num, per[N];
inline void adde(int u, int v) {e[++ tot] = {v, head[u]}, head[u] = tot;}
inline void get_mx(int u, int d, int &mx, int &res)
{
    if (ckmax(mx, d)) res = u;
    for (int i = head[u], v; i; i = e[i].next)
        if ((v = e[i].to) != fa[u]) fa[v] = u, get_mx(v, d + 1, mx, res);
}
inline void get_rt()
{
    int mx, u, v;
    mx = -1, fa[1] = 0, get_mx(1, 0, mx, u);
    mx = -1, fa[u] = 0, get_mx(u, 0, mx, v);
    for (mx >>= 1; mx --; v = fa[v]); rt = v;
}
inline void dfs(int u)
{
    dis[u] = 0;
    for (int i = head[u], v; i; i = e[i].next)
        if ((v = e[i].to) != fa[u]) fa[v] = u, dep[v] = dep[u] + 1, dfs(v), ckmax(dis[u], dis[v] + 1);
}
inline void get_siz(int u)
{
    if (dis[u] < mid) return siz[u] = 0, void();
    siz[u] = 1;
    for (int i = head[u], v; i; i = e[i].next)
        if ((v = e[i].to) != fa[u]) get_siz(v), siz[u] += siz[v];
}
inline void get_mn(int u, int t)
{
    ckmax(t, buc[dep[u]]), ckmin(mn, siz[rt] - max(0, dep[u] - t - 1));
    // cerr << u << ' ' << t << ' ' << siz[rt] << '\n';
    int mx = 0, son = 0;
    for (int i = head[u], v; i; i = e[i].next)
        if ((v = e[i].to) != fa[u])
            if (siz[v]) ++ son;
            else ckmax(mx, dis[v] + 1);
    w[u] = mid - mx;
    int lst = buc[dep[u] + mid - mx + 1];
    ckmax(buc[dep[u] + mid - mx + 1], dep[u] - mid + mx);
    for (int i = head[u], v; i; i = e[i].next)
        if ((v = e[i].to) != fa[u] && siz[v]) get_mn(v, son + (dep[u] != 1) > 2 ? max(t, dep[u]) : t);
    buc[dep[u] + mid - mx + 1] = lst;
}
inline void dfs2(int u)
{
    per[++ num] = u;
    int son = 0, nxt;
    for (int i = head[u], v; i; i = e[i].next)
        if ((v = e[i].to) != fa[u] && siz[v]) ++ son, nxt = v;
    if (son == 1) dfs2(nxt);
}
inline bool check()
{
    get_siz(rt), mn = inf, get_mn(rt, 0);
    if (mn <= k) return true;
    int son = 0;
    for (int i = head[rt], v; i; i = e[i].next)
        if (siz[v = e[i].to]) ++ son;
    if (son != 2) return false;
    num = son = 0; int pos;
    for (int i = head[rt], v; i; i = e[i].next)
        if (siz[v = e[i].to])
        {
            if (++ son == 1) dfs2(v), reverse(per + 1, per + num + 1), pos = num, per[++ num] = rt;
            else dfs2(v);
        }
    fill(buc + 1, buc + pos + 1, num);
    for (int i = 1, u; i <= num; ++ i)
    {
        u = per[i];
        // cerr << u << ' ' << w[u] << '\n';
        if (i > w[u] + 1) ckmin(buc[min(pos, i - w[u] - 1)], min(i + w[u], num));
    }
    int mx = 0;
    for (int i = pos; i; -- i)
    {
        if (i != pos) ckmin(buc[i], buc[i + 1]);
        ckmax(mx, buc[i] - i - 1);
    }
    memset(buc + 1, 0x00, pos << 2);
    return siz[rt] - mx <= k;
}
inline void solve()
{
    cin >> n >> k, tot = 0, memset(head + 1, 0x00, n << 2);
    for (int i = 1, u, v; i < n; ++ i) cin >> u >> v, adde(u, v), adde(v, u);
    get_rt(), fa[rt] = 0, dep[rt] = 1, dfs(rt); int res = dis[rt];
    for (int L = 0, R = res - 1; L <= R;)
        if (mid = L + R >> 1, check()) res = mid, R = mid - 1;
        else L = mid + 1;
    cout << res << '\n';
}
signed main()
{
    file(hub);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (cin >> cas >> T; T --; solve());
    return 0;
}