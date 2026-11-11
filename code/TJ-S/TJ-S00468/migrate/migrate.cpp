#include <bits/stdc++.h>
using namespace std;
long long ans[1000][10000], x[1000000], a;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int c, t;
	cin >> c >> t;
	if (1)
	{
		while(t --)
		{
			a = 0;
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i ++)
			{
				cin >> x[i];
			}
			long long a = 0;
			for (int i = 1; i <= n; i ++)
			{
				for (long long j = 1; j <= n; j ++)
				{
					ans[i][j] = 0;
				}
			}
			for (int i = 1; i <= n; i ++)
			{
				for (long long j = i; j <= n; j ++)
				{
					if (x[j] - x[i] <= d)
					{
						ans[i][j] ++;
					}
				}
			}
			for (int i = 1; i <= n; i ++)
			{
				for (long long j = 1; j <= n; j ++)
				{
					if (ans[i][j] > 1)
					{
						a ++;
					}
				}
			}
			cout << a << '\n';
		}
	}
	return 0;
} 
