#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 510;
const int maxm = 5e5 + 10;


ll c, n, m, d, q, w[maxm], x[maxn][maxn], t[maxn][maxn], huan[maxn], k[maxn];
vector<int> belong[maxn];
struct edge
{
	int to;
	ll cost;
};
vector<edge> g[maxn];

int main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k; j++)
		{
			cin >> x[i][j] >> t[i][j];
		}
	}
	while (q--)
	{
		int st, ed;
		cin >> st >> ed;
		if (n == 1)
		{
			cout << w[st] + w[ed] + t[1][st] + t[1][ed] << '\n';
		}
		else
		{
			cout << w[st] + w[ed] + t[1][st] + t[1][ed] << '\n';
		}
	}
	return 0;
}

