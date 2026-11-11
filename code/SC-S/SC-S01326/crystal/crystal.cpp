#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500005], m;
signed n;

bool check(int x)
{
	int sum = 0;
	for(signed i = 1;i <= n;i++)
	{
		sum += (x > a[i] ? x - a[i] : 0);
		if(sum > m)
		{
			return 0;
		}
	}
	if(sum <= m)
		return 1;
	return 0;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int l = 1e18, r = -1e18, mid, ans;
	scanf("%lld %lld", &n, &m);
	for(signed i = 1;i <= n;i++)
	{
		scanf("%lld", &a[i]);
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	l--, r++;
	
	while(l <= r)
	{
		mid = (l + r) / 2LL;
		if(check(mid))
		{
			l = mid + 1LL;
			ans = mid;
		}
		else
			r = mid - 1LL;
	}
	
	int cnt = 0LL;
	for(signed i = 1;i <= n;i++)
		if(ans >= a[i])
			cnt++;
	
	printf("%lld", cnt);
	return 0; 
}