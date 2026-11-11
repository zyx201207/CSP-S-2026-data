#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int M=5e5+10;
struct node{
	int x, dis;
	bool operator < (const node &y) const{
		return y.dis<dis;
	}
};
vector<pair<int, int>> g[M];
int w[M], dis[1010][1010], m;
bool vis[M];
void dijkstra(int s)
{
	for(int i=1;i<=m;i++) vis[i]=0;
	dis[s][s]=0;
	priority_queue<node> q;
	q.push({s, 0});
	while(!q.empty())
	{
		int x=q.top().x;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto tmp:g[x])
		{
			int y=tmp.first, z=tmp.second;
			if(dis[s][y]>dis[s][x]+z)
			{
				dis[s][y]=dis[s][x]+z;
				if(!vis[y]) q.push({y, dis[s][y]});
			}
		}
	}
}
int bfs(int s, int t)
{
	for(int i=1;i<=m;i++) vis[i]=0;
	queue<pair<int, int>> q;
	q.push({s, 0});
	while(!q.empty())
	{
		int x=q.front().first, d=q.front().second;q.pop();
		if(x==t) return d;
		for(auto tmp:g[x])
		{
			int y=tmp.first, z=tmp.second;
			if(!vis[y]) q.push({y, d+z}), vis[y]=1;
		}
	}
	return -1;
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, d, q;
	cin>>c>>n>>m>>d>>q;
	memset(dis, 0x3f, sizeof dis);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int cnt, to, t;
		cin>>cnt;
		vector<pair<int, int>> v;
		for(int j=1;j<=cnt;j++) cin>>to>>t, v.push_back({to, t});
		for(int j=0;j<cnt;j++)
			for(int k=j+1;k<cnt;k++)
				g[v[j].first].push_back({v[k].first, v[j].second+v[k].second}), 
				g[v[k].first].push_back({v[j].first, v[j].second+v[k].second});
	}
	if(c>=12&&c<=19)
	{
		while(q--)
		{
			int x, y;
			cin>>x>>y;
			cout<<w[x]+bfs(x, y)+w[y]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=m;i++) dijkstra(i);
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<'\n';
	}
	return 0;
}