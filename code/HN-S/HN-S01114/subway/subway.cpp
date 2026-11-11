#include <iostream>
#include <vector>
#define int long long
using namespace std;
int T,id;
int n,m,d,q,a[200005],b[200005],w[500005],u,v;
int dp[805][805];
vector<int>ve[500005],ve2[500005];
void solve()
{
    cin >> id >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++)cin >> w[i];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
        {
            dp[i][j] = 1e18;
            if(i == j)dp[i][j] = 0;
        }
    for(int i = 1,to,x,y;i <= n;i ++)
    {
        cin >> to;
        while(to --)
        {
            cin >> x >> y;
            ve[x].push_back(i),ve2[x].push_back(y);
        }
    }
    for(int i = 1;i <= m;i ++)
        for(int j = 0;j < ve[i].size();j ++)
            for(int k = 0;k < ve[i].size();k ++)
                dp[ve[i][j]][ve[i][k]] = min(dp[ve[i][j]][ve[i][k]],ve2[i][j] + ve2[i][k]);
    for(int x = 1;x <= n;x ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++)dp[i][j] = min(dp[i][j],dp[i][x] + dp[x][j]);
    while(q --)
    {
        cin >> u >> v;
        if(u == v)
        {
            cout << "0\n";
            continue ;
        }
        int trans = 1e18;
        for(int i = 0;i < ve[u].size();i ++)
            for(int j = 0;j < ve[v].size();j ++)trans = min(trans,dp[ve[u][i]][ve[v][j]] + ve2[u][i] + ve2[v][j] + w[u] + w[v]);
        cout << trans << '\n';
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    T = 1;
    while(T --)solve();
}
/*
idea:16:05,but O(n*(q + \sumk_i \log n)) maybe can
16:10 ** computer si ji le !!!! !!!!
16:12 teacher helps. fixed
16:26 maybe floyd can get O(n^3 + d^2q)
16:28 oh!!!I know it!
solved:16:42
expected:100pts
*/
