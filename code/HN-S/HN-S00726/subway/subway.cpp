#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 10,N = 510;
int c,n,m,d,q,w[M],dis[N];
bool vis[N];
struct Edge
{
	int v,ww;
};
vector<Edge> a[M];
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({w[s],s});
	dis[s] = w[s];
	while (!q.empty())
	{
		auto cur = q.top();
		q.pop();
		int d = cur.first,u = cur.second;
		if (vis[u])
		{
			continue;
		}
		vis[u] = 1;
		for (auto g : a[u])
		{
			int v = g.v,ww = g.ww;
			if (dis[v] > d + ww)
			{
				dis[v] = d + ww;
				q.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int k,last,lt;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int x,t;
			cin >> x >> t;
			if (j == 1)
			{
				lt = t;
				last = x;
				continue;
			}
			a[last].push_back({x,t + lt});
			last = x;
			lt = 0;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1; i <= q; i++)
	{
		int x,y;
		cin >> x >> y;
		dij(x);
		cout << dis[y] + w[y] << '\n';
	}
	return 0;
}

