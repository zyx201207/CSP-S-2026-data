#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,w[500010],a[505][50010],t[505][50010],x,y,k[500010];
vector<int>to[500010];
struct node{
	int sta,line,id;
};
queue<node>q;
bool vis[500010];
int ans[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	while(Q--)
	{
		memset(to,0x3f,sizeof(to));
		memset(vis,0x3f,sizeof(vis));
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>a[i][j]>>t[i][j];
				to[a[i][j]].push_back(i);
			}
			
		}
		memset(ans,0x3f,sizeof(ans));
		cin>>x>>y;
		for(int i=0;i<to[x].size();i++)
		{
			for(int j=1;j<=k[to[x][i]];j++)
			{
				q.push({a[to[x][i]][j],to[x][i],j});
				ans[a[to[x][i]][j]]=t[to[x][i]][j];
			}
		}
		while(q.empty())
		{
			node e=q.front();
			q.pop();
			if(!vis[e.sta])
			{
				vis[e.sta]=1;
				for(int i=0;i<to[e.line].size();i++)
				{
					for(int j=1;j<=k[to[e.sta][i]];j++)
					if(!vis[a[to[e.sta][i]][j]])
					{
						q.push({a[to[e.sta][i]][j],to[e.sta][i],j});
						ans[a[to[e.sta][i]][j]]=min(a[to[e.sta][i]][j],a[e.line][e.id]+t[e.line][e.id]+t[e.line][j]);
					}
					
				}
			}
		}
		cout<<ans[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
