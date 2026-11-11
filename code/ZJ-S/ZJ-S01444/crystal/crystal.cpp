#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5e5 + 5;

long long read();

bool judge(long long  k);

long long  a[MAXN];

long long n, m;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read();
	for(long long  i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	long long  L = 1, R = n + 1, ans = 1;
	while(L <= R)
	{
		long long  mid = (L + R) >> 1;
		if(judge(mid))
		{
			ans = mid;
			L = mid + 1;
		}
		else
		{
			R = mid - 1;
		}
	}
	printf("%lld", ans);
	return 0;
}

long long  read()
{
	long long  f = 1;
	char op = getchar();
	while(op > '9' || op < '0')
	{
		if(op == '-')
		{
			f = -1;
		}
		op = getchar();
	}
	long long  ans = 0;
	while(op >= '0' && op <= '9')
	{
		ans = (ans << 3) + (ans << 1) + op - '0';
		op = getchar();
	}
	return f * ans;
}

bool judge(long long  k)
{
	long long  cost = 0;
	for(long long  i = 1; i < k; i++)
	{
		cost += i * (a[i + 1] - a[i]);
	}
	if(cost <= m)
	{
		return true;
	}
	for(long long  i = k + 1; i <= n; i++)
	{
		cost = cost - (a[i - 1] - a[i - k]) + (k - 1) * (a[i] - a[i - 1]);
		if(cost <= m)
		{
			return true;
		}
	}
	return false;
}
