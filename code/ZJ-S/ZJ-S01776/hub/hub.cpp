#include<bits/stdc++.h>
using namespace std;
int C,T,n,k,u,v,d[1000010],maxn;
bool st[1000010];
vector<int>g[1000010];
map<int,int>mp;
void dijkstra()
{
	memset(d,0x3f,sizeof d);
	memset(st,0,sizeof st);
	d[1]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,1});
	while(q.size())
	{
		auto u=q.top().second;
		q.pop();
		if(st[u])continue;
		st[u]=1;
		for(auto v:g[u])
		{
			if(d[v]>d[u]+1)
			{
				d[v]=d[u]+1;
				q.push({d[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		mp[d[i]]++;
		maxn=max(maxn,d[i]);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dijkstra();
		int t=1;
		for(int i=1;i<=maxn;i++)
		{
			if(mp[i]>=k)
			{
				t=i;break;
			}
		}
		cout<<t<<'\n';
	}
	return 0;
}