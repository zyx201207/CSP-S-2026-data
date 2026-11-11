#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 1, r = 0, ans = 0;
	ll diff = 0;
	while (r < n)
	{
		diff += 1ll * (r - l + 1) * (a[r + 1] - a[r]);
		r++;
		while (diff > m && l <= r)
			diff -= (a[r] - a[l]), l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
