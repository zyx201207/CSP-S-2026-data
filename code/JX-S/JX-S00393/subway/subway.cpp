#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[505][500005],siz[505];
ll edge[505][505],w[500005];
vector<vector<int> > from(500005);
int t[505][500005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++)cin >> w[i];
    for(int i = 1;i<=n;i++)
    {
        cin >> siz[i];
        for(int j = 1;j<=siz[i];j++)
        {
            cin >> a[i][j] >> t[i][a[i][j]];
            from[a[i][j]].push_back(i);
        }
    }
    memset(edge,0x3f,sizeof(edge));/*
    for(int i = 1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            for(int k = 1;k<=m;k++)
            {
                if(t[i][k]!=0&&t[j][k]!=0)
                {
                    edge[i][j] = min(edge[i][j],t[i][k]+t[j][k]);
               }
           }
            edge[j][i] = edge[i][j];
        }
    }*/

    for(int i = 1;i<=m;i++)
    {
        for(auto u:from[i])
        {
            for(auto v:from[i])
            {
                if(u<v)
                {
                    edge[v][u] = edge[u][v] = min(1ll*edge[u][v],1ll*t[u][i]+t[v][i]);
                }
            }
        }
    }
/*
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }*/

    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(i!=j)edge[i][j] = min(1ll*edge[i][j],1ll*edge[i][k]+edge[k][j]);
                else edge[i][j] = 0;
            }
        }
    }



    for(int i = 1;i<=q;i++)
    {
        int u,v;
        cin >> u >> v;
        ll ans = 1e18;
        for(auto x:from[u])
        {
            for(auto y:from[v])
            {
                ans = min(ans,1ll*edge[x][y]+w[u]+w[v]+t[x][u]+t[y][v]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
