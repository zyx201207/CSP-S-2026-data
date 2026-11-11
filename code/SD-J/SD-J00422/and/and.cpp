#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	long long a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	long long maxs[m];
	int sum = 0;
	while (sum < m)
	{
		long long maxa = 0;
		int maxaw;
		for (int i = 0; i < n; i++)
		{
			if (maxa < a[i])
			{
				maxa = a[i];
				maxaw = i;
			}
		}
		maxs[sum] = maxa;
		a[maxaw] = 0;
		sum++;
	}
	long long cnt = maxs[0];
	for (int i = 1; i < m; i++)
	{
		cnt = cnt & maxs[i];
	}
	printf("%lld", cnt);
	return 0;
} 
