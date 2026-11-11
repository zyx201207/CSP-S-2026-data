#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 5e5 + 10, M = 510, inf = 1e9;

typedef pair<int, int> PII;

int c, n, m, d, q;
int w[N];
bool st[N];
long long dis[N];
vector<int> t[M], vec[M], g[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i ++ )
	{
		cin >> w[i];
		g[i].reserve(d);
	}
		
	for (int i = 1; i <= n; i ++ )
	{
		int k;
		cin >> k;
		vec[i].reserve(k); t[i].reserve(k);
		while (k -- )
		{
			int x, y;
			cin >> x >> y;
			vec[i].push_back(x);
			t[i].push_back(y);
			g[x].push_back(i);
		}
	}
	
	while (q -- )
	{
		int s, t;
		cin >> s >> t;
		long long ans = w[s] + w[t];
		cout << ans << "\n";
	}
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
