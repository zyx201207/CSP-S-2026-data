#include <bits/stdc++.h>
#define Int long long
#define PII pair <int, int>
using namespace std;

const int N = 1e3 + 10;
const int M = 2e5 + 10;
const Int INF = 1e17 + 10;

Int a[M], dis[N][N];

void Reset()
{
	for (int i = 1; i <= N - 1; i++)
	for (int j = 1; j <= N - 1; j++) dis[i][j] = INF;
	for (int i = 1; i <= N - 1; i++) dis[i][i] = 0;
	return;
}

void solve()
{
	Reset();
	int n, m, d, Q; cin >> n >> m >> d >> Q;
	cout << Q << '\n';
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int _ = 1; _ <= n; _++)
	{
		int len; cin >> len;
		vector <PII> vec(len);
		for (int j = 0; j < len; j++) cin >> vec[j].first >> vec[j].second;
		for (PII ite1 : vec)
		for (PII ite2 : vec)
		{
			int u = ite1.first, v = ite2.first;
			Int w = ite1.second; w += ite2.second;
			dis[u][v] = dis[v][u] = min(dis[u][v], w);
		}
	}		
	for (int k = 1; k <= m; k++)
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= m; j++)
	{
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	while (Q--)
	{
		int u, v; cin >> u >> v;
		cout << a[u] + a[v] + dis[u][v] << '\n';
	}
	return;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, T = 1; cin >> c;
	while (T--) solve();
	return 0;
}
