#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v,w;
};
vector<edge> e[600001]; // 1~m1代表站厅，m1+1~m1+n1代表地铁线 
int c,n,m,d,q,a[500001],dis[600001],vis[600001],x,y;
struct node
{
	int no,dist;
	bool operator<(node b) const
	{
		return dist > b.dist;
	}
};
void dijkstra(int st)
{
	memset(dis,0x3f,sizeof(dis));memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({st,0});dis[st] = 0;
	while(!q.empty())
	{
		int u = q.top().no,distt = q.top().dist;q.pop();
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(auto v : e[u]) if(distt + v.w < dis[v.v]) dis[v.v] = distt + v.w,q.push({v.v,dis[v.v]});
	}
}
void go_work()
{
	cin >> x >> y;
	dijkstra(x);
	cout << a[x] + a[y] + dis[x] << "\n";
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1,k;i <= n;i++)
	{
		cin >> k;
		for(int j = 1,v,w;j <= k;j++) cin >> v >> w,e[m + i].push_back({v,w}),e[v].push_back({m + i,w}); // u就是线路，即m1+i
	}
	while(q--) go_work();
	return 0;
}
