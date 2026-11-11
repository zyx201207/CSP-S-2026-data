#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 5e5 + 10;
int a[N];
int sum[N];
int cnt;
int ans = 1;
int GetSum(int l, int r)
{
	return sum[r] - sum[l - 1];
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		cnt += i * (a[i] - a[i - 1]);
		if (cnt <= m)
		{
			ans = max(ans, i);
		}
		else
		{
			int l = 1, r = i-1, mid;
			while (l < r)
			{
				mid = (l + r) >> 1;
				if ((i - mid + 1) * a[i] - GetSum(mid, i) > m)
				{
					l = mid + 1;
				}
				else
				{
					r = mid;
				}
			}
			if ((i - mid + 1) * a[i] - GetSum(mid, i) > m)
			{
				continue;
			}
			ans = max(ans, i - mid + 1);
		}
	}
	cout << ans << endl;
}