#include <bits/stdc++.h> //dij%%% 14:57 - 15:53   56 min
using namespace std;
#define ll long long
#define PII pair <ll,int>
#define se second

const int M=5e5+5,N=505;
int cwz,n,m,d,que,S,T;
struct node{
    int sub,t;
};
vector <node> c[M],g[N];
ll tim[N][N],dis[N][N];
int k[N],w[M];
bool vis[N];

priority_queue <PII,vector<PII>,greater<PII>> q;

void dij(int st)
{
    q.push({0,st});
    dis[st][st]=0;
    for(int i=1;i<=n;i++) vis[i]=0;
    while(!q.empty())
    {
        PII h=q.top(); q.pop();
        int u=h.se;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto nxt:g[u])
        {
            int v=nxt.sub,w=nxt.t;
            if(dis[st][u]+w<dis[st][v])
            {
                dis[st][v]=dis[st][u]+w;
                q.push({dis[st][v],v});
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>cwz>>n>>m>>d>>que;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            tim[i][j]=1e18,dis[i][j]=1e18;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1,a,t;j<=k[i];j++)
        {
            cin>>a>>t;
            c[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        int l=c[i].size();
        for(int j=0;j<l;j++)
        {
            for(int k=0;k<l;k++)
            {
                if(j==k) continue;
                int u=c[i][j].sub,w1=c[i][j].t;
                int v=c[i][k].sub,w2=c[i][k].t;
                tim[u][v]=min(tim[u][v],1ll*w1+w2);
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(tim[i][j]!=1e18)
            {
                g[i].push_back({j,tim[i][j]});
                g[j].push_back({i,tim[i][j]});
            }
        }
    }
    for(int i=1;i<=n;i++) dij(i);
    while(que--)
    {
        ll ans=2e18;
        cin>>S>>T;
        for(auto p1:c[S])
        {
            for(auto p2:c[T])
            {
                int u=p1.sub,v=p2.sub,w1=p1.t,w2=p2.t;
                ans=min(ans,dis[u][v]+w1+w2);
            }
        }
        cout<<ans+w[S]+w[T]<<endl;
    }
    return 0;
}
