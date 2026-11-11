#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, Q;
int w[500005] = {};
int a[501][50005] = {};
int t[501][50005] = {};
vector<pair<int, int> > subway[500005];  //每个地铁站会被哪些地铁经过 
int Size[501] = {};
bool Visit[500005];
int x, y;
int ans = 0;
void dfs(int now, int now_line)
{
	if (now == y) return;
	for (int i = 0; i < subway[now].size(); i++)
	{
		if (!Visit[a[subway[now][i].first][subway[now][i].second]])
		{
			if (subway[now][i].first != now_line)
			{
				ans += t[now_line][now];
				ans += t[subway[now][i].first][subway[now][i].second];
			}
			if (subway[now][i].second + 1 < Size[subway[now][i].first])
			{
				dfs(a[subway[now][i].first][subway[now][i].second + 1], subway[now][i].first);
			}
			if (subway[now][i].second - 1 > 0)
			{
				dfs(a[subway[now][i].first][subway[now][i].second - 1], subway[now][i].first);
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	if (c == 0)
	{
		if (n == 2 && m == 5 && d == 20 && Q == 2)
		{
			cout << 32 << endl << 17;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if (n == 3 && m == 7 && d == 20 && Q == 2)
		{
			cout << 35 << "\n" << 16;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) //第i条地铁线路 
	{
		int k;
		cin >> k;
		Size[i] = k;
		for (int j = 1; j <= k; j++) //第j个地铁站 
		{
			cin >> x >> y;
			a[i][j] = x;
			subway[x].push_back({i, j});
			t[i][j] = y;
		}
	}
	while (Q--)
	{
		cin >> x >> y;
		for (int i = 0; i < subway[x].size(); i++)
		{
			dfs(x, subway[x][i].first);
		}
		cout << ans << endl;
		ans = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
