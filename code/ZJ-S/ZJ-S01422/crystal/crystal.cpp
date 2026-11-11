#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005], d[500005], sum[500005];
bool check(long long x)
{
	long long t = sum[x - 1];
	for (long long i = x; i <= n; i++)
	{
		if (t <= m && t >= 0) return 1;
		t -= a[i] - a[i - x + 1];
		t += x * d[i];
	}
	return (t <= m);
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		d[i - 1] = a[i] - a[i - 1];
	for (long long i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + d[i] * i;
	int l = 1, r = n + 1;
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) 
			l = mid;
		else r = mid;
	}
	printf("%d", l);
	return 0;
}
