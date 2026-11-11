#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main()
{
	long long n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i > 0; i--)
	{
		long long k = m, x = 1, c = 0;
		while (k >= 0 && i - x >= 1)
		{
			if (k >= (a[i] - a[i - x]))
			{
				k = k - (a[i] - a[i - x]);
			}
			else
				break;
//			cout << k << "\n";
			x++;
			c++;
		}
		ans = max(ans, c + 1);

	}
	cout << ans;
	return 0;
}