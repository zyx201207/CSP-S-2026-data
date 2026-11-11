#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int c_,m,n,d,q,vis[5005],f[505][505];
//int ans[5005][5005];
//struct node
//{
//	int u,d;
//	bool operator <(const node x)const
//	{
//		return d<x.d;
//	}
//};
//vector<int>g[500005],w[500005];
//void dij(int u,int *ans)
//{
//	for (int i=1;i<=5000;i++)
//	{
//		ans[i]=0x3f3f3f3f3f3f3f3f;
//	}
//	ans[u]=0;
//	priority_queue<node>q;
//	q.push({u,0});
//	int f=0;
//	if (u==112)
//	{
//		f=1;
//	}
//	for (int i=1;i<=5000;i++)
//	{
//		vis[i]=0;
//	}
//	while (!q.empty())
//	{
//		int u=q.top().u;
//		q.pop();
//		if (vis[u]==1)
//		{
//			continue;
//		}
//		if (f)
//		{
//			cerr<<u<<'\n';
//		}
//		vis[u]=1;
//		for (int i=0;i<g[u].size();i++)
//		{
//			int v=g[u][i];
//			if (ans[v]>ans[u]+w[u][i])
//			{
//				ans[v]=ans[u]+w[u][i];
//				q.push({v,ans[v]});
//			}
//			
//		}
//	}
//}
int w_0[500005];
vector<int>b[500005],c[500005];
#define DEB -1
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c_>>n>>m>>d>>q;
//	if (c_<=DEB)
//	{
//		int tot=1;
//		for (int i=1;i<=m;i++)
//		{
//			cin>>w_0[i];
//		}
//		for (int i=1;i<=n;i++)
//		{
//			int k,a,t,lst=0;
//			cin>>k;
//			for (int j=1;j<=k;j++)
//			{
//				cin>>a>>t;
//				if (j!=1)
//				{
//					g[lst].push_back(tot+m);
//					w[lst].push_back(0);
//					g[tot+m].push_back(lst);
//					w[tot+m].push_back(0);
//					g[tot+m].push_back(a);
//					w[tot+m].push_back(t);
//					g[a].push_back(tot+m);
//					w[a].push_back(t);
//					tot++;
//				}
//				else
//				{
//					g[tot+m].push_back(a);
//					w[tot+m].push_back(t);
//					g[a].push_back(tot+m);
//					w[a].push_back(t);
//					tot++;
//				}
//				lst=tot-1+m;
//			}
//		}
//		for (int i=1;i<=m;i++)
//		{
//			dij(i,ans[i]);
//		}
//		for (int Ti=1,x,y;Ti<=q;Ti++)
//		{
//			cin>>x>>y;
//			cout<<ans[x][y]+w_0[x]+w_0[y]<<'\n';
//		}
//	}
//	else
//	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				f[i][j]=inf;
			}
			f[i][i]=0;
		}
		for (int i=1;i<=m;i++)
		{
			cin>>w_0[i];
		}
		for (int i=1;i<=n;i++)
		{
			int k,a,t,lst=0;
			cin>>k;
			for (int j=1;j<=k;j++)
			{
				cin>>a>>t;
				b[a].push_back(i);
				c[a].push_back(t);
			}
		}
		for (int i=1;i<=m;i++)
		{
			for (int j=0;j<b[i].size();j++)
			{
				for (int k=0;k<b[i].size();k++)
				{
					f[b[i][j]][b[i][k]]=min(f[b[i][j]][b[i][k]],c[i][j]+c[i][k]);
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
				{
					f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
				}
			}
		}
		for (int Ti=1,x,y;Ti<=q;Ti++)
		{
			cin>>x>>y;
			int ans=inf;
			for (int i=0;i<b[x].size();i++)
			{
				for (int j=0;j<b[y].size();j++)
				{
					ans=min(ans,w_0[x]+w_0[y]+c[x][i]+c[y][j]+f[b[x][i]][b[y][j]]);
				}
			}
			cout<<ans<<'\n';
		}
		
//	}
	
//	else if (c<=11)
//	{
//		int tot=1;
//		for (int i=1;i<=m;i++)
//		{
//			cin>>w_0[i];
//		}
//		for (int i=1;i<=n;i++)
//		{
//			int k,a,t,lst=0;
//			cin>>k;
//			for (int j=1;j<=k;j++)
//			{
//				cin>>a>>t;
//				if (j!=1)
//				{
//					g[lst].push_back(tot+m);
//					w[lst].push_back(0);
//					g[tot+m].push_back(a);
//					w[tot+m].push_back(t);
//					g[a].push_back(tot+m);
//					w[a].push_back(t);
//					tot++;
//				}
//				else
//				{
//					g[tot+m].push_back(a);
//					w[tot+m].push_back(t);
//					g[a].push_back(tot+m);
//					w[a].push_back(t);
//					tot++;
//				}
//				lst=a+m;
//			}
//		}
//	}
	return 0;
}

