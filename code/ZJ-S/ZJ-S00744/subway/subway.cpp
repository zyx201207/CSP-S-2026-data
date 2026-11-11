#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
int c, n, m, d, q; 
const int N = 510, M = 5e5 + 100;
int w[M];
vector <pair <int, int> > x[M];
int f[N][N];
signed main()
{
	memset(f, 0x3f, sizeof f);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			x[a].push_back(make_pair(i, t));
		}
	}
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int i = 1; i <= m; i++)
	{
		sort(x[i].begin(), x[i].end());
		for(auto it1 = x[i].begin(); it1 < x[i].end(); it1++)
		{
			for(auto it2 = it1; it2 < x[i].end(); it2++)
			{
				if(it1 == it2) continue;
				auto j = *it1, k = *it2;
				f[j.first][k.first] = min(f[j.first][k.first], j.second + k.second);
	//			printf("i=%lld,f[%lld][%lld]min=%lld\n", i, j.first, k.first, j.second + k.second);
			}
		}
	}
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				f[i][j] = min(f[min(i, k)][max(i, k)] + f[min(j, k)][max(j, k)], f[i][j]);
			}
		}
	}
	for(int i = 1; i <= q; i++)
	{
		int u, v;
		cin >> u >> v;
		int ans = f[0][0];
		for(auto s : x[u])
		{
			for(auto t : x[v])
			{
				int ss = min(s.first, t.first);
				int tt = max(s.first, t.first);
				ans = min(ans, f[ss][tt] + s.second + t.second);
		//		printf("When ss=%lld,tt=%lld, the ans=%lld+%lld+%lld\n", ss, tt, f[ss][tt], s.second, t.second);
			}
		}
		cout << (ans + w[u] + w[v]) << "\n";
	}
}
/*
fc subway.out subway7.ans
*/
