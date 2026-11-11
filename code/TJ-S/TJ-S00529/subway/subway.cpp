#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
long long w[2005], a[2005], b[2005], k[2005];
long long dis[2005];
bool f[2005];
struct node
{
	int v;
	long long w;
};
vector<node> g[200005];
struct Node
{
	int v;
	long long dis;
	bool operator<(const Node &B) const
	{
		return dis > B.dis;
	}
};
priority_queue<Node> q;
void dj(int s, int t)
{
	memset(dis, 0x3f3f3f3f3f3f3f3f, sizeof dis);
	memset(f, 0, sizeof f);
	q.push({s, 0});
	dis[s] = 0;
	while (!q.empty())
	{
		int x = q.top().v;
		q.pop();
		if (f[x]) continue;
		if (x == t) break;
		f[x] = 1;
		for (int i = 0; i < g[x].size(); ++i)
		{
			long long y = g[x][i].v, w = g[x][i].w;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				q.push({y, dis[y]});
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
		{
			cin >> a[j] >> b[j];
		}
		for (int j = 1; j < k[i]; ++j)
		{
			for (int s = j + 1; s <= k[i]; ++s)
			{
				int u = a[j], v = a[s], w = b[j] + b[s];
				g[u].push_back({v, w});
				g[v].push_back({u, w});
			}
		}
	}
	while (q--)
	{
		int s, t;
		cin >> s >> t;
		dj(s, t);
		cout << dis[t] + w[s] + w[t] << endl;
	}
	return 0;
}
