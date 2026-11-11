#include <bits/stdc++.h>
using namespace std;
int n, maxx = 1, L = 0;
long long m, ta, tb;
long long a[500000];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	ta = 0;
	for(int i = 1; i < n; i++)
	{
		if(n - L < maxx)
			break;
		tb = ta + (a[i] - a[i - 1]) * (i - L);
		bool have = 0;
		while(tb > m)
		{
			if(L >= n)
			{
				have = 1;
				break;
			}
			tb -= (a[i]	- a[L]);
			ta -= (a[i - 1] - a[L]);
			L++;
		}
		if(have == 1)
			break;
		maxx = max(i - L + 1, maxx);
		ta = tb;
	}
	printf("%d\n", maxx);
	return 0;
}
