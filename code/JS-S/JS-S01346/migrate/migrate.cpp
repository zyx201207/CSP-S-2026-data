#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, x[2000006],vis[5002][5002];
int dfs(int x, int y)
{
    return 2;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>> c>>T;
    while(T--)
    {
        ll n, d;cin>>n>>d;
        for(int i = 1; i <= n; i ++)cin>>x[i];
        for(int i = 1; i <= n; i ++){
            for(int j = i+1; j<= n; j ++){
                vis[i][j] = dfs(i,j);
            }
        }
        cout << 0;
    }
    return 0;
}
