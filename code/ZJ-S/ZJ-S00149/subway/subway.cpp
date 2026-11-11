#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 2e4 + 10;
#define pii pair<int, int>
int c, n, m, d, q;
int w[M];
int k[N];
int tim[M][N];
vector<pii> g[M];
int ans;
int vis[M][N];
vector<int> xianlu[M];
void dfs(int u, int xian, int des, int t)
{
//	cout << "u:" << u << " xian:" << xian << " des:" << des << " t:" <<t << endl;
	if(u == des)
	{
		t += tim[u][xian];
		ans = min(ans, t);
		return;
	}

	vis[u][xian] = t;
	for(auto & p : g[u])
	{
		int v = p.first, w = p.second;
		//	cout << "  v:" << v << " w:" << w << endl;
		if(w == xian)
		{
			if(vis[v][w] > t)
				dfs(v, xian, des, t);
		}
		else
		{
			if(vis[v][w] > t + tim[u][xian] + tim[u][w])
				//	cout << "  tim[v][xian]:" << tim[v][xian] << " tim[v][w]:" << tim[v][w] << endl;
				dfs(v, w, des, t + tim[u][xian] + tim[u][w]);
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		int lst = 0;
		for(int j = 1; j <= k[i]; j++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			if(lst != 0)
			{
				g[lst].push_back({tmp1, i});
				g[tmp1].push_back({lst, i});
			}
			xianlu[tmp1].push_back(i);
			tim[tmp1][i] = tmp2;
			lst = tmp1;
		}
	}
	while(q--)
	{
		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= n; j++)
				vis[i][j] = 2147483647;
		ans = 2147483647;
		int x, y;
		cin >> x >> y;
		for(auto & p : xianlu[x])
		{
			dfs(x, p, y, tim[x][p]);
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}

