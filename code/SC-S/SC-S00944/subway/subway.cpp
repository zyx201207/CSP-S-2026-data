#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
int c,n,m,d,q,w[500005],k[500005],disa[2005][2005],visa[2005][2005],disb[200005],visb[200005];
vector<pii> g[500505];
void planA(int s)
{
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(disa[s],0x3f3f3f3f,sizeof(disa[s]));
	memset(visa[s],0,sizeof(visa[s]));
	disa[s][s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(visa[s][u]) continue;
		visa[s][u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(disa[s][v]>disa[s][u]+w)
			{
				disa[s][v]=disa[s][u]+w;
				q.push({disa[s][v],v});
			}
		 } 
	}
}
void planB(int s)
{
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(disb,0x3f3f3f3f,sizeof(disb));
	memset(visb,0,sizeof(visb));
	disb[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(visb[u]) continue;
		visb[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(disb[v]>disb[u]+w)
			{
				disb[v]=disb[u]+w;
				q.push({disb[v],v});
			}
		} 
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int u,x;
			cin>>u>>x;
			g[i+m].push_back({u,x});
			g[u].push_back({i+m,x});
		}
	}
	if(c<=11)
	{
		for(int i=1;i<=m;i++) planA(i);
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			cout<<disa[a][b]+w[a]+w[b]<<'\n'; 
		}
		return 0;
	}
	if(c<=15)
	{
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			planB(a);
			cout<<disb[b]+w[a]+w[b]<<'\n';
		}
	}
	return 0;
}
/*
exp:44pts
writer:1419936
*/
