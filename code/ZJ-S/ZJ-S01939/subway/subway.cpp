#include<bits/stdc++.h>
using namespace std;
const int M(5e5+5),N(505);
int c,n,m,D,Q;
int W[M];
struct bridge
{
	long long to,w;
};
vector<bridge> d[M+N];
long long dist[N][N],edge[N][N];
void addedge(int u,int v,int w)
{
	d[u].emplace_back((bridge){v,w});
}
struct node
{
	int now;
	long long val;
};
priority_queue<node> q;
long long dis[M+N]; 
bool operator < (const node &x,const node &y)
{
	return x.val > y.val;
}
vector<bridge> road[M+N];
void dijsktra()
{
	while(!q.empty())
	{
		int now(q.top().now);
		long long val(q.top().val);
		q.pop();
		if(val^dis[now]) continue;
		for(auto eeee:road[now])
		{
			if(dis[eeee.to] > val+eeee.w)
			{
				dis[eeee.to] = val+eeee.w;
				q.emplace((node){eeee.to,dis[eeee.to]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> D >> Q;
	for(int i(1);i <= m;++i) cin >> W[i];
	for(int i(1),k;i <= n;++i)
	{
		cin >> k;
		for(int j(1),to,w;j <= k;++j)
		{
			cin >> to >> w;
			addedge(m+i,to,w);
			addedge(to,m+i,w);
		}
	}
	memset(edge,0x3f,sizeof edge);
	for(int i(1);i <= m;++i) for(auto edge1:d[i]) for(auto edge2:d[i])
	{
		int x(edge1.to-m);
		int y(edge2.to-m);
		if(x == y) continue;
		edge[x][y] = min(edge[x][y],edge1.w+edge2.w*1ll);
		edge[y][x] = min(edge[y][x],edge1.w+edge2.w*1ll);
	}
	for(int i(1);i <= n;++i) for(int j(1);j <= n;++j)
	{
		if(edge[i][j] < 1e18)
		road[i+m].emplace_back((bridge){j+m,edge[i][j]}); 
	}
	for(int i(1);i <= n;++i)
	{
		while(!q.empty()) q.pop();
		memset(dis,0x3f,sizeof dis);
		dis[m+i] = 0;
		q.emplace((node){m+i,0});
		dijsktra();
		for(int j(1);j <= n;++j) dist[i][j] = dis[m+j];
	}
	for(int i(1),x,y;i <= Q;++i)
	{
		cin >> x >> y;
		long long ans(1e18);
		for(auto edge1:d[x]) for(auto edge2:d[y])
		{
			ans = min(ans,dist[edge1.to-m][edge2.to-m]+edge1.w+edge2.w+W[x]+W[y]);
		}
		cout << ans << "\n";
	}
	return 0; 
}
