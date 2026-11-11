#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e2+10,M=5e5+10;
int a[M],t[M];
struct node
{
	int v,w;
};
vector<node> g[M];
int dis[M],vis[M];
int w[M],k[N];
int c,n,m,d,q;
void spfa(int x)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto f:g[u])
		{
			int v=f.v,w=f.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(vis[v]==0)
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c<=11)
	{
		for(int i=1; i<=m; i++) cin>>w[i];
		for(int i=1; i<=n; i++)
		{
			cin>>k[i];
			for(int j=1; j<=k[i]; j++)
				cin>>a[j]>>t[j];
			for(int j=1; j<k[i]; j++)
			{
				for(int l=j+1; l<=k[i]; l++)
				{
					int u=a[j],v=a[l],w=t[j]+t[l];
					g[u].push_back({v,w});
					g[v].push_back({u,w});
				}
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			spfa(x);
			cout<<dis[y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
