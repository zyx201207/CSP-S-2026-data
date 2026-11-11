#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n, m, a[N], cost[N], ans;
void solve()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1 ; i <= n ; i ++)
	{
		cost[i] = cost[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		if(cost[i] <= m) ans = i;
	}
	for(int i = 1 ; i < n ; i ++)
	{
		int l = i + 1, r = n;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(cost[mid] - (cost[i] + i * (a[mid] - a[i])) <= m)
			{
				ans = max(ans, mid - i);
				l = mid + 1;
			}
			else r = mid;
		}
	} 
	cout << ans;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
	while(T --) solve();
	return 0;
}

