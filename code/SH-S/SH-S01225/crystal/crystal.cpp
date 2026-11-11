#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500010], s[500010];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		s[i] = a[i] + s[i-1];
	}
	int ans = 1;
	for (int i = n; i >= 2; i--)
	{
		int left = 0, right = i;
		while (left < right)
		{
			int mid = (right + left) / 2;
			if (s[i] - s[mid] + m < a[i] * (i-mid))//²»Âú×ã 
			{
				left = mid + 1; 
			}
			else
			{
				right = mid;
			}
		}
		ans = max(ans, i - left);
	}
	cout << ans << endl;
	return 0;
}
