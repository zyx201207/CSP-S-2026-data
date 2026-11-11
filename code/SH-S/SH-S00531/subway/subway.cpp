#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int w[500010], k[510], a[510][20010], t[510][20010];

struct node
{
	int b, t;
};

vector<pair<int, int>> g[20010][510];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			if(j == 1)
				continue;
			g[a[i][j]][i].push_back({a[i][j - 1], 0});
			g[a[i][j - 1]][i].push_back({a[i][j], 0});
		}
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		cout << ans << endl;
	}
	return 0;
}
