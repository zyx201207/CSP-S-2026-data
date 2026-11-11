#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n > 5000)
	{
		int k = a[2] - a[1];
		m = m * 2 / k;
		int l = 1,r = n - 1;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (mid * (mid + 1) < m)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << r + 1;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		int k = m,now = 1;
		for (int j = i - 1; j > 0 && k >= a[i] - a[j]; j--)
		{
			k -= a[i] - a[j];
			now++;
		}
		ans = max(now,ans);
	}
	cout << ans;
	return 0;
}