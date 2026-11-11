#include<bits/stdc++.h>
using namespace std;
const int M = 510,N = 510;
long long w[M],t[N][M];
bool G[M][M],vis[M][M];
int c,n,m,d,q;
struct node
{
    int id;
}l[N][N];
long long ans;
void dfs(int x,int y,long long sum)
{
    if(x == y)
    {
        ans = min(ans,sum);
        return;
    }
    for(int i = 1;i <= m;i ++)
    {
        if(G[x][i] == 1 && !vis[x][i])
        {
            vis[x][i] = 1;
            dfs(i,y,sum + t[l[x][i].id][x] + t[l[x][i].id][i]);
            vis[x][i] = 0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        int x;
        cin >> x;
        int u,v,q;
        for(int j = 1;j <= x;j ++)
        {
            if(j >= 2) v = u;
            cin >> u;
            if(j == 1) q = u;
            cin >> t[i][u];
            if(j >= 2)
            {
                G[u][v] = 1;
                G[v][u] = 1;
                l[u][v].id = i;
                l[v][u].id = i;
            }
        }
        G[u][q] = 1;
        G[q][u] = 1;
        l[u][q].id = i;
        l[q][u].id = i;
    }
    while(q --)
    {
        long long x,y;
        ans = 0x3f3f3f3f;
        for(int i = 1;i <= 500;i ++)
            for(int j = 1;j <= 500;j ++)
                vis[i][j] = 0;
        cin >> x >> y;
        dfs(x,y,0);
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
    return 0;
}

