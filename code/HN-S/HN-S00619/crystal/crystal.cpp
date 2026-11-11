#include <bits/stdc++.h>
#define filetestin
#define filetestout
using i64 = long long;
using ui64 = unsigned long long;
const int N = 5e5 + 5;
int T = 1, n;
i64 m, a[N], s[N];
i64 sum (int l, int r)
	{return s[r] - s[l - 1];}
bool check (int l, int r)
	{return 1ll * (r - l + 1) * a[r] - sum (l, r) <= m;}
void prework ()
{
}
void solve ()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		std::cin >> a[i];
	std::sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
	{
		int l = 1, r = i;
		while (l < r)
		{
			int mid = ((l + r) >> 1);
			if (check (mid, i))
				r = mid;
			else
				l = mid + 1;
		}
		ans = std::max (ans, i - l + 1);
	}
	std::cout << ans << '\n';
}
void clear ()
{
}
signed main ()
{
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
#ifdef filetestin
	freopen ("crystal.in", "r", stdin);
#endif
#ifdef filetestout
	freopen ("crystal.out", "w", stdout);
#endif
#ifdef PREWORK
	prework ();
#endif
#ifdef tests
	std::cin >> T;
#endif
	while (T --)
		solve (),
		clear ();
	return 0;
}