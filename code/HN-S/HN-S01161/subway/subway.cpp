#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct node
{
	int a,t;
};
int c,n,m,d,q;
int w[N];
vector<node>g[N];
vector<int>p[N];
int sum,z,ans;
bool vis[N];
bool f=0;
void dfs(int s,int e)
{
	queue<pair<int,int>>q;
	q.push({s,0});
	vis[s]=1;
	while(q.size())
	{
		pair<int,int>x=q.front();
		q.pop();
		int nx=x.first;
		if(nx==e)
		{
			if(!f)
			{
				f=1;
				ans=x.second;
			}
			else ans=min(ans,x.second+1);
		}
		for(int i=0;i<p[s].size();i++)
		{
			int u=p[s][i];//uÊÇÂ·Ïß 
			for(int j=0;j<g[u].size();j++)
			{
				int v=g[u][j].a;
				if(!vis[v])
				{
					vis[v]=1;
					q.push({v,x.second+1});
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			node y;
			cin>>y.a>>y.t;
			g[i].push_back(y);
			p[y.a].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(vis));
		int s,e;
		cin>>s>>e;
		dfs(s,e);
		ans=ans*g[1][1].t;
		cout<<ans<<'\n';
	}
	return 0;
}
