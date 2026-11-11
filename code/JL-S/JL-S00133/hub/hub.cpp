#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 1000005;
int id, n, k;
vector<int> g[N];
bool st[15], vis[15];
int dis[15];
int f[N], f2[N], sum, d;
void dfs0(int u)
{
    vis[u] = true;
    for (int i : g[u])
        if (!vis[i] && st[i])
            dfs0(i);
}
void dfs(int u,int fa)
{
    f[u] = 0, f2[u] = inf;
    for (int i : g[u])
    {
        if (i == fa)
            continue;
        dfs(i, u);
        f[u] = max(f[u], f[i] + 1);
        f2[u] = min(f2[u], f2[i] + 1);
    }
    //if (d == 2)cout<<u<<" "<<f[u]<<' '<<f2[u]<<'\n';
    if (f[u] >= d)
    {
        f[u] = -d - 1, f2[u] = 0, sum ++;
        //if (d == 2)cout<<u<<'\n';
    }
    if (f[u] + f2[u] <= d)
        f[u] = min(f[u], -1);
}
void work()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++)
        g[i].clear();
    for (int i=1;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b), g[b].pb(a);
    }
    if (n == k)
    {
        cout << "0\n";
        return;
    }
    if (id >= 1 && id <= 3)
    {
        int ans = n;
        for (int i=0;i<(1<<n);i++)
        {
            if (__builtin_popcount(i) != k)
                continue;
            for (int j=0;j<n;j++)
                st[j + 1] = i >> j & 1, vis[j + 1] = 0, dis[j + 1] = inf;
            int cnt = 0;
            for (int j=1;j<=n;j++)
                if (st[j] && !vis[j])
                    cnt ++, dfs0(j);
            if (cnt > 2)
                continue;
            queue<int> q;
            for (int j=1;j<=n;j++)
                if (st[j])
                    q.push(j), dis[j] = 0;
            int mx = 0;
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                mx = max(mx, dis[t]);
                for (int i : g[t])
                    if (dis[i] > dis[t] + 1)
                        dis[i] = dis[t] + 1, q.push(i);
            }
            ans = min(ans, mx);
        }
        cout << ans << '\n';
        return;
    }
    if (k <= 2)
    {
        int l = 1, r = n - 1, ans = r;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            d = mid, sum = 0;
            dfs(1, 1);
            if (f[1] + f2[1] > d)
                sum ++;
            if (sum <= k)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        cout << ans << '\n';
        return;
    }
    int l = 1, r = n - 1, ans = r;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int s1 = mid - 1;
        int t1 = s1 + (k + 1) / 2 - 1;
        int s2 = t1 + 2 * mid;
        if (mid % 2 == 0)
            s2 --;
        int t2 = s2 + k / 2 - 1;
        int d = n / 2 + 1 - t2;
        if (d <= mid)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << '\n';
}
int main()
{
    freopen("hub.in", "r", stdin);freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> id >> T;
    while (T--)work();
    return 0;
}
