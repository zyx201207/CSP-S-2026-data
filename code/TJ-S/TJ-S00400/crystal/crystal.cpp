#include <bits/stdc++.h>
using namespace std;

long long n, m;

long long a[500005], b[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	if (n == 1 || m == 0)
	{
		printf("1");
		return 0;
	}
	bool chk = true;
	long long ans = 1, k, cnt;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		long long res = (a[i] - a[i - 1]);
		if (res < 0) res *= -1;
		b[i] = b[i - 1] + res;
		if (i >= 3 && b[i] - b[i - 1] != b[i - 1] - b[i - 2]) chk = false;
		
	}
	if (chk)
	{
		int x = 1;
		while (true)
		{
			if (ans == n) break;
			if (k >= x * 1ll * (b[2] - b[1])) ans++, k -= x * 1ll * (b[2] - b[1]);
			else break;
		}
		printf("%lld", ans);
		return 0;
	}
	for (int i = 1, j, jj; i <= n; i++)
	{
		k = m, j = i, jj = i, cnt = 1;
		while (k >= 0 && j - 1 > 0)
		{
			if (k >= b[i] - b[j - 1]) cnt++, k -= b[i] - b[j - 1], j--;
			else break;
		}
		if (cnt > ans) ans = cnt;
	}
	printf("%d", ans);
	return 0;
}
