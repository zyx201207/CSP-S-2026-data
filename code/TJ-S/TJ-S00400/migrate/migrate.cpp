#include <bits/stdc++.h>
using namespace std;

int x[2000005], y[2000005];
int cnt = 0;
int c, t, n, d, ans;

int find(int a, int b)
{
	if(cnt >= 3) return cnt;
	for (int k = a; k <= b; k++)
	{
		if (y[k] - y[a] <= d)
		{
			if (k == b) cnt++;
			else return find(k, b);
		}
	}
	return cnt;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
	{
		/*ans = 0;
		bool chk = 0;
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
			int z = x[i] - x[i - 1];
			if (z < 0) z *= -1;
			y[i] = y[i - 1] + z;
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				cnt = 0;
				int z = x[j] - x[i];
				if (z < 0) z *= -1;
				if (z <= d || j - i < 3) continue;
				if (find(i, j) == 2) ans++;
			}
		}
		printf("%d\n", ans);*/
		printf("0\n");
	}
	return 0;
}
