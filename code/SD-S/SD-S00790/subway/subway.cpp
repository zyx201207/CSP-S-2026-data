#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int MAXM = 5e5+55, MAXN = 530;
const long long INF = 100000000000000000ll;
long long c, n, m, d, q, k;
long long w[MAXM], dis[MAXN][MAXN];
vector<long long> ind[MAXM], t[MAXM];
long long x, y, ans;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	// I
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		long long aa, tt;
		for(int j = 1;j <= k;j++)
		{
			cin >> aa >> tt;
			ind[aa].push_back(i);
			t[aa].push_back(tt);
		}
	}
	// III init
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++) dis[i][j] = INF;
	}
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	// II
	for(int i = 1;i <= m;i++)
	{
		int siz = ind[i].size();
		for(int u = 0;u < siz - 1;u++)
		{
			for(int v = u + 1;v < siz;v++)
			{
				dis[ind[i][u]][ind[i][v]] = min(dis[ind[i][u]][ind[i][v]], t[i][u] + t[i][v]);
				dis[ind[i][v]][ind[i][u]] = min(dis[ind[i][v]][ind[i][u]], t[i][u] + t[i][v]);
			}
		}
	}
	// III
	for(int u = 1;u <= n;u++)
	{
		for(int v = 1;v <= n;v++)
		{
			if(u == v) continue;
			for(int w = 1;w <= n;w++)
			{
				dis[u][v] = min(dis[u][v], dis[u][w] + dis[w][v]);
			}
		}
	}
	// IV
	while(q--)
	{
		cin >> x >> y;
		ans = INF;
		int sizx = ind[x].size(), sizy = ind[y].size();
		for(int u = 0;u < sizx;u++)
		{
			for(int v = 0;v < sizy;v++) ans = min(ans, t[x][u] + t[y][v] + dis[ind[x][u]][ind[y][v]]);
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
2 6

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 100 7 2
5 1 1 3 2 5 100 4 6 6 7
2 6
*/
