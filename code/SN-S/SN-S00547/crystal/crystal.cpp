#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 5e5 + 10;
ll n, m, a[N], sum[N], ans;
bool check(ll x)
{
	bool flag = false;
	for(ll i = 1; i <= n; i ++)
	{
		if(i + x - 1 > n) break;
		ll j = i + x - 1;
		ll now = (a[j] * x) - (sum[j] - sum[i - 1]);
		if(now <= m) flag = true;
	}
	return flag;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i ++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	ll l = 1, r = n;
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
