#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int c,n,m,d,q,k[N],w[N],a[N][N],t[N][N],dis[N][N];
bool vis[N];
struct edge
{ 
	int to,w; 
}; 
struct node 
{ 
	int x,ans; 
	bool operator <(const node &a) const 
	{ 
		return a.ans<ans; 
	} 
};
vector<edge>v[N]; 
void dijkstra(int st) 
{ 
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	dis[st][st]=0;
	q.push({st,0}); 
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		if(vis[x.x]) continue;
		vis[x.x]=1;
		for(auto i:v[x.x])
		{
			int k=i.to,w=i.w;
			if(dis[st][k]>x.ans+w)
			{
				dis[st][k]=x.ans+w;
				q.push({k,x.ans+w});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j) cin>>a[i][j]>>t[i][j];
		for(int x=1;x<=k[i];++x)
		for(int y=x+1;y<=k[i];++y)
		{
			v[a[i][x]].push_back({a[i][y],t[i][x]+t[i][y]});
			v[a[i][y]].push_back({a[i][x],t[i][x]+t[i][y]});
		}
	}
	for(int i=1;i<=m;++i) dijkstra(i);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
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
*/
