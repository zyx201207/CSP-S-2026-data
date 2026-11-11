#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
int c, n;
ll d;
ll a[2000005];
int l[2000005], r[2000005];
unordered_map<int, vector<int> > pntl, pntr;
int cntl, cntr;
void dfsl(int x, int pre)
{
    cntl ++;
    for(auto it : pntr[x])
    {
        if(it == pre) continue;
        dfsl(l[it], it);
    }
    return;
}
void dfsr(int x, int pre)
{
    cntr ++;
    for(auto it : pntl[x])
    {
        if(it == pre) continue;
        dfsr(r[it], it);
    }
    return;
}
int cnt;
void dfs(int x, int tot, int fnl, int stp)
{
    if(tot > stp) return;
    if(tot == stp && x == fnl)
    {
        cnt ++;
        return;
    }
    for(int i = x + 1; i <= r[x]; i ++) dfs(i, tot + 1, fnl, stp);
    return;
}
void solve()
{
    cin >> n >> d;
    for(int i = 0; i <= n; i ++) a[i] = l[i] = r[i] = 0;
    pntl.clear(), pntr.clear();
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++)
    {
        int lft = 1, rght = i;
        while(lft <= rght)
        {
            int mid = (lft + rght) >> 1;
            if(a[i] - a[mid] <= d) l[i] = mid, rght = mid - 1;
            else lft = mid + 1;
        }
        lft = i, rght = n;
        while(lft <= rght)
        {
            int mid = (lft + rght) >> 1;
            if(a[mid] - a[i] <= d) r[i] = mid, lft = mid + 1;
            else rght = mid - 1;
        }
        pntl[l[i]].push_back(i), pntr[r[i]].push_back(i);
    }
    vector<pair<int, int> > prs;
    for(int i = 1; i <= n; i ++)
    {
        if(r[i] <= i + 1) continue;
        for(auto it : pntl[r[i] - 1])
        {
            if(l[it] >= it - 1) continue;
            prs.push_back({i, it});
        }
    }
    ll ans = 0;
    for(auto it : prs)
    {
        cntl = cntr = 0;
        dfsl(l[it.first], it.first), dfsr(r[it.second], it.second);
        ans += (ll)cntl * (ll)cntr;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    IOS;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T;
    cin >> c >> T;
    if(c == 11 || c == 12)
    {
        while(T --)
        {
            cin >> n >> d;
            for(int i = 1; i <= n; i ++) cin >> a[i];
            ll t = a[2] - a[1];
            ll len = d / t;
            if(len * 2 + 1 >= n || len <= 1) cout << "0\n";
            else cout << n - 2 * len + 1 << "\n";
        }
    }
    else if(c == 13 || c == 14)
    {
        while(T --)
        {
            cin >> n >> d;
            for(int i = 1; i <= n; i ++) cin >> a[i];
            cout << "0\n";
        }
    }
    else if(c <= 6)
    {
        while(T --)
        {
            cin >> n >> d;
            for(int i = 1; i <= n; i ++) cin >> a[i];
            for(int i = 1; i <= n; i ++)
            {
                l[i] = r[i] = i;
                for(int j = i - 1; j >= 1; j --) if(a[i] - a[j] <= d) l[i] = j;
                for(int j = i + 1; j <= n; j ++) if(a[j] - a[i] <= d) r[i] = j;
            }
            ll g[305][305] = {0};
            for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++)
            {
                if(i == j) continue;
                int u = min(i, j), v = max(i, j);
                if(r[u] >= v) g[u][v] = g[v][u] = 1;
                else g[u][v] = g[v][u] = 0x3f3f3f3f;
            }
            for(int k = 1; k <= n; k ++) for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            int ans = 0;
            for(int i = 1; i <= n; i ++)
            {
                for(int j = i + 2; j <= n; j ++)
                {
                    cnt = 0;
                    dfs(i, 0, j, g[i][j]);
                    if(cnt == 2) ans ++;
                }
            }
            cout << ans << "\n";
        }
    }
    else while(T --) solve();
    return 0;
}
