#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = (s); i <= (e); i++)
#define dep(i, s, e) for (int i = (s); i >= (e); i--)
#define sz(x) (int)x.size()
#define ppc(x) __builtlin_popcnt(x)
#define pub push_back
using namespace std;

const int N = 1e6 + 5;
//#define int long long
#define ll long long
#define i28 __int128

int n, k;
int u[N], v[N], dep[N], mx[N];
vector < int > g[N];

int ban, rt, cnt, d;

void dfs(int x, int pre)
{
    dep[x] = dep[pre] + 1;
    if (dep[x] > dep[rt]) rt = x;
    for (auto to : g[x])
        if (to != pre && to != ban)
        {
            dfs(to, x);
        }
}

void dfs2(int x, int pre)
{
    dep[x] = dep[pre] + 1, mx[x] = dep[x];
    for (auto to : g[x])
        if (to != pre && to != ban)
        {
            dfs2(to, x);
            mx[x] = max(mx[x], mx[to]);
        }
    if (mx[x] - dep[x] > d || x == rt) cnt++;
}

int check()
{
    if (d == 0) return n;
    int ans = n;
    rep(i, 1, n - 1)
    {
        ban = v[i], rt = cnt = 0;
        rep(i, 1, n)
            dep[i] = 0;
        dfs(u[i], 0);
        rep(i, 1, n)
            dep[i] = 0;
        dfs(rt, 0);
        rep(i, 1, n)
            if (dep[i] == (dep[rt] + 1) / 2) 
            {
                rt = i;
                break;
            }
        rep(i, 1, n)
            dep[i] = 0;
        dfs2(rt, 0);

        rt = 0, ban = u[i];
        rep(i, 1, n)
            dep[i] = 0;
        dfs(v[i], 0);
        rep(i, 1, n)
            dep[i] = 0;
        dfs(rt, 0);
        rep(i, 1, n)
            if (dep[i] == (dep[rt] + 1) / 2) 
            {
                rt = i;
                break;
            }
        rep(i, 1, n)
            dep[i] = 0;
        dfs2(rt, 0);
        // cout << u[i] << " " << v[i] << " " << d << " " << cnt << '\n';

        ans = min(ans, cnt);
        if (ans <= k) return ans;
    }
    return ans;
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cid, ts;
    cin >> cid >> ts;
    while (ts--)
    {
        cin >> n >> k;
        rep(i, 1, n - 1)
        {
            cin >> v[i] >> u[i];
            g[v[i]].pub(u[i]);
            g[u[i]].pub(v[i]);
        }
        int l = -1, r = n - k;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            d = mid;
            if (check() <= k) r = mid;
            else l = mid;
        }
        cout << r << "\n";

        rep(i, 1, n)
            g[i].clear();
    }
    return 0;
}