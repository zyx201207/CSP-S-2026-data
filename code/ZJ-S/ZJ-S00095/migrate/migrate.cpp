#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int c, t;
	int n;
	long long d;
	long long x[2000001];
	int ans = 0;
	int main()
	{
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> c >> t;
		for (int tt = 1; tt <= t; ++tt)
		{
			cin >> n >> d;
			for (int i = 1; i <= n; ++i)
				cin >> x[i];
			vector<vector<int>> v(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
			vector<vector<int>> f(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
			for (int i = 1; i <= n; ++i)
				for (int j = i + 1; j <= n; ++j)
					if (x[j] - x[i] <= d)
					{
						v[i][j] = 1;
						f[i][j] = 1;
					}
			for (int k = 1; k <= n; ++k)
				for (int i = 1; i < k; ++i)
					for (int j = k + 1; j <= n; ++j)
					{
						if (v[i][j] > v[i][k] + v[k][j])
						{
							v[i][j] = v[i][k] + v[k][j];
							f[i][j] = 1;
						}
						else if (v[i][j] == v[i][k] + v[k][j])
						{
							if (f[i][j] < 3 && f[i][k] == 1 && f[k][j] == 1)
								++f[i][j];
							if (f[i][j] < 3 && f[i][k] == 2 && f[k][j] == 1)
								++ ++f[i][j];
							if (f[i][j] < 3 && f[i][k] == 1 && f[k][j] == 2)
								++ ++f[i][j];
						}
					}
			ans = 0;
			for (int i = 1; i <= n; ++i)
				for (int j = i + 1; j <= n; ++j)
					if (f[i][j] == 2)
						++ans;
			// for (int i = 1; i <= n; ++i)
			// 	for (int j = i + 1; j <= n; ++j)
			// 		cout << i << ", " << j << ": " << v[i][j] << ' ' << f[i][j] << '\n';
			cout << ans << '\n';
		}
		return 0;
	}
}
int main()
{
	return Main::main();
}
