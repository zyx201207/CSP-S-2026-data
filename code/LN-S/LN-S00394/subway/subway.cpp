#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N];
vector<pair<int,int>> g[N*2];
int dist[N*2];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<pair<int,int>>ss[N];
int f[N];
long long ff[N];
void Dijstra(int s)
{
	memset(dist,0x3f,sizeof dist);
	pq.emplace(0,s);
	dist[s]=0;
	while(!pq.empty())
	{
		auto d=pq.top();
		pq.pop();
		int u;
		u=d.second;
		if(d.first>dist[u])continue;
		for(auto e:g[u])
		{
			int v=e.first;
			int val=e.second;
			if(dist[v]>dist[u]+val)
			{
				dist[v]=dist[u]+val;
				pq.emplace(dist[v],v);
			}
		}
	}
	
	//cout<<dist[t]+w[s]+w[t]<<endl;
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,val;
			int pp=N+i;
			cin>>v>>val;
			g[pp].emplace_back(v,val);
			g[v].emplace_back(pp,val);
		}
		/*for(int j=1;j<=k;j++)
		{
			for(int p=1;p<=k;p++)
			{
				if(j!=p)
				{
					int ww=b[i][j]+b[i][p];
					g[j].emplace_back(p,ww);
				}
			}
		}*/
	}
	for(int i=1;i<=q;i++)
	{

		int s,t;
		cin>>s>>t;
		ss[s].emplace_back(t,i);
		f[s]++;
	}
	for(int s=1;s<=m;s++)
	{
		if(f[s]!=0)
		{
			Dijstra(s);
			for(auto h:ss[s])
			{
				int t=h.first,pl=h.second;
				
				ff[pl]=dist[t]+w[s]+w[t];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ff[i]<<endl;
	}
	
	return 0;
}
