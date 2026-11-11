#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
using ll=long long;
int w[M],K[M];
ll dis[N][N];
pair<int,int>p[M][20];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=0;j<k;j++)
        {
            int pos,d;cin>>pos>>d;
            p[pos][K[pos]++]={i,d};
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) dis[i][j]=1e18;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<K[i];j++)
            for(int k=j+1;k<K[i];k++)
                if(p[i][j].first!=p[i][k].first)
                    dis[p[i][j].first][p[i][k].first]=min(dis[p[i][j].first][p[i][k].first],(ll)p[i][j].second+p[i][k].second),
                    dis[p[i][k].first][p[i][j].first]=min(dis[p[i][k].first][p[i][j].first],(ll)p[i][j].second+p[i][k].second);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int s,t;cin>>s>>t;
        ll ans=1e18;
        for(int i=0;i<K[s];i++)
            for(int j=0;j<K[t];j++)
                ans=min(ans,dis[p[s][i].first][p[t][j].first]+p[s][i].second+p[t][j].second);
        cout<<ans+w[s]+w[t]<<"\n";
    }
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<"\n";
}