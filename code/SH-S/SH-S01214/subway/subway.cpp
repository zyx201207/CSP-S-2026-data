#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
long long w[500005];
int k[505];

long long path[505][505];

pair<int, long long> sts[500005][25];
int stscnt[500005]; 

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	memset(path, -1, sizeof(path));
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int a;
			long long t;
			cin >> a >> t;
			for (int l = 1; l <= stscnt[a]; l++)
			{
				int other = sts[a][l].first;
				if (path[other][i] == -1)
					path[other][i] = t + sts[a][l].second;
				else
					path[other][i] = min(path[other][i], t + sts[a][l].second);
			}
			sts[a][++stscnt[a]] = make_pair(i, t);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		path[i][i] = 0;
		for (int j = i + 1; j <= n; j++)
			path[j][i] = path[i][j];
	}
	for (int l = 1; l <= n; l++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (path[i][l] >= 0 && path[l][j] >= 0)
					if (path[i][j] == -1 || path[i][j] > path[i][l] + path[l][j])
						path[i][j] = path[i][l] + path[l][j];
	for (;q--;)
	{
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (int i = 1; i <= stscnt[x]; i++)
			for (int j = 1; j <= stscnt[y]; j++)
				if (path[sts[x][i].first][sts[y][j].first] >= 0)
					ans = min(ans, path[sts[x][i].first][sts[y][j].first] + sts[x][i].second + sts[y][j].second);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
	// 写下这行注释保我不被卡时限也不挂分awa 
}
