#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum[200010],a[200010],pos,ans;
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1;i <= n;i++) cin >> a[i] >> c[i],sum[i] = sum[i - 1] + a[i];
	for(ll i = 1;i <= n;i++)
		if(sum[i] >= sum[n] / 2 + 1)
		{
			pos = i;
			break;
		}
	ll lst = sum[n] / 2 + 1;
	ll mid = sum[n] / 2 + 1;
	for(ll i = pos;i <= n;i++)
	{
		ll l = mid - (sum[i] - mid) - !(sum[n] % 2);
		ll r = mid - (lst - mid) - !(sum[n] % 2);
		ll pos1 = lower_bound(sum + 1,sum + n + 1,l) - sum;
		ll pos2 = lower_bound(sum + 1,sum + n + 1,r) - sum;
//		cout << sum[i] << " " << lst << " " << l << ":" << pos1 << "        " << r << ":" << pos2 << endl;
		if(pos1 == pos2)
		{
			if(c[pos1] != c[i]) ans += r - l + 1;
		}
		else
		{
			if(c[pos1] != c[i]) ans += sum[pos1] - l + 1;
			for(ll j = pos1 + 1;j < pos2;j++) if(c[j] != c[i]) ans += a[j];
			if(c[pos2] != c[i]) ans += r - sum[pos2 - 1];
		}
		lst = sum[i] + 1;
	}
	cout << ans;
	return 0;
}
/*
1 2 3 4 5 6 7 8
*/
