#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long n, a[N], s1[N], s2[N], ans;
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %c\n", a + i, c + i);
		s1[i] = s1[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--)
	{
		s2[i] = s2[i + 1] + a[i];
	}
	long long i1 = 1, i2 = n, now = 0;
	long long mid = s1[n] / 2;
	while (now < mid)
	{
		if (c[i1] != c[i2])
		{
			ans += min(a[i1], a[i2]);
		}
		now += min(a[i1], a[i2]);
		if (now > s1[i1])
		{
			i1++;
		}
		if (now > s2[i2])
		{
			i2--;
		}
		//printf("now:%lld i1:%lld i2:%lld ans:%lld\n", now, i1, i2, ans);
	}
	printf("%lld", ans);
	return 0;
}