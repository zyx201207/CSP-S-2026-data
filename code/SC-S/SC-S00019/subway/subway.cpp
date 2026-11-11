#include <bits/stdc++.h>
using namespace std;

struct node
{
	int v, l;
};

vector<node> g[2005];
int n, m, q, d, dis[505][505];
int k[505], w[505];

void floyd()
{
	for (int i = 1; i <= n + m; i++) dis[i][i] = 0;
	for (int k = 1; k <= n + m; k++)
	{
		for (int i = 1; i <= n + m; i++)
		{
			for (int j = 1; j <= n + m; j++)
			{
				dis[i][j] = dis[j][i] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}
}

void work()
{
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) 
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) 
		{
			int x, y;
			cin >> x >> y;
			g[x + n].push_back({i, y});
			g[i].push_back({x + n, y});
			dis[x + n][i] = min(dis[x + n][i], y);
			dis[i][x + n] = min(dis[i][x + n], y);
		}
	}
	floyd();
	while(q--)
	{
		int st, ed;
		cin >> st >> ed;
		cout << dis[st + n][ed + n] + w[st] + w[ed] << endl;
	}
	return;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t;
	cin >> t;
	cin >> n >> m >> d >> q;
	work();
	return 0;
}