#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[5005],ans[5005][5005],q[5005][505]; 
struct node
{
	int a,t;
};
vector<node> g[505],ab[5005];
void dfs(int st,int u,int c)
{
	for(auto h:ab[u])
	{
		int type=h.a,t=h.t;
		for(auto v:g[type])
			if(v.a!=u&&ans[st][v.a]>c+t+q[v.a][type])
			{
				ans[st][v.a]=c+t+q[v.a][type];
				dfs(st,v.a,ans[st][v.a]);
			}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	memset(ans,0x3f,sizeof ans);
	cin>>n>>n>>m>>k>>k;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			g[i].push_back({x,y});
			ab[x].push_back({i,y});
			q[x][i]=y;
		}
	}
	for(int i=1;i<=m;i++)
		dfs(i,i,0);
	for(int i=1;i<=k;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+ans[u][v]<<endl;
	}
	return 0;
}
