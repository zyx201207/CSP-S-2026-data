#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
#define N 500007
using namespace std;
ll n, m, a[N], l, r, sum[N], ans;

ll solve(ll idx)
{
	ll l = 1, r = idx - 1, res = 0;
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		if ((idx - mid) * a[idx] - sum[idx - 1] + sum[mid - 1] <= m)
		{
			r = mid - 1;
			res = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return idx - res + 1;
}

int main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
//		cout << solve(i) << "\n";
		ans = max(ans, solve(i));
	}
	cout << ans;
	return 0;
} 
