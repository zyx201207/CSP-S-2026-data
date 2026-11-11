#include <bits/stdc++.h>
using namespace std;

int c, t, n;
long long d, x[2000005];

bool f[2000005];
int minn, cnt;

void dfs(int u, int v, int len)
{
	if(u == v)
	{
		if(len < minn)
		{
			minn = len;
			cnt = 1;
		}
		else if(len == minn)
		{
			cnt ++;
		}
		return;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(f[i] == false && abs(x[i] - x[u]) <= d)
		{
			f[i] = true;
			dfs(i, v, len + 1);
			f[i] = false;
		}
	}
	return;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	for(int dt = 1; dt <= t; dt ++)
	{
		scanf("%d%d", &n, &d);
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &x[i]);
		}
		int ans = 0;
		for(int i = 1; i <= n - 1; i ++)
		{
			for(int j = i + 1; j <= n; j ++)
			{
				minn = 10;
				cnt = 0;
				f[i] = true;
				dfs(i, j, 0);
				f[i] = false;
				if(cnt == 2)
				{
					ans ++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
