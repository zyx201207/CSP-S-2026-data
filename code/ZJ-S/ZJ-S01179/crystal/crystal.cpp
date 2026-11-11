#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int sum = 0, ans = 1;
	for(int r = 1, l = 1; r <= n; r++)
	{
		sum += (r-l) * (a[r] - a[r-1]);
		while(l <= r && sum > m)
		{
			sum -= a[r]-a[l];
			l++;
		}
		ans = max(r-l+1, ans);
	}
	cout << ans;
	return 0;
}
// 14:45
