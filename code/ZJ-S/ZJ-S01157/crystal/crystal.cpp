#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	ll sum = 0,ans = -1;
	for(ll l = 1,r = 1;r <= n;)
	{
		while(r <= n && sum <= m) r++,sum += (r - l) * (a[r] - a[r - 1])/*,cout << l << " " << r << endl*/;
		ans = max(ans,r - l);
//		cout << sum << endl;
		while(l < r && sum > m) l++,sum -= a[r] - a[l - 1]/*,cout << l << " " << r << endl*/;
		ans = max(ans,r - l + 1);
//		cout << l << " " << r << endl;
	}
	cout << ans;
	return 0;
}
