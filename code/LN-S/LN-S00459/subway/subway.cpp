#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
struct node
{
    int v,w;
};
vector<node>ed[MAXN];//代表第i个地铁站的站厅到各个线路的
int w[MAXN];
int a[505][505];//各个线路之间的最短路
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;cin>>x>>y;
            ed[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)    a[i][j]=0;
            else a[i][j]=2e12;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(ed[i].size()<2)  continue;
        for(int j=0;j<ed[i].size();j++)
        {
            for(int k=j+1;k<ed[i].size();k++)
            {
                node x=ed[i][j],y=ed[i][k];
                a[x.v][y.v]=a[y.v][x.v]=min(a[x.v][y.v],x.w+y.w);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                a[i][j]=a[j][i]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while(q--)
    {
        int s,e;cin>>s>>e;
        int ans=2e12;
        for(int i=0;i<ed[s].size();i++)
        {
            for(int j=0;j<ed[e].size();j++)
            {
                node x=ed[s][i],y=ed[e][j];
                ans=min(ans,x.w+y.w+a[x.v][y.v]);
            }
        }
        cout<<ans+w[s]+w[e]<<endl;
    }
    return 0;
}
