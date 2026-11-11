#include <bits/stdc++.h>
#define int long long int
#define mid (l + r) / 2
#define pushup(x) mx[x] = max(mx[x << 1], mx[x << 1 | 1]), sum[x] = sum[x << 1] + sum[x << 1 | 1]
using namespace std;
const int N = 5e5 + 5, M = 1e5 + 5;
int n, k, m, ans, a[N], mx[N], cov[N], sum[N];
void pushdown(int x, int l, int r)
{
    if(cov[x] != 0)
    {
        cov[x << 1] = cov[x << 1 | 1] = cov[x];
        mx[x] = mx[x << 1] = mx[x << 1 | 1] = cov[x];
        sum[x] = cov[x] * (r - l + 1);
        sum[x << 1] = cov[x] * (mid - l + 1);
        sum[x << 1 | 1] = cov[x] * (r - mid);
        cov[x] = 0;
    }
}
void update(int x, int l, int r ,int u, int v, int val)
{
    if(r < u || l > v)
        return;
    if(u <= l && r <= v)
    {
        cov[x] = val;
        mx[x] = val;
        sum[x] = (r - l + 1) * val;
        return;
    }
    pushdown(x, l, r);
    update(x << 1, l, mid, u, v, val);
    update(x << 1 | 1, mid + 1, r, u, v, val);
    pushup(x);
}
int query_sum(int x, int l, int r, int u, int v)
{
    if(r < u || l > v)
        return 0;
    if(u <= l && r <= v)
        return sum[x];
    pushdown(x, l, r);
    return query_sum(x << 1, l, mid, u, v) + query_sum(x << 1 | 1, mid + 1, r, u, v);
}
int query_max(int x, int l, int r, int u, int v)
{
    if(r < u || l > v)
        return -1145141919810;
    if(u <= l && r <= v)
        return mx[x];
    pushdown(x, l, r);
    return max(query_max(x << 1, l, mid, u, v), query_max(x << 1 | 1, mid + 1, r, u, v));
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i], update(1, 1, n, i, i, a[i]);
    for(int l = 1; l <= n; l++)
    {
        for(int r = l; r <= n; r++)
        {
            int ned = query_max(1, 1, n, l, r) * (r - l + 1)- query_sum(1, 1, n, l, r);
            if(ned <= k)
                ans = max(ans, r - l + 1);
            else
                break;
        }
    }
    cout << ans;
    return 0;
}
