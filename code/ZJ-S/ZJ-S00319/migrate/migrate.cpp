#include <bits/stdc++.h>
using namespace std;
int c, t, n, d1[5005], d2[5005], d3[5005];
long long d, x[2000005];
pair<int, int> q[5005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		scanf("%d%lld", &n, &d), x[n + 1] = 5e18;
		for(int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		long long cnt = 0;
		if(n == 1) puts("0");
		else if(c <= 10)
		{
			for(int i = 1; i <= n; i++)
			{
				memset(d1, 0, sizeof d1);
				memset(d2, 0, sizeof d2);
				memset(d3, 63, sizeof d3);
				int p = 0;
				queue<pair<int, int>> q;
				q.push({0, i});
				while(!q.empty())
				{
					int y = q.front().first, u = q.front().second;
					q.pop();
					for(int j = max(u, p) + 1; x[j] - x[u] <= d; j++)
						if(!d1[j]) d1[j] = y + 1, q.push({d1[j], j});
						else if(!d2[j]) d2[j] = y + 1, q.push({d2[j], j});
						else d3[j] = y + 1, p = j, q.push({d3[j], j});
				}
				for(int j = i + 1; j <= n; j++)
					if(d1[j] && d1[j] == d2[j] && d2[j] < d3[j]) cnt++;
			}
			cout << cnt << '\n';
		}
		else if(c <= 12)
		{
			int y = d / (x[2] - x[1]) * 2 - 1;
			if(y > 1 && y < n) cout << n - y << '\n';
			else puts("0");
		}
	}
	return 0;
}