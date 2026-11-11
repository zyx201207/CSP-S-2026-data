#include <bits/stdc++.h>
using namespace std;

#define int long long

int read()
{
	int x = 0;
	bool f = true;
	char c = getchar();
	while (c < '0' || c > '9')
		f = (c != '-'), c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

int n, m;
int a[500005];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
	}
		
	sort(a + 1, a + n + 1);
	int r = 1;
	int mx = 1;
	int sum = 0;
	for (int l = 1; l <= n; )
	{
		while (r < n && sum + (r - l + 1) * (a[r + 1] - a[r]) <= m)
		{
			sum += (r - l + 1) * (a[r + 1] - a[r]);
			++r;
		}
		mx = max(mx, r - l + 1);
		sum -= a[r] - a[l];
		++l;
	}
	printf("%lld\n", mx);
	return 0;
}