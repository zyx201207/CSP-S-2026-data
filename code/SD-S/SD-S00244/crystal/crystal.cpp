#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
const ll MOD = 998244353;
const ll inf = 9e18;
ll n,m;
ll a[N];
bool check(ll mid){
	ll need = 0;
	for(ll i = 1;i < mid;i++)
	{
		need += a[mid] - a[i];
	}
	if(need <= m) return true;
	ll sum = 0;
	for(ll i = mid + 1;i <= n;i++)
	{
		sum = (a[i] - a[i - 1]) * mid + need - (a[i] - a[i - mid]);
		need = sum;
		if(need <= m) return true;
	}
	return need <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	
	ll l = 1,r = n,ans = 1;
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout<<ans;
	return 0;
}
