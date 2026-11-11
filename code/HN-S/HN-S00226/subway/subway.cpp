#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
struct bb
{
	int to,t;
};
vector<bb> g[500005];
int bfs(int l,int r)
{
	int vis[500005],ans=INT_MAX;
	memset(vis,0x3f,sizeof(vis));
	queue<bb> q;
	q.push({l,w[l]});
	while(q.size())
	{
		bb b=q.front();
		q.pop();
		if(b.to==r)
		{
			ans=min(ans,b.t);
		}
		for(int i=0;i<g[b.to].size();i++)
		{
			bb v=g[b.to][i];
			if(v.t+w[b.to]<vis[v.to])
			{
				vis[v.to]=v.t+w[b.to];
				q.push({v.to,vis[v.to]});
			}
		}
	}
	return ans;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			g[i].push_back({x,y});
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<bfs(l,r)<<"\n";
	}
	return 0;
}

