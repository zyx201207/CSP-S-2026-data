#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];
struct Node{
    long long idx, time;
} b[N];
bool x[1005][1005];
long long ans;
long long c, n, m, d, q;
void dfs (long long pos, long long sum, long long tgt)
{
    if (sum > ans)
    {
        return ;
    }
    if (pos == tgt)
    {
        ans = min (sum, ans);
        return ;
    }
    for (long long i = pos + 1;i <= m;i++)
    {
        if (x[i][pos])
        {
            dfs (i, sum + b[pos].time + b[i].time, tgt);
        }
    }
}
int main()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (long long i = 1;i <= m;i++)
    {
        cin >> a[i];
    }
    for (long long i = 1;i <= n;i++)
    {
        long long cnt;
        cin >> cnt;
        for (long long j = 1;j <= cnt;j++)
        {
            cin >> b[j].idx >> b[j].time;
            for (long long k = 1;k <= j;k++)
            {
                x[b[j].idx][b[k].idx] = x[b[k].idx][b[j].idx] = true;
            }
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ans = LONG_LONG_MAX;
        dfs (l, 0, r);
        cout << ans << endl;
    }
    return 0;
}
