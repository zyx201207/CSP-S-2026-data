#include<bits/stdc++.h>
using namespace std;
int n, s;
long long m, a[500005], ans, l, r;
bool check(long long x)
{
	long long s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < x)
			s += x - a[i];
		else break;
	}
	return s <= m;
}
long long solve(int x)
{
	long long s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <=x)
			s++;
		else break;
	}
	return s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	l = a[1], r = a[n];
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (check (mid))
			l = mid + 1, ans = solve(mid);
		else r = mid - 1;
	}
	cout << ans;
	
	return 0;
}