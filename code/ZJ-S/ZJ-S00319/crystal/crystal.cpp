#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], s[500005];
bool chk(int x)
{
	long long mn = 5e18;
	for(int i = x; i <= n; i++)
		mn = min(mn, a[i] * x - s[i] + s[i - x]);
	return mn <= m;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int l = 1, r = n, mid, ans;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(chk(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}