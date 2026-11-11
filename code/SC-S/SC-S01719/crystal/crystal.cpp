#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5+65;
ll n,m;
ll a[N];
ll c[N];
ll f[N];//f[i]表示从1~i都变为a[i]所花的代价； 
bool check(ll x)
{
	for(int i = x; i <= n;i++)
	{
		ll dj = f[i]-f[i-x+1]-(i-x)*(a[i]-a[i-x+1]);
		if(dj <= m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n ; i++)	
	{
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i = 1; i <= n ; i++) 
	{
		c[i] = a[i]-a[i-1];
	}
	f[1] = 0;
	for(int i = 2; i <= n ;i++) 
	{
		f[i] = f[i-1]+(i-1)*c[i];
	}
	ll l = 1,r = n;
	ll ans = 1;
	while(l <= r)
	{
		ll mid = (l+r) >> 1;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<ans;
	return 0;
} 