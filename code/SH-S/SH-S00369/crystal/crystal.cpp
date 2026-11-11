#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

long long n, m, a[N], sum[N];

bool check(int x)
{
	for (int i = x; i <= n; i ++ )
	{
		if ((x - 1) * a[i] - sum[i - 1] + sum[i - x] <= m) return true;
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	long long l = 1, r = n;
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++ )
	{
		sum[i] = sum[i - 1] + a[i];
	}
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%lld\n", l);
	return 0;
}
