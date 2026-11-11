#include <bits/stdc++.h>
#define int long long
#define x0 rp
#define x1 Rp
#define y0 rP
#define y1 RP
#define endl '\n'
#define pll pair <int , int>
#define LLMI (int)(-1e18)
#define LLMA (int)(1e18)
using namespace std;

const int N = 2e6 + 5;
int a[N];
int n, d;
int f(int s, int e)
{
    int res = 1;
    for (int i = s + 1; i <= e; i ++)
    {
        if (a[i] - a[s] > d)
        {
            s = i - 1;
            res ++;
        }
    }
    return res;
}
int dfs(int u, int e, int step, int sh)
{
    if (u == e)
    {
        if (step == sh) return 1;
        return 0;
    }
    int res = 0;
    for (int i = u + 1; i <= e; i ++)
    {
        if (a[i] - a[u] <= d)
        {
            res += dfs(i, e, step + 1, sh);
            if (res > 2) break;
        }
    }
    return res;
}
void solve1()
{
    int ans = 0;
    for (int u = 1; u <= n; u ++)
    {
        for (int v = 1; v <= n; v ++)
        {
            int tmp = f(u, v);
//            cout << u << ' ' << v << ' ' << tmp << endl;
            if (dfs(u, v, 0, tmp) == 2) ans ++;
        }
    }
    cout << ans << endl;
}
void solve(int C)
{
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    if (n <= 9) solve1(); // 8pts
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t --) solve(c);
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
