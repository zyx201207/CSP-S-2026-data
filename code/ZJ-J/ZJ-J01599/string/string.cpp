#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
char c[200005];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		c[i] = getchar();
		while (c[i] < 'a' || c[i] > 'z')
			c[i] = getchar();
	}
	long long ans = 0;
	int l = 1, r = n;
	while (l < r)
	{
		if (a[l] > a[r])
		{
			if (c[l] != c[r])
				ans += a[r];
			a[l] -= a[r];
			--r;
		}
		else if (a[l] == a[r])
		{
			if (c[l] != c[r])
				ans += a[l];
			++l, --r;
		}
		else
		{
			if (c[l] != c[r])
				ans += a[l];
			a[r] -= a[l];
			++l;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
