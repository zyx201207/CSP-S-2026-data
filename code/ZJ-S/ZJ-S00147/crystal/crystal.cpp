#include <bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, ans = 1;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 2; i <= n; i++)
	{
		int sum = 0;
		for (int j = i - 1; j > 0; j--)
		{
			//cout << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << '\n';
			sum += a[i] - a[j];
			if (sum > m)
			{
				ans = max(ans, i - j);
				break;
			}
		}
		if (sum <= m)
			ans = max(ans, i);
	}
	cout << ans;
}
