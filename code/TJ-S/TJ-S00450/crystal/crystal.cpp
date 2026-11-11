#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[500005], n, m; 

inline bool check(int x)
{
	if(x == 0) return true;
	int minn = LLONG_MAX;
	for(int i = 1; i + x - 1 <= n; i++) minn = min(minn, (a[i + x - 1] - a[i + x - 2]) * x - (a[i + x - 1] - a[i - 1]));
	//cout << minn << '\n';
	return (minn <= m);
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	int l = 0, r = n, ans = 0;
	while(l <= r)
	{
		int mid = l + (r - l >> 1);
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << '\n';
	 
	return 0;
}

