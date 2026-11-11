#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#define int long long
#define N 500007
using namespace std;
int c, n, m, d, q, w[N], dist[507][507];
vector <int> gl[N], gp[N];
vector <int> g[N];
queue <int> que;
int dis[507], ans[507][507];

struct node
{
	int idx, len;
	bool operator < (const node&other) const
	{
		return len > other.len;
	}
};


priority_queue <node, vector<node>> que2;

void bfs(int beg, int ed)
{
	while (!que.empty()) que.pop();
	dis[beg] = 1;
	que.push(beg);
	while (!que.empty())
	{
		int head = que.front();
		que.pop();
//		cout << dis[head] << "  head\n";
		for (int ne : g[head])
		{
			if (dis[ne] > dis[head] + 1)
			{
//				cout << dis[head] + 1 << "     jibajibajibajiba\n";
				dis[ne] = dis[head] + 1;
//				if (ne == ed) return;
				que.push(ne);
//				cout << dis[ne] << "         748598748\n";
			}
		}
	}
}

void bfs2(int beg, int ed)
{
	while (!que.empty()) que.pop();
	dis[beg] = 0;
	que2.push({beg, 0});
	while (!que2.empty())
	{
		node head1 = que2.top();
		int head = head1.idx;
		que2.pop();
		for (int ne : g[head])
		{
			if (dis[ne] > dis[head] + dist[ne][head])
			{
				dis[ne] = dis[head] + dist[ne][head];
				que2.push({ne, dis[ne]});
			}
		}
	}
}

void solveB()
{
	int T;
	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;
//		cout << 1;
		for (int j = 1; j <= cnt; j++)
		{
			int x;
			cin >> x >> T;
			gp[x].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int ne1 : gp[i])
		{
			for (int ne2 : gp[i])
			{
				if (ne1 != ne2)
				{
					g[ne1].push_back(ne2);
				}
			}
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= n; i++)
	{
		ans[i][i] = 0;
		for (int j = i + 1; j <= n; j++)
		{
			bfs(i, j);
			ans[i][j] = dis[j];
//			cout << dis[j] << " dajiba\n";
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int u, v;
		cin >> u >> v;
		int ans2 = 9178136991;
		for (int ne1 : gp[u])
		{
			for (int ne2 : gp[v])
			{
				if (ne1 > ne2) swap(ne1, ne2);
				ans2 = min(ans2, ans[ne1][ne2]);
			}
		}
		cout << (ans2) * 2 * T + w[u] + w[v] << "\n";
	}
}

signed main()
{
	freopen("subway1.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	if (c >= 12 && c <= 19)
	{
		solveB();
		return 0;
	}
	int t[m][n];
	for (int i = 1; i <= m; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++)
		{
			int x;
			cin >> x;
			cin >> t[x][i];
			gp[x].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int ne1 : gp[i])
		{
			for (int ne2 : gp[i])
			{
				if (ne1 != ne2)
				{
					g[ne1].push_back(ne2);
					dist[ne1][ne2] = dist[ne2][ne1] = t[i][ne1] + t[i][ne2];
				}
			}
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= n; i++)
	{
		ans[i][i] = 0;
		for (int j = i + 1; j <= n; j++)
		{
			bfs2(i, j);
			ans[i][j] = dis[j];
//			cout << dis[j] << " dajiba\n";
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int u, v;
		cin >> u >> v;
		int ans2 = 9178136991;
		for (int ne1 : gp[u])
		{
			for (int ne2 : gp[v])
			{
				if (ne1 > ne2) swap(ne1, ne2);
				ans2 = min(ans2, ans[ne1][ne2]);
			}
		}
		cout << ans2 + w[u] + w[v] << "\n";
	}
	return 0;
} 
