#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 5e5 + 5;
struct node
{
	int v, w;
};
int c, n, m, d, q, w[N], a, t, k, b[N];
vector<node> G[N];
void dij(int x)
{
	queue<node> q;
	for (auto i : G[x]) q.push(i);
	while (!q.empty())
	{
		int u = q.front().v;
		for (int i = 0; i < G[u].size(); i ++)
		{
			int v = G[u][i].v, w = G[u][i].w;
			if (b[v] + w < b[u]) b[u] = b[v] + w, q.push(G[u][i]);
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++)
	{
		cin >> k;
		int lsta, lstt;
		for (int j = 1; j <= k; j ++)
		{
			cin >> a >> t;
			if (j != 1) G[lsta].push_back((node){a, lstt});
			lsta = a, lstt = t;
		}
	}
	for (int i = 1; i <= n; i ++) memset(G, 0, sizeof(G)), dij(i); 
	return 0;
}
