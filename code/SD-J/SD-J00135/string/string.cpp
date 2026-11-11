#include <bits/stdc++.h>
using namespace std;

constexpr long long N = 2e5 + 10;

static long long a[N];
static char c[N];

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef DEBUG
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif // DEBUG
#ifdef DEBUG
//	freopen("string4.in", "r", stdin);
//	freopen("string.out", "w", stdout);
#endif // DEBUG
	long long n, len = 0;
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		len += a[i];
	}
	long long p = 0, q = len;
	long long cur1 = 1, cur2 = n;
	long long ans = 0;
	while(p < q)
	{
		if(a[cur1] < a[cur2])
		{
			p += a[cur1];
			q -= a[cur1];
			if(c[cur1] != c[cur2])
				ans += a[cur1];
			a[cur2] -= a[cur1];
			cur1++;
		}
		else if(a[cur1] == a[cur2])
		{
			p += a[cur1];
			q -= a[cur2];
			if(c[cur1] != c[cur2])
				ans += a[cur1];
			cur1++;
			cur2--;
		}
		else
		{
			p += a[cur2];
			q -= a[cur2];
			if(c[cur1] != c[cur2])
				ans += a[cur2];
			a[cur1] -= a[cur2];
			cur2--;
		}
	}
	cout << ans << '\n';

	return 0;
}

