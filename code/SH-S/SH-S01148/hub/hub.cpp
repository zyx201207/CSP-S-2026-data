#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,k;
vector<int> g[1000005];
int dis[1000005];
int tot[1000005];
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		pair<int,int> tmp=pq.top();
		pq.pop();
		int d=tmp.first,u=tmp.second;
		if(d!=dis[u]) continue;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			dij(i);
			for(int j=1;j<=n;j++) tot[i]+=dis[j];
		}
		sort(tot+1,tot+n+1,greater<int>());
		cout<<tot[k+1]/(n-k+1)<<endl;
	}
	return 0;
} 
