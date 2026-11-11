#include<bits/stdc++.h>
#define int long long
#define mk make_pair
using namespace std;

const int M = 5e5 + 10, D = 30, N = 510;

int c, n, m, d, q;
int w[M], t[M][D], num[M];
int e[M][D];
int dis[N][N];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dis, 0x3f, sizeof dis);
	memset(t, 0x3f, sizeof t);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dis[i][i] = 0;
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a;
			cin >> a;
			cin >> t[a][i];
			e[a][num[a]++] = i;
		}
	}
//	cout << "ok" << " " << sizeof(e) / 1024/1024<< endl;
	for (int i = 1; i <= m; i++)
	{
//		cout << "dot: "<< i << " " << num[i]<< endl;
		for (int j = 0; j < num[i]; j++)
		{
			for (int k = 0; k < j; k++)
			{
//				cout << k << " " << j << endl;
//				cout << i << " " << k << " " << j << " " << t[i][e[i][j]] << " " << t[i][e[i][k]] << endl;
				dis[e[i][j]][e[i][k]] = dis[e[i][k]][e[i][j]] = min(dis[e[i][j]][e[i][k]], t[i][e[i][j]] + t[i][e[i][k]]);
			}
		}
	}
//	cout << "ok" << endl;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
//				cout << i << " " << j << endl;
			}
		}
	}
//	cout << "tst" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			cout << j << " " << i << " " << dis[i][j] << endl;
//		}
//	}
//cout << "ok" << endl;
	while (q--)
	{
		int x, y;
		int ans = LONG_LONG_MAX;
		cin >> x >> y;
//		int num1 = e[x].size(), num2 = e[y].size();
		for (int i = 0; i < num[x]; i++)
		{
			for (int j = 0; j < num[y]; j++)
			{
				if (t[x][e[x][i]] + t[y][e[y][j]] + dis[e[x][i]][e[y][j]] < ans)
				{
					ans = t[x][e[x][i]] + t[y][e[y][j]] + dis[e[x][i]][e[y][j]];
				}
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
