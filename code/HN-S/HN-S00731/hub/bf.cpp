#include <bits/stdc++.h>
#define N 15
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
int cas, T, n, k, tot, head[N], dis[N];
inline void adde(int u, int v) {e[++ tot] = {v, head[u]}, head[u] = tot;}
inline bool check(int s)
{
    int ct = k ;
    for (int u = 1, i, v; u <= n; ++ u)
        if (s >> u - 1 & 1)
            for (i = head[u]; i; i = e[i].next)
                if ((v = e[i].to) > u && s >> v - 1 & 1) -- ct;
    return ct <= 2;
}
inline int bfs(int s)
{
    memset(dis + 1, 0x3f, n << 2);
    queue<int> q;
    for (int i = 1; i <= n; ++ i)
        if (s >> i - 1 & 1) dis[i] = 0, q.push(i);
    for (int u, i, v; !q.empty();)
    {
        u = q.front(), q.pop();
        for (i = head[u]; i; i = e[i].next)
            if (ckmin(dis[v = e[i].to], dis[u] + 1)) q.push(v);
    }
    return *max_element(dis + 1, dis + n + 1);
}
inline void solve()
{
    cin >> n >> k, tot = 0, memset(head + 1, 0x00, n << 2);
    for (int i = 1, u, v; i < n; ++ i) cin >> u >> v, adde(u, v), adde(v, u);
    int res = n;
    for (int s = 1; s < 1 << n; ++ s)
    {
        if (__builtin_popcount(s) == k && check(s))
            ckmin(res, bfs(s));
    }
    cout << res << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (cin >> cas >> T; T --; solve());
    return 0;
}