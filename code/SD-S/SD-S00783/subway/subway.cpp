#include<bits/stdc++.h>
#define inf 1e18
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
const int N=6e5+10,M=510;
int c,n,m,q,d;
int w[N];
ll f[N],vis[N];
vector<pii>e[N],s[N];
ll dis[M][M];
priority_queue<pli,vector<pli>,greater<pli> >pq;
void dij(int id)
{
//	cout<<id<<"\n";
	for(int i=1;i<=n;i++)  f[i]=inf,vis[i]=0;
    f[id]=0;
    pq.push({0,id});
    while(!pq.empty())
    {
      int u=pq.top().se;
      pq.pop();
      if(vis[u])  continue;
      vis[u]=1;
      for(pii p:e[u])
      {
        int v=p.fi,w=p.se;
        if(f[u]+w<f[v])
        {
          f[v]=f[u]+w;
          pq.push({f[v],v});
		}
	  }
	}
//	for(int i=1;i<=n;i++)  cout<<f[i]<<" ";cout<<"\n";
	for(int i=1;i<=n;i++)  dis[id][i]=f[i];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)  cin>>w[i];
	for(int i=1;i<=n;i++)
	{
	  int k;
	  cin>>k;
	  for(int j=1,x,y;j<=k;j++)
	  {
	    cin>>x>>y;
	    s[x].emplace_back(i,y);
	  }
	}
//	cout<<"ok\n";
	for(int i=1;i<=m;i++)
	{
	  for(pii p:s[i])
	    for(pii q:s[i])
	    {
	      int w=p.se+q.se;
	      if(p!=q)
	      {
	        e[p.fi].emplace_back(q.fi,w);
	        e[q.fi].emplace_back(p.fi,w);
		  }
		}
	}
	for(int i=1;i<=n;i++)  dij(i);
	while(q--)
	{
	  int x,y;
	  ll ans=inf;
	  cin>>x>>y;
	  for(pii a:s[x])
	    for(pii b:s[y])
	      ans=min(ans,dis[a.fi][b.fi]+a.se+b.se);
	  ans+=w[x]+w[y];
	  cout<<ans<<"\n";
//	  cout<<e[x].size()<<" "<<e[y].size()<<"\n";
	}
	return 0;
}
