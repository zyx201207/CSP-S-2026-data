#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[500005], s[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	int l = n;
	for (int j = n - 1; j >= 1; --j)
	{
		s[j] = s[j + 1] + a[n] - a[j];
		while (l > j && s[j] - (a[n] - a[l]) * 1ll * (l - j + 1) > m)
		{
			l--;
		}
		ans = max(ans, l - j + 1);
	}
	cout << ans << endl;
	return 0;
}
