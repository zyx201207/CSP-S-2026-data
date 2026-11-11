#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

//main
vector <int> G[N];
// int dp[105][105][105][2],dp2[105][105][105][5];
// int dpt[N],sz[N];
int sz[N];
int st;
int n,k;
// void dfs(int u,int f)
// {
//     dpt[u] = dpt[f]+1;
//     sz[u] = 1;
//     int tmx = 0,tmx2 = 0;
//     for(int v:G[u])
//     {
//         if(v == f)  continue;
//         dfs(v);
//         if(dpt[v] >= tmx)   tmx2 = tmx,tmx = dpt[v];
//         else if(dpt[v] > tmx2)  tmx2 = dpt[v];
//         sz[u] += sz[v];
//     }
//     int ls = 0;
//     for(int v:G[u])
//     {
//         if(v == f)  continue;
//         for(int i = 0;i<=min(sz[u],k);i++)  for(int j = 0;j<=tmx;j++)
//         {
//             if(j == 0)  dp2[v][i][j][0] = max(dp2[ls][i][j][0],dpt[v]-dp[u]);
//             if(j > 0)   dp2[v][i][j][1] = min(dp2[v][i][j][1],max(dp[v][i][j-1][0],(dpt[v] == tmx ? tmx2:tmx)-dp[u]+j));
//             if(j > 0)   dp2[v][i][j][4] = min(dp2[v][i][j][4],max(dp[v][i][j-1][1],(dpt[v] == tmx ? tmx2:tmx)-dp[u]+j));
//             dp2[v][i][1][2] = max(dp2[ls][i][1][2],dpt[v]-dp[u]);
//             for(int tk = 0;tk<=i;tk++)
//             {
//                 if(j == 0)  dp2[v][i][j][0] = min(dp2[ls][tk][j][0],dp[v][i-tk][0][0]);
//                 if(j > 0)   dp2[v][i][1][2] = min(dp2[v][i][1][2],max(dp2[ls][tk][0][0],dp[v][i-tk][j][0]));
//                 dp2[v][i][j][3] = min(dp2[v][i][j][3],max(dp2[ls][tk][j]))
//             }
//         }
//         ls = v;
//     }
//     dpt[u] = tmx;
    
// }
int check(int u,int f)
{
    int s = 0,t = 0;
    for(int v:G[u])
    {
        if(v == f)  continue;
        s += check(v,u)-(((st << 1 >> v)&1) && ((st << 1 >> u)&1));
        t |= ((st << 1 >> v) & 1);
    }
    return s+(!t && ((st << 1 >> u) & 1));
}
int dfs(int u,int f)
{
    if((st << 1 >> u) & 1)  return 0;
    int mn = 1e9;
    for(int v:G[u])
    {
        if(v == f)  continue;
        mn = min(mn,dfs(v,u)+1);
    }
    return mn;
}
//

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1;i<=(1 << 10)-1;i++)   sz[i] = sz[i&(i-1)]+1;
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        int u,v;
        for(int i = 1;i<n;i++)
        {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        // memset(dp,0x3f,sizeof(dp)):
        int an = 1e9;
        for(int i = 1;i<=(1 << n)-1;i++)
        {
            st = i;
            if(sz[i] != k)  continue;
            int t = check(1,0);
            if(t > 2)   continue;
            int mx = 0;
            for(int j = 1;j<=n;j++) mx = max(mx,dfs(j,0));
            an = min(an,mx);
        }
        cout << an <<"\n";
        for(int i = 1;i<=n;i++) G[i].clear();
    }
    return 0;
}