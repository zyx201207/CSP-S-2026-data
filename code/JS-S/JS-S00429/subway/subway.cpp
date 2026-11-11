//rp++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005,inf=1e18;
int c,n,m,d,q,w[N],k,a,t,x,y;
int dis[505][505],dp[505][505];
vector<pair<int,int>>g[N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        int sz=g[i].size();
        //cout<<i<<' '<<sz<<'\n';
        for(int j=0;j<sz-1;j++)
        {
            for(int k=j+1;k<sz;k++)
            {
                int jf=g[i][j].first,js=g[i][j].second,
                    kf=g[i][k].first,ks=g[i][k].second;
                    //cout<<jf<<' '<<js<<' '<<kf<<' '<<ks<<'\n';
                dis[jf][kf]=dis[kf][jf]=min(dis[jf][kf],js+ks);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=dis[i][j];
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--)
    {
        cin>>x>>y;
        int s1=g[x].size(),s2=g[y].size(),ans=inf;
        for(int i=0;i<s1;i++)
            for(int j=0;j<s2;j++)
            {
                int jf=g[x][i].first,js=g[x][i].second,
                    kf=g[y][j].first,ks=g[y][j].second;
                ans=min(ans,dp[jf][kf]+js+ks);
            }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
//Floyd shi gay.
