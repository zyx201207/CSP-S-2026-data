#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[500005];
int maxl[500005];
int costp[500005];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int j;
	int ans = 0;
	for (int i = n; i >= 1; i--)
	{
		if (i == n)
		{
			for (j = i; j >= 1; j--)
			{
				if (costp[i] + a[i] - a[j] <= m)
				{
					maxl[i]++;
					costp[i] += a[i] - a[j];
				}
				else break;
			}
		}
		else
		{
			costp[i] = costp[i + 1] - (a[i + 1] - a[i]) * (maxl[i + 1] - 1);
			maxl[i] = maxl[i + 1] - 1;
			for (j; j >= 1; j--)
			{
				if (costp[i] + a[i] - a[j] <= m)
				{
					maxl[i]++;
					costp[i] += a[i] - a[j];
				}
				else break;
			}
		}
		ans = max(maxl[i], ans);
//		cout << costp[i] << ' ' << maxl[i] << '\n';
	}
	cout << ans << '\n';
	return 0;
}
