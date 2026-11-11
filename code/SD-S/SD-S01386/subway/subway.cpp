// subway

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
const int inf = 0x3f3f3f3f;

struct Node {
	int i, w;
};
int c, n, m, d, q;
int w[500010];
std::vector<Node> G[500010];
int dis[500010];
std::bitset<500008> in_q;
void bfs(int b, int e)
{
	std::queue<int> q;
	q.push(b);
	std::fill(dis + 1, dis + 1 + m, inf);
	in_q.set(0);
	dis[b] = 0;
	while (!q.empty())
	{
		int top = q.front();
		in_q[top] = 0;
		q.pop();
		for (auto it : G[top])
		{
			int nd = it.w + dis[top];
			if (nd < dis[it.i])
			{
				if (!in_q[it.i]) 
				{
					q.push(it.i);
					in_q[it.i] = 1;
				}
				dis[it.i] = nd;
			}
		}
	}
	std::cout << dis[e] + w[b] + w[e] << '\n';
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		std::cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		std::cin >> k;
		std::vector<Node> vec;
		for (int j = 1; j <= k; j++)
		{
			int v, w;
			std::cin >> v >> w;
			vec.push_back({v, w});
		}
		for (int u = 0; u < k - 1; u++)
		{
			for (int v = u + 1; v < k; v++)
			{
				G[vec[u].i].push_back({vec[v].i, vec[u].w + vec[v].w});
				G[vec[v].i].push_back({vec[u].i, vec[u].w + vec[v].w});
			}
		}
	}
	
//	for (int i = 1; i <= m; i++)
//	{
//		fprintf(stderr, "G[%d]: ", i);
//		for (auto it : G[i])
//		{
//			fprintf(stderr, "(%2d,%2d) ", it.i, it.w);
//		}
//		fprintf(stderr, "\n");
//	}
	while (q--)
	{
		int u, v;
		std::cin >> u >> v;
		bfs(u, v);
	}
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

