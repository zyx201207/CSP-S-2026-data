#include<bits/stdc++.h>
using namespace std;
struct node
{
	int tt;
	int dis;
};
int c,n,m,d,q,u,v,k,st,ed,mx;
vector<node> g[501];
bool vis[501];
void dfs(int now,int endd,int step)
{
	if(now==endd)
	{
		mx=max(mx,step);
		return;
	}
	if(step>=mx&&mx!=INT_MIN) return;
	for(auto t:g[now])
	{
		if(vis[t.tt]==0)
		{
			vis[t.tt]=1;
			dfs(t.tt,endd,step+t.dis);
			vis[t.tt]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>u;
		g[i].push_back({m+i,u});
		g[m+i].push_back({i,u});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k>>u>>v;
		int la=u;
		g[u+m].push_back({u+(1+i)*m,v});
		g[u+(1+i)*m].push_back({u+m,v});
		for(int j=2;j<=k;j++)
		{
			cin>>u>>v;
			g[u+m].push_back({u+(1+i)*m,v});
			g[u+(1+i)*m].push_back({u+m,v});
			g[u+(1+i)*m].push_back({la+(1+i)*m,0});
			g[la+(1+i)*m].push_back({u+(1+i)*m,0});
		}
	}
	for(int i=1;i<=q;i++)
	{
		mx=INT_MIN;
		memset(vis,0,sizeof(vis));
		cin>>st>>ed;
		vis[st]=1;
		dfs(st,ed,0);
		cout<<mx<<"\n";
	}
	return 0;
}
