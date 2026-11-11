#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long n, m, a[N], p[N], s[N], ans, tot, i, j;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
	{
		p[i] = a[i] - a[i - 1];
		s[i] = s[i - 1] + p[i];
	}
	i = 2, j = 2; //[i, j)
	for (int k = 2; k <= n; k++)
	{
		tot += p[j++] * (j - i);
		while (tot > m)
		{
			tot -= s[j - 1] - s[i - 1]; 
			i++;
		}
		ans = max(ans, j - i);
	}
	printf("%lld", ans + 1);
	return 0;
}

