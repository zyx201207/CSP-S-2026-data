#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m;
int a[N];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 1, sum = 0;
	for (int i = 2, j = 1; i <= n; i++)
	{
		sum += (a[i] - a[i - 1]) * (i - j);
		while (j < i && sum > m) sum -= (a[i] - a[j]), j++;
		ans = max(ans, i - j + 1);
	}
	printf("%lld\n", ans);
	return 0;
}

/*
finished at 14:43
*/