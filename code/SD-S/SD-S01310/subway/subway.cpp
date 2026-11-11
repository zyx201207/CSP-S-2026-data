#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 5e5+10;
const int M = 500+10;
using namespace std;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		x = x*10+ch-'0',ch = getchar();
	return x*f;
}
vector<pii> g[N+M];
int w[N],n,m;

int dist[N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dij(int x)
{
	for(int i = 1;i<=m+n;++i)
	{
		vis[i] = 0;
		dist[i] = INF;
	}
	q.push({0,x});
	dist[x] = 0;
	while(!q.empty())
	{
		int u = q.top().se;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto e : g[u])
		{
			int v = e.fi,w = e.se;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
vector<int> num[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c = read();
	n = read();m = read();
	int d = read(),Q = read();
	for(int i = 1;i<=m;++i)
		w[i] = read();
	for(int i = 1;i<=n;++i)
	{
		int k = read(),id = m+i;
		for(int j = 1;j<=k;++j)
		{
			int a = read(),t = read();
			g[a].push_back({id,t});
			g[id].push_back({a,t});
		}
	}
	for(int i = 1;i<=n;++i)
	{
		dij(m+i);
		for(int j = 1;j<=m;++j)
			num[i].push_back(dist[j]);
	}
	while(Q--)
	{
		int x = read(),y = read();
		int ans = INF;
		for(int i = 1;i<=n;++i)
		{
			ans = min(ans,num[i][x-1] + num[i][y-1]);
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}

