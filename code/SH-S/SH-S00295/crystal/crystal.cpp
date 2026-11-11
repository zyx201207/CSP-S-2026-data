#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],ss[500010];
ll n,m,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		ss[i] = ss[i - 1] +a[i];
	for (int i = 1;i <= n;i++)
	{
		ll l = 1,r = i;
		while(l <= r)
		{
			ll mid = l + r >> 1;
			ll sum = a[i] * (i - mid + 1) - ss[i] + ss[mid - 1];
			if(sum <= m) r = mid - 1,ans = max(i - mid + 1,ans);
			else l = mid + 1;
		}
	}
	cout << ans;
	return 0;
 } 
