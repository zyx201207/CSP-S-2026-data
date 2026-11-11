#include<bits/stdc++.h>
using namespace std;
const int N = 2005, M = 2e6 + 5;
long long T, n, d, cnt, a[M], nxt[N], stp[N][N], ans;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> T >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if (n > 500)
		{
			d /= a[2] - a[1];
			cout << (d <= 1?0:max(n - (d * 2 - 1), 0ll)) << "\n";
			continue;
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i;j <= n;j++)
			{
				if (a[j] - a[i] <= d)
				{
					nxt[i] = j;
				}
				else
				{
					break;
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				cnt = 0;
				for (int l = i;;l = nxt[l])
				{
					if (l >= j)
					{
						stp[i][j] = cnt;
						break;
					}
					if (nxt[l] == l)
					{
						stp[i][j] = -1;
						break;
					}
					cnt++;
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				cnt = 0;
				for (int k = 1, l = nxt[i];k < stp[i][j];k++, l = nxt[l])
				{
					for (int t = 1;t <= 2;t++)
					{
						if (stp[l][j] == stp[l - t][j])
						{
							cnt++;
						}
					}
				}
				if (cnt == 1)
				{
					ans++;
				}
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
