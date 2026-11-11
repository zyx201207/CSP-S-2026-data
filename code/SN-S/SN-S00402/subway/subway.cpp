//SN-S00402 把小煜 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
vector<pair<int,int> >g[5010];
int dis[5010][5010];
priority_queue<pair<int,int> >qu;
void dji(int s)
{
	qu.push({0,s}); dis[s][s]=0;
	while(qu.size())
	{
		int u=qu.top().second,d=-qu.top().first;
		qu.pop();
		if(dis[s][u]<d) continue;
		for(auto p:g[u])
		{
			int v=p.first,w=p.second;
			if(dis[s][v]>d+w)
			{
				dis[s][v]=d+w;
				qu.push({-dis[s][v],v});
			}
		}
	}
}
void solve()
{
	int s,t; cin>>s>>t;
	if(dis[s][t]) cout<<dis[s][t]<<"\n";
	else
	{
		memset(dis[s],0x3f,sizeof(dis[s]));
		dji(s);
		cout<<dis[s][t]<<"\n";
	}
}
void add(int u,int v,int w)
{
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int x; cin>>x;
		add(i,i+m,x);
	}
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t; cin>>a>>t;
			add(a+m,i+m+m,t);
		}
	}
	while(q--) solve();
	return 0;
}
