#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define pb push_back
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int tid,n,m,d,q,w[500010];
ll dis[510][510];
vector<pii>g[500010];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>tid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        while(c--)
        {
            int x,t;
            cin>>x>>t;
            g[x].pb({i,t});
        }
    }
    for(int i=1;i<=m;i++)
        for(auto x:g[i])for(auto y:g[i])
        {
            int u=x.fir,v=y.fir;ll d=x.sec+y.sec;
            chmin(dis[u][v],d);
            chmin(dis[v][u],d);
        }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        chmin(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        ll ans=inf;
        for(auto x:g[u])for(auto y:g[v])
        {
            int p=x.fir,q=y.fir;ll d=x.sec+y.sec;
            chmin(ans,dis[p][q]+d);
        }
        ans+=w[u]+w[v];
        cout<<ans<<'\n';
    }
    return 0;
}
/*
Are you going to Scarborough Fair?
*/