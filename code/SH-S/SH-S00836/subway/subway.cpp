#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int a[501][501], t[501][501], best[501];
int adj[1001][1001], w[501], cache[1001][1001];
bool visited[501], mem[1001][1001];
int c, n, m, d, q;
int dfs (int from, int to)
{
	if (from == to) return 0;
	if (mem[from][to]) return cache[from][to];
	if (visited[from]) return INF;
	visited[from] = true;
	int minn = INF;
	for (int i = 1; i <= m; i++)
	{
		if (adj[from][i] == INF) continue;
		int now = dfs(i, to);
		if (now == INF) continue;
		minn = min(minn, adj[from][i] + dfs(i, to));
	}
	visited[from] = false;
	return best[from] = min(best[from], minn);
}
int main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++) adj[i][j] = INF;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
		for (int j = 1; j <= k; j++)
		{
			for (int l = j + 1; l <= k; l++)
			{
				adj[a[i][j]][a[i][l]] = adj[a[i][l]][a[i][j]] = min(adj[a[i][j]][a[i][l]], t[i][j] + t[i][l]);
			}
		}
	}
	while (q--)
	{
		for (int i = 1; i <= 500; i++) best[i] = INF, visited[i] = false;
		int from, to;
		cin >> from >> to;
		cout << dfs(from, to) + w[from] + w[to] << "\n";
	}
	return 0;
}
