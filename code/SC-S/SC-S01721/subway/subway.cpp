#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5,N2 = 5e5 + 5;

//main
struct BDS
{
    int v;
    long long w;
};
vector <BDS> G[N2];
long long tds[N2],dis[N][N];
int c,n,m,d,q;
//

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++) cin >> tds[i];
    int u,v,w;
    for(int i = 1;i<=n;i++)
    {
        cin >> u;
        for(int j = 1;j<=u;j++)
        {
            cin >> v >> w;
            G[v].push_back({i,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i<=n;i++) dis[i][i] = 0;
    for(int i = 1;i<=m;i++) for(int j = 0;j<G[i].size();j++)    for(int k = j+1;k<G[i].size();k++)
    {
        u = G[i][j].v,v = G[i][k].v;
        dis[u][v] = dis[v][u] = min(dis[u][v],G[i][j].w+G[i][k].w);
    }
    for(int k = 1;k<=n;k++) for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        cin >> u >> v;
        long long an = 1e18;
        for(BDS x:G[u]) for(BDS y:G[v]) an = min(an,x.w+y.w+dis[x.v][y.v]);
        // if(an >= 1e18)
        // {
        //     cout <<"-1\n";
        //     continue;
        // }
        cout << an+tds[u]+tds[v] <<"\n";
    }
    return 0;
}