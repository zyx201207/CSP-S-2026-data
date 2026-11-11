#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, m, a[MAXN];
bool vis[MAXN];
int ans = -0x3f3f;
void dfs(int num, int pos, int step)
{

    if(step == m)
    {
        //cout << num << "\n";
        ans = max(num, ans);
        return ;
    }
    if(pos > n)
    {
        return ;
    }
    if(step == 0)
    {
        for(int i = pos ; i <= n ; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                dfs(a[i], i + 1, step + 1);
                vis[i] = 0;
            }
        }
        return ;
    }
    for(int i = pos ; i <= n ; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(a[i] & num, i + 1, step + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(vis, 0, sizeof vis);
    cin >> n  >> m;
    for(int i = 1 ; i <= n ; i++)
         cin >> a[i];
    dfs(0, 1, 0);
    cout << ans <<"\n";
    return 0;
}
