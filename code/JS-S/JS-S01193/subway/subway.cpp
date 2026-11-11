#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],K[505],N[500005];
struct info{int p,t;};
vector<info> a[500005];
int tot=1,ver[500005],head[500005],nxt[500005],val[500005];
void add(int x,int y,int z)
{
    ver[++tot]=y,nxt[tot]=head[x],head[x]=tot,val[tot]=z;
    //cout<<x<<' '<<y<<' '<<z<<'\n';
}
int d[505][505];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dij(int s)
{
    while(!q.empty())
    {
        pair<int,int> now=q.top();
        q.pop();
        int td=now.first,x=now.second;
        for(int i=head[x];i;i=nxt[i])
        {
            int y=ver[i];
            if(d[s][y]>d[s][x]+val[i])
            {
                d[s][y]=d[s][x]+val[i];
                q.push(make_pair(d[s][y],y));
            }
        }
    }
}
signed main()
{
    std::cin.sync_with_stdio(0);cin.tie();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C,n,m,D,Q;
    cin>>C>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>K[i];
        for(int j=1;j<=K[i];j++)
        {
            int x,y;
            cin>>x>>y;
            a[x].push_back({i,y});
        }
    }
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++)
        d[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        N[i]=a[i].size();
        for(int j=0;j<N[i];j++)
            for(int k=j+1;k<N[i];k++)
            {
                add(a[i][j].p,a[i][k].p,a[i][j].t+a[i][k].t);
                add(a[i][k].p,a[i][j].p,a[i][j].t+a[i][k].t);
            }
    }
    for(int i=1;i<=n;i++)
    {
        q.push(make_pair(0,i));
        dij(i);
    }
    while(Q--)
    {
        int s,t;
        cin>>s>>t;
        int ans=1e18;
        for(int j=0;j<N[s];j++)
            for(int k=0;k<N[t];k++)
                ans=min(ans,a[s][j].t+d[a[s][j].p][a[t][k].p]+a[t][k].t);
        printf("%lld\n",ans+w[s]+w[t]);
    }
    return 0;
}
