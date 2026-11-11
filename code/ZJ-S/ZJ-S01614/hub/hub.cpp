#include <iostream>
#include <vector>
#include <set> 
#include <queue>
#define big long long
using namespace std;
big _,T,n,k,head[1000006],cnt;
big mp[103][103],fa[103],vis[103],dis[103];
big find(big x) { return fa[x]==x? x: fa[x]=find(fa[x]); }
set <big> roots;
struct Edge{
	big next,to;
}edge[2000006];
void add_edge(big u,big v)
{
	edge[++cnt] = {head[u],v};
	head[u] = cnt;
}
struct Connected{
	big u,v;
}con[1000006];
// 先拿 15 分：暴力枚举
bool ok(big x)
{
	big ret = 0;
	while(x)
	{
		ret += (x&1);
		x >>= 1;
	}
	return ret == k;
}
struct Node{
	big p,val;
	friend bool operator < (const Node &l, const Node &r) { return l.val > r.val; }
}; priority_queue <Node> q;
void Dijkstra(big st)
{
	q.push({st,dis[st]=0});
	while(!q.empty())
	{
		big u = q.top().p; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(big i = head[u],v;i ;i = edge[i].next)
		{
			v = edge[i].to;
			if(vis[v]) continue;
			if(dis[u]+1 <= dis[v]) q.push({v,dis[v]=dis[u]+1});
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&_,&T);
	while(T--)
	{
		big ans = 1e18;
		scanf("%lld %lld",&n,&k);
		for(big i = 1;i <= n;i++) for(big j = 1;j <= n;j++) mp[i][j] = 0;
		for(big i = 1;i <= n;i++) head[i] = 0;
		cnt = 0;
		for(big i = 1,x,y;i < n;i++)
		{
			scanf("%lld %lld",&x,&y);
			add_edge(x,y), add_edge(y,x);
			con[i] = {x,y};
			mp[x][y] = 1;
		}
		for(big st = 0;st < (1<<n);st++)
		{
			if(!ok(st)) continue;
			// 选了 k 座城市
			vector <big> pos;
			for(big i = 0;i < n;i++)
			{
				if((st>>i)&1) pos.push_back(i+1);
			}
			for(big i = 1;i <= n;i++)
			{
				fa[i] = i; // 初始化 
				vis[i] = 0;
				dis[i] = 1e18;
			}
			for(auto x: pos)
			{
				for(auto y: pos)
				{
					if(x == y) continue;
					if(mp[x][y])
					{
						big ru = find(x), rv = find(y);
						if(ru != rv) fa[ru] = rv;
					}
				}
			}
			roots.clear();
			for(auto x: pos) roots.insert(find(x));
			if(roots.size() > 2) continue;
			big maxx = 0;
			
			for(big i = 1;i <= n;i++)
			{
				for(big j = 1;j <= n;j++)
				{
					 // 初始化 
					vis[j] = 0;
					dis[j] = 1e18;
				}
				Dijkstra(i);
				big minx = 1e18;
				for(auto u: pos) minx = min(minx,dis[u]);
				maxx = max(maxx,minx);
			}
			ans = min(ans,maxx);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
