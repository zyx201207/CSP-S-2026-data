#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010], sum[500010];
int n, m;
inline bool check(int x)
{
	int ans = 1e18;
	for(int i = x;i <= n;i++)
	{
		ans = min(ans, a[i] * x - sum[i] + sum[i - x]);
//		if(x == 7)
//		{
//			cout << a[i] * x << ' ' << sum[i] << ' ' << sum[i - x] << 
//		}
	}
	return ans <= m;
}
signed main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 0, r = n + 1, ans = 1;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
//			if(mid == 7)
//			{
//				cout << 
//			}
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}