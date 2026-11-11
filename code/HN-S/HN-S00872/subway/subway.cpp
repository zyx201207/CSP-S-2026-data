#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], k, x, y, u, v;
vector <int> a[505];
vector <int> t[505];

bool f[500005];
long long dis[500005];

struct node
{
	int id;
	long long len;
};

bool operator > (node x, node y)
{
	return x.len > y.len;
}

void sssp_dijkstra()
{
	for(int i = 1; i <= m; i ++)
	{
		f[i] = false;
		dis[i] = 500000000000001;
	}
	priority_queue < node, vector <node>, greater <node>> q;
	dis[u] = 0;
	q.push({u, 0});
	for(; q.size() > 0; )
	{
		int tmp = q.top().id;
		q.pop();
		if(f[tmp] == true)
		{
			continue;
		}
		f[tmp] = true;
		for(int i = 1; i <= n; i ++)
		{
			int pos = -1;
			for(int j = 0; j <= a[i].size() - 1; j ++)
			{
				if(a[i][j] == tmp)
				{
					pos = j;
					goto A;
				}
			}
			if(false)
			{
				A:
				for(int j = 0; j <= a[i].size() - 1; j ++)
				{
					if(j == pos)
					{
						continue;
					}
					if(dis[tmp] + t[i][pos] + t[i][j] < dis[a[i][j]])
					{
						dis[a[i][j]] = dis[tmp] + t[i][pos] + t[i][j];
						q.push({a[i][j], dis[a[i][j]]});
					}
				}
			}
		}
	}
	return;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> k;
		for(int j = 1; j <= k; j ++)
		{
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i = 1; i <= q; i ++)
	{
		cin >> u >> v;
		sssp_dijkstra();
		cout << w[u] + dis[v] + w[v] << '\n';
	}
	return 0;
}
