#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 0, a[201000];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (m == 1)
	{
		for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	else if (m == n)
	{
		ans = a[1];
		for (int i = 2; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	else if (m == 2)
	{
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	else if (m == n - 1)
	{
		long long num;
		for (int i = 1; i <= n; i++)
		{
			if (i == 1) num = a[2];
			else num = a[1];
			for (int j = 1; j <= n; j++) 
			{
				if (i == j) continue;
				num &= a[j];
			}
			ans = max(ans, num);
		}
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}