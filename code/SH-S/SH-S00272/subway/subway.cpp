#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=0x3f3f3f3f;
ll d[510],w[500010],vis[510],a[500010],t[500010];
vector<pair<ll,ll> >g[500010];
ll solve(int s,int t)
{
	priority_queue<pair<ll,ll> >pq;
	memset(vis,0,sizeof(vis));
	memset(d,INF,sizeof(d));
	pq.push({0,s});
	d[s]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first,w=g[u][i].second;
			if(!vis[v]&&d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				pq.push({-d[v],v});
			}
		}
	}
	return d[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%lld%lld",&a[j],&t[j]);
			//cout<<k<<" "<<a[j]<<"\\"<<t[j]<<"\n";
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				g[a[j]].push_back({a[l],t[j]+t[l]});
				g[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		//cout<<x<<" "<<y<<" ";
		printf("%lld\n",solve(x,y)+w[x]+w[y]);
	}
}
