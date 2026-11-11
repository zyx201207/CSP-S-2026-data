#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int C, T;
int n, m, mn, cnt;
int a[N], dp[N];
void dfs(int u, int y, int sum)
{
    if(sum > mn || cnt > 2) return;
    // cout << u << ' ' << sum << '\n';
    if(u == y)
    {
        if(sum < mn) cnt = 1, mn = sum;
        else if(sum == mn) cnt++;
        // cout << sum << ' ' << u << ' ' << cnt << '\n';
        return;
    }
    for(int i = u + 1; i <= y; i++)
    {
       // if(i == u) continue;
        if(abs(a[u] - a[i]) <= m) dfs(i, y, sum + 1);
    }
}
bool check(int x, int y)
{
    mn = 1e18, cnt = 0;
    dfs(x, y, 0);
    if(cnt == 2) return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> C >> T;
    if(C <= 10)
    {
        while(T--)
        {
            cin >> n >> m;
            int ans = 0;
            for(int i = 1; i <= n; i++) cin >> a[i];
            for(int i = 1; i <= n; i++)
            {
                for(int j = i + 2; j <= n; j++)
                {
                    if(check(i, j)) ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    if(11 <= C && C <= 12)
    {
        while(T--)
        {
            cin >> n >> m;
            for(int i = 1; i <= n; i++) cin >> a[i];
            int d = a[2] - a[1];
            if(m < 2 * d)
            {
                cout << "0\n";
                continue;
            }
            int x = m / d;
            int ans = 0;
            for(int i = 1; i < x; i++) ans += (n - x - i);
            cout << ans << '\n';
        }
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
