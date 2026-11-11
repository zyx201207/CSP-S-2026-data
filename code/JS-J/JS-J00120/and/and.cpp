#include <bits/stdc++.h>
using namespace std;

int n, m, sum = -1;
int a[200005], b[200005];
bool vis[200005];
void dfs(int dep)
{
    if (dep > m)
    {
        int ans = a[b[1]];
        for (int i = 2; i <= m; i++)
            ans = (ans & a[b[i]]);
        sum = max(sum, ans);
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            b[dep] = i;
            dfs(dep + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1);
    cout << sum << "\n";
    return 0;
}
