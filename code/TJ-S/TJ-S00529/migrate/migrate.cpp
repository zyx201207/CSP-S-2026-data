#include <iostream>
#include <cstdio>
using namespace std;
long long a[2000005];
int n;
long long d, cnt[305], minn[305];
bool check1()
{
	long long x = a[2] - a[1];
	for (int i = 2; i < n; ++i)
	{
		if (a[i + 1] - a[i] != x) return 0;
	}
	return 1;
}
void dfs(int x, int time)
{
	//cout << x << " " << time << " " << minn[x] << " " << cnt[x] << endl;
	for (int i = x + 1; a[i] - a[x] <= d && i <= n; ++i)
	{
		if (time + 1 < minn[i])
		{
			minn[i] = time + 1;
			cnt[i] = 0;
		}
		if (time + 1 == minn[i]) ++cnt[i];
		if (time + 1 > minn[i]) continue;
		dfs(i, time + 1);
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		if (check1())
		{
			d = d / (a[2] - a[1]);
			cout << max(0ll, n - 2ll * d) << endl;
			continue; 
		}
		else
		{
			int ans = 0;
			for (int i = 1; i < n; ++i)
			{
				for (int j = i + 1; j <= n; ++j) cnt[j] = 0, minn[j] = n; 
				dfs(i, 0);
				for (int j = i + 1; j <= n; ++j)
				{
					//cout << cnt[j] << " ";
					if (cnt[j] == 2) 
					{
						++ans;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
