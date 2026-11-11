#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long c, t, n, d, x[N], ans;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
	{
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int cnt = 0;
			for (int k = 1; k <= n; k++)
			{
				if (abs(x[i] - x[k]) <= d && abs(x[j] - x[k]) <= d)
				{
					cnt++;
				}
			}
			if (cnt == 2)
			{
				ans++;
			}
		}
	}
	printf("%lld", ans); 
	return 0;
}

