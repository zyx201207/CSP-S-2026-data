#include <bits/stdc++.h>
using namespace std;
unsigned long long m;
int n, a[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = n; i >= 1; i--)
	{
		unsigned long long sum = 0;
		int mx = 0;
		for (int j = i; j >= 1; j--)
		{
			sum += a[i] - a[j];
			if (sum <= m)
				mx++;
		}
		ans = max(ans, mx);
		if (mx == i || mx == i - 1)
		{
			cout << ans;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
