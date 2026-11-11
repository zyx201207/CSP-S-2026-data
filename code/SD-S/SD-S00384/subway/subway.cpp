#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int c,n,m,d,q;
int w[200005];
int a[500][505],t[505][505];
int dis[505];
struct node
{
	int id,w;
	friend bool operator < (node a,node b)
	{
		return a.w<b.w;
	}
};
int vis[505];
struct edge
{
	int v,w;
};
vector<edge> g[505];
int tt[505][505];
int ww[505][505];
int fi[505];
void dij(int s)
{
	priority_queue<node> pq;
	pq.push((node){s,0});
	memset(dis,0x3f,sizeof(dis));
	dis[s] = w[s];
//	vis[s] = 1; 
	fi[s] = 1;
	while(pq.size())
	{
		node tmp = pq.top();
		pq.pop();
		int u = tmp.id;
//		cout<<u<<endl;
//		if(vis[u])
//			continue;
		vis[u] = 1;
		for(auto t:g[u])
		{
			int w = t.w;
			int v = t.v;
//			cout<<v<<' '<<w<<endl;
			if(dis[u]+w<dis[v])
				fi[v] = 1,dis[v] = dis[u]+w,pq.push((node){v,dis[v]});
		}
	}
}
signed main()
{
	fast;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int i;
	for(i=1;i<=m;i++)
		cin>>w[i];
	for(i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int j;
		for(j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			tt[i][a] = tt[a][i] = t;
			g[i].push_back((edge){a,t});
			g[a].push_back((edge){i,t}); 
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		memset(fi,0,sizeof fi);
		dij(x);
		int ss = 0;
		for(i=x;i<y;i++)
		{
//			cout<<vis[i]<<' ';
			if(fi[i])
				ss += tt[i][i];
		}
		cout<<dis[y]+w[y]+ss<<endl;
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

