#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[500005];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	int ans2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n, ans = i;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if ((a[mid] - a[mid - 1]) * (mid - i + 1) - (a[mid] - a[i - 1]) <= m) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans2 = max(ans2, ans - i + 1);
	}
	printf("%lld", ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}