#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N];

signed main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	
	int l = 1, cur = 0, ans = 0;
	for (int r = 1; r <= n; r ++)
	{
		while (l <= r && cur > m)
		{
			cur -= (a[r] - a[l]);
			l ++;
		}
		ans = max (ans, r - l + 1);
		cur += (r - l + 1) * (a[r + 1] - a[r]);
	}
	cout << ans << "\n";
	return 0;
}
/*
合并区间显然连续
使用双指针
[l, r] -> [l, r + 1]
lst_cost = sigma (a[r] - a[i]) (i <= r)
now_cost = sigma (a[r + 1] - a[i]) (i <= r)
now_cost = lst_cost + (a[r + 1] - a[r]) * (r - l + 1)

[l, r] -> [l + 1, r]
now_cost = lst_cost - (a[r] - a[l])
*/
/*
5 8
-3 -1 2 2 7
*/
