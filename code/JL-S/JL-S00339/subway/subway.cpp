#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10;
int c,n,m,d,q;
ll w[M];
vector<ll>g[M],a[N],t[N];
ll dist[N][N];
map<ll,ll>v[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);t[i].push_back(y);
            g[x].push_back(i);
            v[i][x]=y;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]=1e18;
    for(int s=1;s<=m;s++)
    {
        for(int i=0;i<g[s].size();i++)
            for(int j=0;j<g[s].size();j++)
            {
                if(i==j)continue;
                int l=g[s][i],r=g[s][j];
                dist[l][r]=dist[r][l]=min(dist[l][r],v[l][s]+v[r][s]);
            }
    }
    for(int i=1;i<=n;i++)dist[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll res=1e18;
        for(int l=0;l<g[x].size();l++)
            for(int r=0;r<g[y].size();r++)
            {
                int i=g[x][l],j=g[y][r];
                res=min(res,dist[i][j]+v[i][x]+v[j][y]);
            }
        cout<<res+w[x]+w[y]<<endl;
    }
    return 0;
}
