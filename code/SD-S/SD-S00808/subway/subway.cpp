#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int N = 505, M = 500510, Q = 100005;
constexpr long long inf = 0x3f3f3f3f3f3f3f3f;
long long read();
int c, n, m, d, q;
long long w[N], dis[M], ans[Q];
struct Node
{
	int to;
	long long val;
	bool operator<(const Node &other) const
	{
		return val > other.val;
	}
};
vector<Node> adj[M];
struct Query
{
	int x, y, id;
	bool operator<(const Query &other) const
	{
		return x < other.x;
	}
} qs[Q];

void solve(int st)
{
	for (int i = 1; i <= m; i++)
	{
		dis[i] = inf;
	}
	priority_queue<Node> pq;
	pq.emplace(Node{st, 0});
	dis[st] = 0;
	while (!pq.empty())
	{
		int now = pq.top().to;
		pq.pop();
		for (Node e : adj[now])
		{
			if (dis[e.to] > dis[now] + e.val)
			{
				dis[e.to] = dis[now] + e.val;
				pq.emplace(Node{e.to, dis[e.to]});
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
	{
		w[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		int k = read();
		if (k == 2)
		{
			int a = read(), b = read();
			long long t1 = read(), t2 = read();
			adj[a].emplace_back(Node{b, t1 + t2});
			adj[b].emplace_back(Node{a, t1 + t2});
			continue;
		}
		m++;
		for (int j = 1; j <= k; j++)
		{
			int a = read();
			long long t = read();
			adj[a].emplace_back(Node{m, t});
			adj[m].emplace_back(Node{a, t});
		}
	}
	for (int i = 1; i <= q; i++)
	{
		qs[i].x = read(), qs[i].y = read();
		if (qs[i].x > qs[i].y)
		{
			swap(qs[i].x, qs[i].y);
		}
		qs[i].id = i;
	}
	sort(qs + 1, qs + q + 1);
	for (int i = 1; i <= n; i++)
	{
		if (qs[i].x != qs[i - 1].x)
		{
			solve(qs[i].x);
		}
		ans[qs[i].id] = dis[qs[i].y] + w[qs[i].x] + w[qs[i].y]; 
	}
	for (int i = 1; i <= q; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}
long long read()
{
	long long res = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
