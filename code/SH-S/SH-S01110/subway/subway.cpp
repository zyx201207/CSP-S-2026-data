#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 2e4 + 5;
const long long INF = 1e16;

int c, n, m, d, q;
long long w[M];
int k[N];
vector<pair<int, int>> ak[M];
pair<int, long long> a[N][M];
long long dist[N][N];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j].first >> a[i][j].second;
			ak[a[i][j].first].push_back({i, j});
		}
		sort(a[i] + 1, a[i] + k[i] + 1);
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			long long w = INF;
			int aq = 1;
			for (int ap = 1; ap <= k[i]; ap++)
			{
				if (a[i][ap].first == a[j][aq].first)
				{
					w = min(w, a[i][ap].second + a[j][aq].second);
				}
				while (a[j][aq].first < a[i][ap].first && aq <= k[j]) aq++;
			}
			dist[i][j] = dist[j][i] = w;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int l = 1; l <= n; l++)
			{
				dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
			}
		}
	}
	
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		long long ans = INF;
		for (int i = 0; i < (int)ak[u].size(); i++)
		{
			for (int j = 0; j < (int)ak[v].size(); j++)
			{
				ans = min(ans, dist[ak[u][i].first][ak[v][j].first] + a[ak[u][i].first][ak[u][i].second].second + a[ak[v][j].first][ak[v][j].second].second);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}
	
	return 0;
}
