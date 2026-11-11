//SN-S00477 于柏骁 西安辅轮中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+5;
ll n,m;
ll a[maxn];
ll sum[maxn];
ll ans;
ll d;
bool f = 1;
void solve()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i ++)
	{
		if(i == 2) d = a[i] - a[i-1];
		if(a[i] - a[i-1] != d && i > 2) f = 0;
		sum[i] = a[i] + sum[i-1];
	}
	if(f)
	{
		for(ll i = 0;i < n;i ++)
		{
			ll ssum = (0+d*i) * (i+1) / 2;
			if(ssum <= m) ans = max(ans,i+1);
		}
		cout << ans << endl;
		return;
	}
	for(ll i = 1;i <= n;i ++)
	{
		for(ll j = i;j >= 1;j --)
		{
			ll x = (i-j+1) * a[i] - (sum[i] - sum[j-1]);
			if(x <= m) ans = max(ans,i-j+1);
		}
	}
	cout << ans << endl;
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
//	cin >> T;
	while(T--) solve();
	return 0;
}
