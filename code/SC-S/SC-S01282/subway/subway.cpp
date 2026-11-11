#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 505;
const int maxm = 5e5 + 5;
int c, n, m, d, q;
int k;
int a, t;
int x, y;
int wn[maxm];
struct hallway
{
	int st;
	int ti;
};
vector<hallway>v[maxm];
long long dist[maxn][maxn];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &wn[i]);
		//cin >> wn[i];
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		//cin >> k;
		for (int j = 1; j <= k; j++)
		{
			scanf("%d %d", &a, &t);
			//cin >> a >> t;
			v[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			for (int k = j + 1; k < v[i].size(); k++)
			{
				int u = v[i][j].st, w = v[i][k].st;
				if (dist[u][w] > v[i][j].ti + v[i][k].ti)
				{
					dist[u][w] = v[i][j].ti + v[i][k].ti;
					dist[w][u] = dist[u][w];
				}
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (dist[i][k] == 0x3f3f3f3f3f3f3f3f) continue;
			for (int j = 1; j <= n; j++)
			{
				if (i == j || i == k || j == k) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--)
	{
		scanf("%d %d", &x, &y);
		//cin >> x >> y;
		int sub1, sub2;
		long long ans = 9e18;
		for (int i = 0; i < v[x].size(); i++)
		{
			for (int j = 0; j < v[y].size(); j++)
			{
				int u = v[x][i].st, w = v[y][j].st;
				ans = min(ans, dist[u][w] + v[x][i].ti + v[y][j].ti);
			}
		}
		printf("%lld\n", ans + wn[x] + wn[y]);
		//cout << ans + wn[x] + wn[y] << endl;
	}
	return 0;
}