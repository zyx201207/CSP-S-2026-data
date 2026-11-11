#include <bits/stdc++.h>
using namespace std;
constexpr int N = 505, M = 5e5 + 5, smallM = 1005;
using ll = long long;
struct station
{
	int a, t;
};
int m, w[N], k[N], T;
ll dis[smallM][smallM];
vector<station> st[N];
void floyd()
{
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		st[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++)
			cin >> st[i][j].a >> st[i][j].t;
		if (7 <= c && c <= 8 && k[i] == 2)
		{
			dis[st[i][1].a][st[i][2].a] = min(dis[st[i][1].a][st[i][2].a], (ll)st[i][1].t + st[i][2].t);
			dis[st[i][2].a][st[i][1].a] = min(dis[st[i][2].a][st[i][1].a], (ll)st[i][1].t + st[i][2].t);
		}
	}
	if (7 <= c && c <= 8)
	{
		floyd();
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (7 <= c && c <= 8)
		{
			cout << w[x] + w[y] + dis[x][y];
		}
		cout << '\n';
	}
	return 0;
}
